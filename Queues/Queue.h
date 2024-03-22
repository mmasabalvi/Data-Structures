#include<string>
using namespace std;


template<class T>
class Node
{
public:
	T data;
	Node<T>* next;

	Node()
	{
		data = 0;
		next = nullptr;
	}

	Node(T data)
	{
		this->data = data;
		next = nullptr;
	}
};


template<class T>
class  Queue
{
public:
	Node<T>* front;
	Node<T>* rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(T val)
    {
        Node<T>* temp = new Node<T>(val);

        if (front == NULL)
        {
            rear = temp;
            front = rear;
        }

        else
        {
            rear->next = temp;
            rear = temp;
        }
         
    }


    int dequeue() 
    {
        if (rear == NULL)
        {
            return -1;
        }

        else 
        {
            Node<T>* temp = front;
            int data = front->data;

            front = front->next;

            delete temp;
            return data;
        }
    }


    int peek()
    {
        return front->data;
    }

    bool is_empty()
    {
        if (front == NULL)
        {
            return 1;
        }
            
        return 0;
    }

    int size()
    {
        Node<T>* temp = front;
        int count = 0;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void clear()
    {
        Node<T>* x = front;

        while (front != NULL)
        {
            front = front->next;
            delete x;
            x = front;
        }
    }

};
