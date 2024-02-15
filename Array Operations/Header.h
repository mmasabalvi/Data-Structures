#include<iostream>
#include<string>
using namespace std;


struct StudentRecord
{
	int StudentID;
	string name;
	float GPA;
};



void insertionSortStudents(struct StudentRecord students[], int size)
{
	int i;
	int j;

	for (i = 1; i < size; i++)
	{
		StudentRecord obj = students[i];

		for (j = i; j > 0 && obj.GPA < students[j - 1].GPA; j--)
		{
			students[j] = students[j - 1];
		}

		students[j] = obj;
	}
}
