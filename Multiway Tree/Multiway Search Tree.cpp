#include <iostream>
#include <vector>
#include<algorithm>
#include<exception>
#include <limits> 
using namespace std;

class duplicateInsertion : public std::exception {
public:
    explicit duplicateInsertion(const std::string& message) : msg_(message) {}
    const char* what() const noexcept override {
        return msg_.c_str();
    }
private:
    std::string msg_;
};

class NotFoundException : public std::exception {
public:
    explicit NotFoundException(const std::string& message) : msg_(message) {}
    const char* what() const noexcept override {
        return msg_.c_str();
    }
private:
    std::string msg_;
};

template <typename DT>
class MTree {
protected:
    int M;                          //Max number of children per node (M+1 way split)
    vector<DT> values;              //Values stored in the node (M-1 values)
    vector<MTree*> children;        //Pointers to child nodes (M+1 children)

public:
    MTree(int M);
    ~MTree();
    bool is_leaf() const;           //Check if current node is a leaf
    void insert(const DT& value);   //Insert a value into MTree
    void split_node();              //Split the node when it exceeds capacity
    MTree* find_child(const DT& value); //Find correct child to follow
    bool search(const DT& value);   //Search for a value in MTree
    void remove(const DT& value);   //Delete a value from MTree
    void buildTree(vector<DT>& input_values); //Build Tree
    vector<DT> collect_values();     //Collect values from all leaf nodes
    bool find(const DT& value);

};

template <typename DT>
MTree<DT>::MTree(int M) : M(M) {}

template <typename DT>
bool MTree<DT>::is_leaf() const
{
    return children.empty();
}


template <typename DT>
MTree<DT>* MTree<DT>::find_child(const DT& value)
{
    //If leaf node, then return
    if (is_leaf())
    {
        return this;
    }

    //Find the appropriate leaf node by checking value with vector values
    for (size_t i = 0; i < values.size(); i++)
    {
        if (value <= values[i])
        {
            return children[i]->find_child(value);
        }
    }

    return children.back()->find_child(value);
}

template <typename DT>
bool MTree<DT>::search(const DT& value)
{
    //Find the leaf node where the value could be
    MTree* leafNode = find_child(value);

    //Only check values in the leaf node
    return std::find(leafNode->values.begin(), leafNode->values.end(), value) != leafNode->values.end();
}

template <typename DT>
bool MTree<DT>::find(const DT& value)
{
    return search(value);
}


template <typename DT>
void MTree<DT>::insert(const DT& value)
{
    //Use find_child to locate the correct leaf node for insertion
    MTree<DT>* target_node = find_child(value);

    //If this is the correct leaf node, insert value in sorted order and return
    if (target_node->is_leaf())
    {
        //Check if the value already exists in the leaf node
        if (std::find(target_node->values.begin(), target_node->values.end(), value) != target_node->values.end())
        {
            throw duplicateInsertion("Duplicate value: value already exists in the tree.");
            return;
        }

        //Insert value in sorted order within the leaf node's values
        target_node->values.insert(std::upper_bound(target_node->values.begin(), target_node->values.end(), value), value);
        cout << "The value = " << value << " has been inserted." << endl; //Output statement for successful insertion

        //If node overflows, split it
        if (target_node->values.size() >= M)
        {
            target_node->split_node();
        }
    }
}

template <typename DT>
void MTree<DT>::split_node() 
{
    if (values.size() <= M - 1) return;  //Only split if the number of values exceeds M-1

    //Calculate the number of elements per partition
    int totalValues = values.size();
    int partitionSize = totalValues / M;
    int remainder = totalValues % M;

    vector<MTree*> newChildren;
    vector<DT> newValues;
    int startIndex = 0;

    for (int i = 0; i < M; i++) {
        int endIndex = startIndex + partitionSize + (i < remainder ? 1 : 0) - 1;
        MTree<DT>* child = new MTree<DT>(M);

        //Copy values to the new child node
        for (int j = startIndex; j <= endIndex; ++j) {
            child->values.push_back(values[j]);
        }

        newChildren.push_back(child);

        if (i < M - 1 && endIndex + 1 < totalValues) {
            newValues.push_back(values[endIndex + 1]);
        }

        startIndex = endIndex + 2;
    }

    //Update this node to be an internal node
    values = newValues;
    children = newChildren;
}



