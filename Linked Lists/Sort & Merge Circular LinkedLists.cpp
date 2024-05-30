//Given 2 Circular LinkedLists. Merge them into one, and sort in descending order such that MaxValue of List1 is followed by MaxValue of List2

#include<iostream>
using namespace std;


class Node
{
public:
    bool checked = 0;
    int data;
    Node* next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};



class CircularLinkedList
{
public:

    Node* head = nullptr;

    bool insert(int data)
    {
        Node* temp = head;
        Node* ptr = new Node(data);

        if (temp == nullptr)
        {
            head = ptr;
            head->next = head;
            return true;
        }

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = ptr;
        ptr->next = head;

        return true;
    }

  
    int findMax()
    {
        Node* maxNode = head;
        Node* temp = head->next;

        while (temp != head)
        {
            if (temp->data > maxNode->data && temp->checked == 0)
            {
                maxNode = temp;
            }

            temp = temp->next;
        }

        maxNode->checked = 1;
        int returnValue = maxNode->data;
        return returnValue;
    
    }

    void print()
    {
        Node* temp = head;
        int count = 0;

        if (head)
        {
            cout << temp->data << " ";
            temp = temp->next;

            while (temp != head)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }

            cout << endl;
        }  
    }



    void mergeLists(CircularLinkedList& list1, CircularLinkedList& list2)
    {
        CircularLinkedList newList;

        Node* temp = newList.head;

        Node* temp1 = list1.head->next;;
        Node* temp2 = list2.head->next;

        while (temp1 != list1.head || temp2 != list2.head)
        {
            newList.insert(list1.findMax());
            newList.insert(list2.findMax());

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        newList.insert(list1.findMax());
        newList.insert(list2.findMax());

        newList.print();

    }
};


int main()
{ 

	CircularLinkedList list1;
	list1.insert(12);
	list1.insert(28);
	list1.insert(18);
	list1.insert(25);
	list1.insert(19);

	CircularLinkedList list2;
	list2.insert(5);
	list2.insert(24);
	list2.insert(12);
	list2.insert(6);
	list2.insert(15);

	cout << "List-1: ";
	list1.print();
	cout << endl;

	cout << "List-2: ";
	list2.print();
	cout << endl;

	CircularLinkedList mergedList;
	
	cout << "Merged List: ";
	mergedList.mergeLists(list1, list2);		


	cout << endl << "------------------" << endl;
}
