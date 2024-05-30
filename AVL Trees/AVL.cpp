#include<iostream>
using namespace std;


struct AVLNode
{
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int val) : data(val), left(NULL), right(NULL), height(1) {}
};


class AVLTree
{
public:
    AVLNode* root;

    AVLTree() : root(NULL)
    {

    }

    int getHeight(AVLNode* p)
    {
        if (p == NULL)
        {
            return 0;
        }
        return p->height;
    }

    int getBalanceFactor(AVLNode* node)
    {
        if (node == nullptr)
            return 0;

        int balancefactor = getHeight(node->left) - getHeight(node->right);
        return balancefactor;
    }

    void insert(int value)
    {

        root = inserttemporary(root, value);
    }


    AVLNode* inserttemporary(AVLNode* node, int value)
    {
        if (node == nullptr)  //first node
            return new AVLNode(value);


        if (value > node->data)
            node->right = inserttemporary(node->right, value);
        else if (value < node->data)
            node->left = inserttemporary(node->left, value);
        else
            return node; // Duplicate values 

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int gettingbalance = getBalanceFactor(node);

        // Left-Left Case(LL)
        if (gettingbalance > 1 && value < node->left->data)
            return rightRotate(node);


        // Right-Right Case (RR)
        if (gettingbalance < -1 && value > node->right->data)
            return leftRotate(node);


        // Right-Left Case (RL)
        if (gettingbalance < -1 && value < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Left-Right Case (LR)
        if (gettingbalance > 1 && value > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        return node;
    }

    AVLNode* rightRotate(AVLNode* y)
    {

        AVLNode* x = y->left;
        AVLNode* z = x->right;

        y->left = z; //x->right comes here

        x->right = y; //

        /*

               y                                     x
              / \                                   / \
            x   t3    Right rotation at y          t1  y
           / \                                        / \
          t1  z                                      z   t3


        */

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }

    AVLNode* leftRotate(AVLNode* x)
    {
        AVLNode* y = x->right;
        AVLNode* z = y->left;

        x->right = z;

        y->left = x;


        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    void inorder(AVLNode* node)
    {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }


    void preorder(AVLNode* node)
    {
        if (node != NULL)
        {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);

        }

    }

    void postorder(AVLNode* node)
    {
        if (node != NULL)
        {
            cout << node->data << " ";
            postorder(node->left);
            postorder(node->right);

        }

    }


    int smallestValueNode(AVLNode* p)
    {
        while (p->left != NULL)
        {
            p = p->left;
        }
        return p->data;
    }

    int largestValueNode(AVLNode* p)
    {
        while (p->right != NULL)
        {
            p = p->right;
        }
        return p->data;
    }

    void remove(int data)
    {
        root = deletefunction(root, data);
    }


    AVLNode* deletefunction(AVLNode* root, int data)
    {
        if (root == NULL)
            return root;

        if (data > root->data)
            root->right = deletefunction(root->right, data);

        else if (data < root->data)
            root->left = deletefunction(root->left, data);

        else
        {
            //bst deletion here
            if (root->left == NULL || root->right == NULL)
            {
                AVLNode* temp;

                if (root->left)
                    temp = root->left;
                else
                    temp = root->right;

                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }

                else
                    *root = *temp;

                delete temp;
            }

            //    else
            //    {
            //        AVLNode* temp = smallestValueNode(root->right); // finding smallest value node

            //        root->data = temp->data;

            //        root->right = deletefunction(root->right, temp->data); //deleting that n=value after replacing
            //    }
            //}

            if (root == NULL)
            {
                return root;

            }

            root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

            int balance = getBalanceFactor(root);

            // Left-Left (LL)
            if (balance > 1 && getBalanceFactor(root->left) >= 0) // if 
            {
                return rightRotate(root);
            }

            // Left-Right (L-R)
            if (balance > 1 && getBalanceFactor(root->left) < 0)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

            // RR Case
            if (balance < -1 && getBalanceFactor(root->right) <= 0)
                return leftRotate(root);


            // RL Case
            if (balance < -1 && getBalanceFactor(root->right) > 0)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root;
        }
    }

        AVLNode* getRoot()
        {
            return root;
        }

        int getDiameter()
        {
            int diameter = getDiamertertemp(root);
            return diameter;
        }

        int getDiamertertemp(AVLNode * node)
        {
            if (node == NULL)
            {
                return 0;
            }

            int leftHeight = getHeight(node->left);
            int rightHeight = getHeight(node->right);

            // Calculate the diameter recursively for left and right subtrees
            int leftsubtree = getDiamertertemp(node->left);// +leftHeight;
            int rightsubtree = getDiamertertemp(node->right);// +rightHeight;

            return leftHeight + rightHeight;
        }
   


};


int main()
{
    AVLTree tree;

    tree.insert(20);
    tree.insert(30);
    tree.insert(10);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Inorder: ";
    tree.inorder(tree.root);

    cout << endl;

    cout << "Pre-order: ";
    tree.preorder(tree.root);

    cout << endl;

    cout << "Post-order: ";
    tree.postorder(tree.root);

    cout << endl;

    cout << "Smallest Value: " << tree.smallestValueNode(tree.root) << endl;

    cout << "Largest Value: " << tree.largestValueNode(tree.root) << endl;

    cout << "Diameter:" << tree.getDiameter();

    //cout << tree.smallestValueNode();

}
