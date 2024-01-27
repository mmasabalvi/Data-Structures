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

    cout << "Array Traversed: " << endl;

    for (int i = 0; i < size; i++)
    {
        int count = 0;

        for (int j = 0; j <= i; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        if (count <= 1)
        {
            cout << arr[i] << " ";
        }
    }
}