#include<iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;


class Node
{
public:
	int data;
	Node* prev;
	Node* next;

	Node(int val)
	{
		data = val;
		prev = nullptr;
		next = nullptr;
	}

};

class DoublyLinkedList
{
private:
	Node* head = nullptr;

public:

	bool insert(int val)
	{
		Node* newNode = new Node(val);

		if (head == nullptr)
		{
			head = newNode;
			return true;
		}

		else
		{
			Node* temp = head;

			while (temp->next != nullptr)
			{
				temp = temp->next;
			}

			temp->next = newNode;

			newNode->prev = temp;
			newNode->next = nullptr;

			return true;
		}

	}


	bool isEmpty()
	{
		if (head == nullptr)
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	int search(int data)
	{
		Node* temp = head;
		int index = 0;

		while (head != nullptr)
		{
			if (data == temp->data)
			{
				return index;
			}

			temp = temp->next;
			index++;
		}

		return -1;
	}

	bool remove(int data)
	{
		int index = search(data);

		if (index == -1)
		{
			return false;
		}

		Node* temp = head;

		if (index == 0)
		{
			head = temp->next;

			if (head != nullptr)
			{
				head->prev = nullptr;
			}

			delete temp;
			return true;
		}

		int pos = 0;
		while (temp != nullptr && pos < index - 1)
		{
			temp = temp->next;
			pos++;
		}

		Node* check = temp->next;
		temp->next = check->next;

		if (check->next != nullptr)
		{
			check->next->prev = temp;
		}

		delete check;
		return true;
	}

	void check()
	{
		Node* fast = head;
		Node* slow = head;

		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
			{
				cout << "Doubly Linked List has a Cycle" << endl;
				return;
			}
		}

		cout << "Doubly Linked List does not have a Cycle" << endl;
	}

	void create()
	{
		if (isEmpty())
		{ 
			return;
		}
			
		Node* temp = head;
		int count = 1;

		while (temp->next != nullptr)
		{
			temp = temp->next;
			count++;
		}

		Node* random = head;

		int x = rand() % count;

		for (int i = 0; i < x; i++)
		{
			random = random->next;
		}

		temp->next = random;
	}

	void display()
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;	
		}
	}
};

int main()
{
	srand(time(0));

	DoublyLinkedList obj1;

	cout << "Doubly Linked List object made: obj1" << endl;

	int num;
	cout << "Enter number of nodes: " << endl;
	cin >> num;

	cout << "Random values entered on " << num << " nodes" << endl;

	for (int i = 0; i <= num; i++)
	{
		int data = rand() % 100 + 1;
		obj1.insert(data);
	}

	cout << "Values: " << endl;
	obj1.display();
	cout << endl;

	cout << "Cycle created from last node to a random node" << endl;
	obj1.create();

	cout << "Check function called: " << endl;
	obj1.check();
}
