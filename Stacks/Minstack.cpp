#include<iostream>
using namespace std;


class StackNode
{
public:
    int value;
    StackNode* next;

    StackNode(int data)
    {
        this->value = data;
        next = nullptr;
    }
};


class MinStack
{
public:
    StackNode* top;

    MinStack()
    {
        top = nullptr;
    }

    void push(int data)
    {
        StackNode* tempNode = new StackNode(data);
        tempNode->next = top;
        top = tempNode;
    }

    void pop()
    {
        if (!isEmpty())
        {
            StackNode* temp = top;
            top = top->next;
            delete temp;
        }

        else
        {
            cout << "Stack is empty" << endl;
        }
    }


    int peek()
    {
        if (!isEmpty())
        {
            int topValue = top->value;
            return topValue;
        }

        else
        {
            cout << "Stack is empty" << endl;
        }
    }

    bool isEmpty()
    {
        if (top != nullptr)
        {
            return 0;
        }

        else
        {
            return 1;
        }
        
    }

    int getMin()
    {
        StackNode* temp = top;
        StackNode* minNode = top;

        while (temp != nullptr)
        {
            if (minNode->value > temp->value)
            {
                minNode = temp;
            }

            temp = temp->next;
        }

        return minNode->value;
    }

};

int main()
{
  MinStack stack;

	stack.push(10);
	stack.push(13);
	stack.push(1);
	stack.push(52);
	stack.push(3);

	cout << "\nMin Value with 5 values in Stack: " << stack.getMin() << endl;

	stack.pop();
	stack.pop();
	stack.pop();

	cout << "Min Value with 2 values in Stack: " << stack.getMin() << endl;

	cout << endl << "------------------" << endl;
}
