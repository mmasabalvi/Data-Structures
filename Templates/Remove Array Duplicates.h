#include "pch.h"
template<typename T>
T* removeDuplicates(T array[], int size, int &newSize)
{
    T* arr2 = new T[size];

    newSize = 0;

    for (int i = 0; i < size; i++)
    {
        int count = 0;

        for (int j = 0; j <= i; j++)
        {
            if (array[i] == array[j])
            {
                count++;
            }
        }

        if (count <= 1)
        {
            arr2[newSize] = array[i];
            newSize++;
        }
    }

    return arr2;
}
