#include<string>
#include<iostream>
using namespace std;

class ListNode
{
public:
	char value;

	ListNode* next;

	ListNode(char value)
	{
		this->value = value;
		this->next = nullptr;
	}
};

class TextEditor
{
private:
	ListNode* head;
	ListNode* cursor;

public:
	TextEditor()
	{
		head = new ListNode('\0');
		cursor = head;
	}

	void addText(const string& text)
	{
		cout << "Entering AddText..." << endl;
		ListNode* temp = cursor;
		ListNode* temp2 = nullptr;

		int i = 0;

		while (text[i] != '\0')
		{
			temp->next = new ListNode(text[i]);
			i++;
			temp2 = temp;
			temp = temp->next;
			cout << "Adding text: " << temp->value << endl;
		}

		cursor = temp2->next;
		cout << "cursor points to: " << cursor->value << endl;
		cout << "Exiting AddText..." << endl << endl;
	}


	string cursorLeft(int k)
	{
		cout << "Entering cursorLeft..." << endl;
		ListNode* temp = head;
		int count = 0;

		while (temp->value != cursor->value && temp != nullptr)
		{
			count++;
			temp = temp->next;
			cout << "Temp Value (cursorLeft func): " <<  temp->value << endl;
		}

		cout << "count value: " << count << endl;
		int left = count - k;
		cout << "left value: " << left << endl;

		cursor = head->next;												//as dummy node
		cout << "cursor points to: " << cursor->value << endl;

		//all works till here

		int counter = 1;

		while (counter <= left)//&& cursor->next != nullptr)
		{
			cursor = cursor->next;
			cout << "cursor values: " << cursor->value << endl;
			counter++;
		}

		char *line = new char [k];
		//string line;
		int j = 0;

		ListNode* temp3 = cursor;

		//all correct till here

		while (cursor!=nullptr)
		{
			line[j] = cursor->value;
			cout << "Line is: " << line[j] << endl;
			cursor = cursor->next;
			j++;
		}
		line[j] = '\0';
		cursor = temp3;

		cout << "Line is: " << line << endl;
		return line;

		cout << "Exiting cursorLeft..." << endl << endl;
	}



	string cursorRight(int k)
	{
		cout << "Entering cursorRight..." << endl;

		int count = 1;
		char* line = new char[2];
		int i = 0;

		//cout << "check;;;;;;";

		cout << "cursor value: " << cursor->value << endl;

		while (count <= k)
		{
			line[i] = cursor->value;
			cout << "Line is: " << line[i] << endl;
			count++;
			cursor = cursor->next;
			i++;
		}
		line[i] = '\0';
		cout << "Exiting cursorRight..." << endl << endl;
		return line;

		

	}

	
};
