#include<iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


class AVLNode
{
public:
    Font font;
    int posX = 0;

    int key;

    AVLNode* left = nullptr;
    AVLNode* right = nullptr;
    int height;

    AVLNode(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

class Inventory
{
private:
    AVLNode* root;
    int NodeCount = 0;
    
public:

    Inventory() : root(NULL) {}

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


    void insert(int key)
    {
        if (root == nullptr)
        {
            //root = new AVLNode(key);
            
        }
        else
        {
            root->posX += 20;
        }

        //cout << root->posX << " pos" << endl;

        NodeCount++;
        root = insert(root, key);
    }


    AVLNode* insert(AVLNode* node, int key)
    {
        if (node == nullptr)  //first node
        {
            return new AVLNode(key);
        }

        //
        if (key > node->key)
        {
            node->right = insert(node->right, key);
        }

        else if (key < node->key)
        {
            node->left = insert(node->left, key);
        }

        else
        {
            node->right = insert(node->right, key); 
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        return balance(node);
     
    }

    AVLNode* balance(AVLNode* node)
    {
        int balanceFactor = getBalanceFactor(node);

        
        if (balanceFactor > 1)
        {
            
            if (getBalanceFactor(node->left) >= 0)
                return rightRotate(node);
            
            else
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        
        else if (balanceFactor < -1)
        {
            
            if (getBalanceFactor(node->right) <= 0)
                return leftRotate(node);
            
            else
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        return node;
    }


    AVLNode* rightRotate(AVLNode* y)
    {

        AVLNode* x = y->left;
        AVLNode* z = x->right;

        y->left = z; 

        x->right = y; 

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



    AVLNode* smallestValueNode(AVLNode* p)
    {
        while (p->left != NULL)
        {
            p = p->left;
        }
        return p;
    }


    void remove(int data)
    {
        root = remove(root, data);
    }

    AVLNode* remove(AVLNode* root, int key)
    {
        if (root == NULL)
        {
            return root;
        }


        if (key > root->key)
        {
            root->right = remove(root->right, key);
        }

        else if (key < root->key)
        {
            root->left = remove(root->left, key);
        }

        else
        {
            
            if (root->left == NULL || root->right == NULL)
            {
                AVLNode* temp;

                if (root->left)
                {
                    temp = root->left;
                }
                    
                else
                {
                    temp = root->right;
                }

                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }

                else
                {
                    *root = *temp;
                }
                   
                delete temp;
            }

            else
            {
                AVLNode* temp = smallestValueNode(root->right); // finding smallest value node

                root->key = temp->key;

                root->right = remove(root->right, temp->key); //deleting that n=value after replacing
            }
        }

        if (root == NULL)
        {

            return root;  //basically if not found

        }

        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;


        return balance(root);
    }

    void checckfor(int key)
    {
        int count = 0;
    }


    void emptyTree()
    {
        root = emptyTree(root);
        NodeCount = 0; 
    }
    
    AVLNode* emptyTree(AVLNode* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        node->left = emptyTree(node->left);
        node->right = emptyTree(node->right);

       
        delete node;

        return nullptr; 
    }

    void display(RenderWindow& window)
    {
        string scoreString = "Inventory: ";

        Font font;
        font.loadFromFile("LilitaOne-Regular.ttf");
        Text scText(scoreString, font, 32);
        scText.setPosition(10, 120);
        scText.setFillColor(Color(18, 134, 191));

        window.draw(scText);

        int startX = 170;
        inorderTraversal(root, window, startX, 25);
    }

    void inorderTraversal(AVLNode* root, RenderWindow& window, int& posX, int gap)
    {
        if (root == nullptr)
        {
            return;
        }

        inorderTraversal(root->left, window, posX, gap);

        int key = root->key;
        Texture powerUp;
        Sprite powerSp;

        switch (key)
        {
        case 100:
            powerUp.loadFromFile("images/platform.png");
            powerSp.setTexture(powerUp);
            powerSp.setScale(2, 2);
            powerSp.setPosition(posX, 125); 
            window.draw(powerSp);
            posX += gap; 
            break;

        case 50:
            powerUp.loadFromFile("images/sword.png");
            powerSp.setTexture(powerUp);
            powerSp.setScale(2, 2);
            powerSp.setPosition(posX, 125);
            window.draw(powerSp);
            posX += gap;
            break;
            

        case 25:
            powerUp.loadFromFile("images/potion1.png");
            powerSp.setTexture(powerUp);
            powerSp.setScale(2, 2.05);
            powerSp.setPosition(posX, 125); 
            window.draw(powerSp);
            posX += gap; 
            break;

        case 0:
            powerUp.loadFromFile("images/key.png");
            powerSp.setTexture(powerUp);
            powerSp.setScale(1.8, 1.8);
            powerSp.setPosition(posX, 125);
            window.draw(powerSp);
            posX += gap;
            break;

        
        }

        inorderTraversal(root->right, window, posX, gap);
    }


};

//int AVLNode::posX = 0;
 