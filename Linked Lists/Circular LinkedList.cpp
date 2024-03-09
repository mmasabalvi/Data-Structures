class Node2
{
private:
	int data;
	Node2* next;

public:
	Node2()
	{
		data = 0;
		next = nullptr;
	}

	Node2(int d)
	{
		data = d;
		//next = ptr;
	}

	void setData(int d)
	{
		data = d;
	}

	void setNext(Node2* ptr)
	{
		next = ptr;
	}

	int getData()
	{
		return data;
	}

	Node2* getNext()
	{
		return next;
	}
};

class CircularLinkedList
{
	Node2* head;

public:

	Node2* getHead()
	{
		return head;
	}

	CircularLinkedList()
	{
		head = nullptr;
	}

	bool insert(int val) 
	{
		Node2* newNode = new Node2(val);

		if (head == nullptr) 
		{
			head = newNode;
			head->setNext(head); 
			return true;
		}

		else 
		{
			Node2* temp = head;

			while (temp->getNext() != head)
			{
				temp = temp->getNext();
			}

			temp->setNext(newNode); 
			newNode->setNext(head); 

			return true;
		}
	}

	bool isEmpty()
	{
		if (head == nullptr)
		{
			return 1;
		}

		return 0;
	}

	bool insertAtIndex(int data, int index)
	{
		if (index < 0)
		{
			return false;
		}

		Node2* newNode = new Node2(data);

		if (index == 0)
		{
			newNode->setNext(head);
			head = newNode;
			
			return true;
		}

		int currIndex = 0;
		Node2* temp = head;

		while (temp && index > currIndex + 1)
		{
			temp = temp->getNext();
			currIndex++;
		}

		if (index > 0 && temp == nullptr)
		{
			return false;
		}

		newNode->setNext(temp->getNext());
		temp->setNext(newNode);

		return true;
	}


	bool search(int data)
	{
		Node2* temp = head;

		while (temp && temp->getData() != data)
		{
			temp = temp->getNext();

			if (temp == head)
			{
				break;
			}
				
		}

		if (temp && temp->getData() == data)
		{
			return 1;
		}
		
		else
		{
			return 0;
		}
	}

	bool update(int former, int data)
	{
		Node2* temp = head;

		while (temp && temp->getData() != former)
		{
			temp = temp->getNext();

			if (temp == head)
			{
				break;
			}
				
		}

		if (temp && temp->getData() == former)
		{
			temp->setData(data);

			return true;
		}
		else
		{
			return false; 
		}
	}

	bool deleteData(int data)
	{
		Node2* temp = head;
		Node2* prev = nullptr;

		
		while (temp && temp->getData() != data)
		{
			prev = temp;
			temp = temp->getNext();


			if (temp == head)
			{
				return false;
			}
		}

		
		if (temp == head)
		{
			
			if (temp->getNext() == head)
			{
				delete temp;
				head = nullptr;
				return true;
			}

		}
		
		else
		{
			prev->setNext(temp->getNext());
			delete temp;
			return true;
		}
		
	}

	bool hasCycle(Node2* head) 
	{
		if (head == nullptr)
		{
			return false;
		}

		Node2* ahead = head;
		Node2* back = head;

		while (ahead != nullptr && ahead->getNext() != nullptr) 
		{
			ahead = ahead->getNext()->getNext();
			back = back->getNext();
			
			if (back == ahead)
			{
				return true;
			}
		}
		return false;
	}


};