template <typename DT>
vector<DT> MTree<DT>::collect_values()
{
    vector<DT> allValues;

    if (is_leaf())
    {
        //If this is a leaf node, add its values directly to the result vector
        allValues = values;
    }
    else
    {
        //Only iterate over child nodes if this is not a leaf

        for (auto child : children)
        {
            //Recursively collect values from each child
            vector<DT> childValues = child->collect_values();

            allValues.insert(allValues.end(), childValues.begin(), childValues.end());
        }
    }
    return allValues;
}


template <typename DT>
void MTree<DT>::remove(const DT& value)
{
    //Navigate to the appropriate leaf node using find_child
    MTree* leafNode = find_child(value);

    //Try to find the value in the leaf node's values
    auto it = std::find(leafNode->values.begin(), leafNode->values.end(), value);

    if (it != leafNode->values.end())
    {
        //Value found in the leaf node, so remove it
        leafNode->values.erase(it);
        cout << "The value = " << value << " has been removed." << endl;
    }
    else
    {
        //Value not found in the leaf node, throw an exception
        throw NotFoundException("Value not found in the tree.");
    }
}


template <typename DT>
void MTree<DT>::buildTree(std::vector<DT>& input_values)
{
    for (auto child : children)
    {
        delete child;
    }
    values.clear();

    children.clear();

    //Base case: if the input values are small enough, set them as this node's values
    if (input_values.size() <= M - 1)
    {
        values = input_values;
        return;
    }

    //Calculate the number of elements each child node will handle
    int D = input_values.size() / M;

    for (int i = 0; i < M; i++)
    {
        int start = D * i;
        int end;

        //Determine end based on whether it's the last partition
        if (i == M - 1) {
            end = input_values.size() - 1;  //Last partition takes remaining elements
        }
        else
        {
            end = start + D - 1;
            //For non-last partitions, add the last element of the partition to this node's values
            values.push_back(input_values[end]);
        }

        //Define child values for the current partition
        vector<DT> child_values(input_values.begin() + start, input_values.begin() + end + 1);

        //Create and build the child node
        MTree<DT>* child = new MTree<DT>(M);
        child->buildTree(child_values);
        children.push_back(child);
    }
}

template <typename DT>
MTree<DT>::~MTree()
{
    for (auto child : children)
    {
        delete child;  //Calls destructor on each child
    }

    //After deleting children, clear the vectors
    children.clear();
    values.clear();
}


int main()
{
    int n;
    int MValue;
    int numCommands;
    char command;
    int value;

    vector<int> mySortedValues;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;                       //Read each value
        mySortedValues.push_back(value);    //Add it to the vector
    }

    //read n numbers from the input and add them to the vector

    cin >> MValue;
    MTree<int>* myTree = new MTree<int>(MValue);

    (*myTree).buildTree(mySortedValues);

    cin >> numCommands; //read the number of commands


    for (int i = 0; i < numCommands; i++)
    {
        cin >> command;

        switch (command)
        {
        case 'I': { //insert
            cin >> value;

            try {
                (*myTree).insert(value);
            }

            catch (duplicateInsertion& e) {
                cout << "The value = " << value << " already in the tree.";
                cout << endl;
            }
        }
                break;

        case 'R': { //remove
            cin >> value;

            try {
                (*myTree).remove(value);
            }

            catch (NotFoundException& e) {
                cout << "The value = " << value << " is not found.";
                cout << endl;
            }
        }
                break;

        case 'F': { //insert
            cin >> value;
            if ((*myTree).find(value))
            {
                cout << "The element with value = " << value << " was found." << endl;
            }

            else
            {
                cout << "The element with value = " << value << " was not found." << endl;
            }
        }
                break;

        case 'B': { //rebuild tree

            vector<int> myValues = ((*myTree).collect_values());
            cout << "The tree has been rebuilt." << endl;
            (*myTree).buildTree(myValues);
        }
                break;

        default:
            cout << "Invalid command!" << endl;
            cin.clear();                 //Clear the error flag on cin
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    cout << "Final List: ";
    std::vector<int> finalValues = myTree->collect_values();
    for (int i = 0; i < finalValues.size(); i++)
    {
        cout << finalValues[i] << " ";
    }
    cout << endl;


    cout << "Program complete..." << std::endl;
    while (cin.get() != '\n');


    delete myTree;
    return 0;
}


