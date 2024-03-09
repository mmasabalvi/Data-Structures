#include<iostream>
using namespace std;
#include<string>

class Employee
{
public:
	string empID;
	string CNIC;
	string joiningDate;
	int salary;
	int bonus;

	Employee()
	{
		empID = "";
		CNIC = "";
		joiningDate = "";
		salary = 0;
		bonus = 0;
	}

	Employee(string emp, string cnic, string jd, int sal, int bon)
	{
		empID = emp;
		CNIC = cnic;
		joiningDate = jd;
		salary = sal;
		bonus = bon;		
	}

};

class Node
{
public:
	Employee employeeData;
	int data;
	Node* prev;
	Node* next;

	Node(int val, const Employee& emp)
	{
		data = val;
		employeeData = emp;
		prev = nullptr;
		next = nullptr;
	}

};

class DoublyLinkedList
{
private:
	Node* head = nullptr;

public:

	bool insert(int val, Employee data)
	{
		Node* newNode = new Node(val, data);

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

	int search(string empID)
	{
		Node* temp = head;
        int index = 0;
		
		while (head != nullptr)
		{
			if (empID == temp->employeeData.empID)
			{
				return index;
			}

			temp = temp->next;
			index++;
		}

		return -1;
	}

	bool remove(string empID)
	{
		int index = search(empID);

		if (index == -1) 
		{
			return false; 
		}

		Node* temp = head;
		int pos = 0;

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

	bool updateSalary(string empID, int sal)
	{
		int index = search(empID);

		if (index == -1)
		{
			return false;
		}

		Node* temp = head;
		int pos = 0;

		while (temp != nullptr && pos < index)
		{
			temp = temp->next;
			pos++;
		}

		temp->employeeData.salary = sal;

	}

	int getemployeesalary(string empID)
	{
		int index = search(empID);

		if (index == -1)
		{
			return false;
		}

		Node* temp = head;
		int pos = 0;

		while (temp != nullptr && pos < index)
		{
			temp = temp->next;
			pos++;
		}

		return temp->employeeData.salary;
	}

	Employee maximumSalary()
	{
		if (head == nullptr) 
		{
			return Employee();
		}

		int maxSalary = head->employeeData.salary;
		Node* maxNode = head;

		Node* temp = head->next;

		while (temp != nullptr)
		{
			cout << temp->employeeData.salary << endl;
			cout << maxSalary << endl;

			if (temp->employeeData.salary >= maxSalary)
			{
				maxSalary = temp->employeeData.salary;
				maxNode = temp;
			}

			temp = temp->next;
		}

		return maxNode->employeeData;
	}

};
