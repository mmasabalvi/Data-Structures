#include <iostream>
using namespace std;

template <typename T>
class binaryTreeNode
{
public:
    T data;
    binaryTreeNode<T>* llink;
    binaryTreeNode<T>* rlink;

    binaryTreeNode() : data(T()), llink(nullptr), rlink(nullptr)
    {}

    binaryTreeNode(T item)
    {
        data = item;
        llink = rlink = nullptr;
    }
};

template <typename T>
class bSearchTreeType
{
private:
    binaryTreeNode<T>* root;

public:
    bSearchTreeType() : root(nullptr)
    {}

    T getRoot()
    {
        return root->data;
    }

    void insert(T insertItem)
    {
        binaryTreeNode<T>* newNode = new binaryTreeNode<T>;
        newNode->data = insertItem;
        newNode->llink = newNode->rlink = NULL;

        if (root == NULL)
        {
            root = newNode;
        }

        else
        {
            binaryTreeNode<T>* temp = root;

            while (temp != NULL)
            {
                if (insertItem < temp->data)
                {
                    if (temp->llink)
                    {
                        temp = temp->llink;
                    }
                    else
                    {
                        temp->llink = newNode;
                        break;
                    }
                }

                else if (insertItem > temp->data)
                {
                    if (temp->rlink)
                    {
                        temp = temp->rlink;
                    }
                    else
                    {
                        temp->rlink = newNode;
                        break;
                    }
                }
            }
        }
    }

    bool search(const T& key)
    {
        binaryTreeNode<T>* current = root;
        while (current != nullptr)
        {
            if (key == current->data)
            {
                return true;
            }
            else if (key < current->data)
            {
                current = current->llink;
            }
            else
            {
                current = current->rlink;
            }
        }
        return false;
    }


    void inorderTraversal()
    {
        inorderTraversal(root);
    }

    void preorderTraversal()
    {
        preorderTraversal(root);
    }

    void postorderTraversal()
    {
        postorderTraversal(root);
    }


    void inorderTraversal(binaryTreeNode<T>* root)
    {
        if (root == nullptr)
        {
            return;
        }

        inorderTraversal(root->llink);
        cout << root->data << " ";
        inorderTraversal(root->rlink);
    }

    void preorderTraversal(binaryTreeNode<T>* root)
    {
        if (root == nullptr)
        {
            return;
        }

        cout << root->data << " ";
        preorderTraversal(root->llink);
        preorderTraversal(root->rlink);
    }

    void postorderTraversal(binaryTreeNode<T>* root)
    {
        if (root == nullptr)
        {
            return;
        }

        postorderTraversal(root->llink);
        postorderTraversal(root->rlink);
        cout << root->data << " ";
    }


    void deleteNode(T deleteItem) 
    {
        deleteNodehelper(root, deleteItem);
    }


    void deleteNodehelper(binaryTreeNode<T>*& root1, T deleteItem)
    {
        if (root1 == nullptr)
        {
            cout << "Element not present" << endl;
        }

        if (deleteItem > root1->data)
        {
            deleteNodehelper(root1->rlink, deleteItem);
        }

        else if (deleteItem < root1->data)
        {
            deleteNodehelper(root1->llink, deleteItem); 
        }

        else
        {
            binaryTreeNode<T>* temp;
            // One child or no child cases
            if (root1->llink == NULL)
            {
                temp = root1;
                root1 = root1->rlink;
                delete temp;
            }

            else if (root1->rlink == nullptr)
            {
                temp = root1;
                root1 = root1->llink;
                delete temp;
            }

            else
            {
                // Two child case
                binaryTreeNode<T>* p;
                binaryTreeNode<T>* q;

                p = root1->rlink;
                q = NULL;  

                while (p->llink != NULL)
                {
                    q = p;
                    p = p->llink;
                }
                root1->data = p->data;

                if (q == NULL)
                {
                    root1->rlink = p->rlink;
                }

                else
                {
                    q->llink = p->rlink;
                }

                delete p;
            }
        }
    }

};
