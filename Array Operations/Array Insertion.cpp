#include<iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the number of elements you want to add: " << endl;
    cin >> size;

    const int cap = 100;

    int* arr = new int[cap];

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

    int x, index;

    cout << "\nInput the element: " << endl;
    cin >> x;

    cout << "Input the index where you want to insert:" << endl;
    cin >> index;

    if (x > (cap-1))
    {
        cout << "Not possible" << endl;
    }


    for (int i = cap-1; i > index; i--)
    {
        arr[i] = arr[i - 1];
        
    }

    arr[index] = x;

    cout << "Array: " << endl;

    for (int i = 0; i < size+1; i++)
    {
        cout << arr[i] << " ";
    }
}