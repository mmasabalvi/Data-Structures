#include<iostream>
using namespace std;

class Node
{
public:
	int data;

	Node* next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}

};

class AdjList
{
public:
	Node* head;

	AdjList()
	{
		head = NULL;
	}

	void Insert(Node* NewNode)
	{
		if (head == NULL) 
		{
			head = NewNode;
		}

		else 
		{
			Node* temp = head;
			while (temp->next != NULL) temp = temp->next;
			temp->next = NewNode;
		}
	}

	void Display() 
	{

	}
};


class Graph
{
public:
	int maxVertices;
	int noOfVertices;

	AdjList* list = NULL;

	Graph(int maxVertices) 
	{
		list = new AdjList[maxVertices];

		this->maxVertices = maxVertices;

		for (int i = 0; i < maxVertices; i++) 
		{
			Node* temp = new Node(i + 1);
			list[i].Insert(temp);
		}
	}

	
	void insertEdge(int src, int dest)
	{
		Node* temp = new Node(dest);
		list[src - 1].Insert(temp);
	}

	void Graphdisplay() 
	{

		for (int i = 0; i < maxVertices; i++)
		{
			Node* temp = list[i].head;

			while (temp != NULL) 
			{
				cout << temp->data;
				if (temp->next != NULL) cout << "->";
				temp = temp->next;
			}

			cout << endl;
		}
	}



};
