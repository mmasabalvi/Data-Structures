#include "pch.h"
#include<ctime>
#include<cstdlib>
template<typename T>

void reverse_deck(T arr1[], int size)
{
    T* arr = new T[size];
    int j = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        arr[j] = arr1[i];
        j++;
    }

    for (int i = 0; i < size; i++)
    {
        arr1[i] = arr[i];
    }

}

template<typename T>
void shuffle_deck(T arr1[], int size)
{
    srand(time(0));

    int num; 
    int temp = 0;

    for (int i = 0; i < size; i++)
    {
        num = rand() % size;
        arr1[i] = temp;
        arr1[i] = arr1[num];
        arr1[num] = temp;
    }
}


