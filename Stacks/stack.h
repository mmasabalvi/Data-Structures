#include<iostream>
using namespace std;

template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;

    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
};


template <typename T>
class Stack
{
public:
    Node<T>* top;

    Stack()
    {
        top = nullptr;
    }


    void push(T data)
    {
        Node<T>* tempNode = new Node<T>(data);
        tempNode->next = top;
        top = tempNode;

    }

    void pop()
    {
        if (!isEmpty())
        {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }


    T peek()
    {
        if (!isEmpty())
        {
            return top->data;
        }
    }


    void clear()
    {
        Node<T>* temp = top;
        while (temp != nullptr)
        {
            temp = temp->next;
            pop();
        }
    }

    bool isEmpty()
    {
        if (top == nullptr)
        {
            return 1;
        }
        
        return 0;
    }

};
