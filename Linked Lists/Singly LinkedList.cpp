#include<iostream>
using namespace std;
#include<string>

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
class  SLinkedList
{
public:
	Node<T>* head = nullptr;

	bool insert(T data)
	{
		Node<T>* temp = head;
		Node<T>* temp1 = nullptr;

		Node<T>* ptr = new Node<T>(data);

		if (temp == nullptr)
		{
			head = ptr;
			return 0;
		}

		while (temp != nullptr)
		{
			temp1 = temp;
			temp = temp->next;
		}

		temp1->next = ptr;
		ptr->next = nullptr;

		return 1;
	}




	bool insertAtHead(T data)
	{
		if (head == nullptr)
		{
			return 0;
		}

		Node<T>* ptr = new Node<T>(data);

		ptr->next = head;
		head = ptr;

		return 1;

	}

	bool InsertAtIndex(T data, int index)
	{
		if (index < 0)
		{
			return 0;
		}

		int currIndex = 0;

		Node<T>* temp = head;

		while (temp && index > currIndex)
		{
			temp = temp->next;
			currIndex++;
		}

		if (index > 0 && temp == nullptr)
		{
			return 0;
		}

		Node<T>* newNode = new Node<T>(data);
		

		if (index == 0) 
		{
			newNode->next = head;
			head = newNode;
		}

		else 
		{
			newNode->next = temp->next;
			temp->next = newNode;
		}

		return 1;

	}

	bool update(int index, T data)
	{
		if (index < 0)
		{
			return 0;
		}

		int currIndex = 0;

		Node<T>* temp = head;

		while (temp && index > currIndex)
		{
			temp = temp->next;
			currIndex++;
		}

		if (index > 0 && temp == nullptr)
		{
			return 0;
		}

		temp->data = data;

		return 1;
	}

	int search(T data)
	{
		Node<T>* temp = head;

		int currIndex = 0;

		while (temp && temp->data != data) 
		{
			temp = temp->next;
			currIndex++;
		}

		if (temp)
		{
			return currIndex;
		}

		else
		{
			return -1;
		}
	}

	bool remove(T data)
	{
		int index = search(data);

		if (index == -1)
		{
			return false;
		}

		if (index == 0) 
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			return true;
		}

		int currIndex = 0;

		Node<T>* prev = nullptr;

		Node<T>* curr = head;

		while (curr && currIndex < index) 
		{
			prev = curr;
			curr = curr->next;
			currIndex++;
		}

		if (curr != nullptr) 
		{ 
			prev->next = curr->next;
			delete curr;
			return true;
		}

		return false; 
	}

	void print()
	{
		Node<T>* temp = head;

		while (temp->next != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl;
	}




};
