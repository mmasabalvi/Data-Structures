//If element is in array more than once, first traverse it using the program provided, and then delete it

#include<iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size of the Array: " << endl;
    cin >> size;

    int* arr = new int[size];

    cout << "Input the Array: " << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Array: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    int x;
    cout << "\nEnter the element to delete: " << endl;
    cin >> x;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            for (int j = i; j < size-1; j++)
            {
                arr[j] = arr[j + 1];
            }

        }
    }

    size--;

    cout << "Array: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

 
}