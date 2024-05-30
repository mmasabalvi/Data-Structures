/*Program a simulation of these actions (undo, redo and backspace). For your
program ‘u|U’ key will be used for undo, ‘r|R’ will be used for redo and ‘b|B’ will be used for
backspace.

Sample Output:
1. User types “Cpls”
2. User types “U”
- Cpl
3. User types “U”
- Cp
4. User types “R” 2 times
- Cpls
5. User presses “left arrow key” and types “B”
- Cps
6. User types “R”
- Cpls   
*/

//arrow keys implementation not complete

#include<iostream>
#include<conio.h>
using namespace std;

class Node
{
public:
	char data;
	Node* next = nullptr;
	Node* prev = nullptr;

	Node(char data)
	{
		this->data = data;
        next = prev = nullptr;
	}
};


class Stack 
{
private:
    char sentence[100];
    int top = -1;

public:
    Stack() 
    {}

    bool isEmpty() 
    {
        return (top == -1);
    }

    void push(char element) 
    {
        if (top < 99) 
        {
            top++;
            sentence[top] = element;
        }

        else
        {
            return;
        }
    }

    char pop() 
    {
        if (!isEmpty())
        {
            char element = sentence[top];
            top--;
            return element;
        }

        else
        {
            return '\0';
        }
    }

    char peek() 
    {
        if (!isEmpty())
        {
            return sentence[top];
        }

        else 
        {
            return '\0';
        }
    }
};


class TextEditor
{
private:
    Node* head;
    Node* cursor;

    Stack redo;

public:

    TextEditor()
    {
        head = nullptr;
        cursor = nullptr;
    }

    void insert(char text)
    {
        Node* newNode = new Node(text);

        if (head == nullptr)
        {
            head = newNode;
            cursor = newNode;    
        }

        else
        {
            newNode->prev = cursor;

            //if (cursor->next != nullptr)
            //{
            //    cursor->next->prev = newNode;  //when adding characters in middle
            //}

            newNode->next = cursor->next;
            cursor->next = newNode;
            cursor = newNode;
            
        }
    }

    void undoOperation()
    {
        if (cursor != nullptr || cursor == head)
        {
            backOperation();
        }
    }

    void redoOperation()
    {
        if (redo.isEmpty())
        {
            return;
        }

        else
        {
            insert(redo.pop());
        }

    }

    void backOperation()
    {
        if (cursor == nullptr || cursor == head)
        {
            return;
        }

        else
        {
            Node* node = cursor;
            //cursor = cursor->prev;

            if (cursor->next != nullptr)
            {
                node->next->prev = cursor->prev;
            }

            if (cursor->prev != nullptr)
            {
                cursor->prev->next = cursor->next;
                cursor = cursor->prev;
            }

            else
            {
                cursor = cursor->next;
                head = cursor;
            }
            
            redo.push(node->data);
            delete node;           
        }
    }


    void cursorLeft() 
    {
        if (cursor != nullptr && cursor->prev != nullptr) 
        {
            cursor = cursor->prev;
        }
    }

    void cursorRight()
    {
        if (cursor != nullptr && cursor->next != nullptr) 
        {
            cursor = cursor->next;
        }
    }

    void display()
    {
        cout << "Line is: ";
        Node* current = head;

        while (current != nullptr)
        {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    TextEditor obj;

    string line;
    cout << "Input a string: " << endl;
    cin >> line;

    int i = 0;
    while (line[i] != '\0')
    {
        obj.insert(line[i]);
        i++;
        //cout << i << " ";
    }

    cout << endl;
    obj.display();

   
    char input;
    while (true) 
    {
        input = _getch();

        switch (input) 
        {
            case 27:
                {
                    return 0;
                }
            
            case 'u':
                obj.undoOperation();
                break;

            case 'U':
                obj.undoOperation();
                break;

            case 'r':
                obj.redoOperation();
                break;

            case 'R':
                obj.redoOperation();
                break;

            case 'b':
                obj.backOperation();
                break;

            case 'B':
                obj.backOperation();
                break;
            
            default:
                obj.insert(input);
                break;
        }

        obj.display();
    }

    return 0;
}
