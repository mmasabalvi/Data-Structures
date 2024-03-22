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

    //------------------------------------------//
//           Duplicates Removal             //
//------------------------------------------//

/*TEST(RemoveDuplicatesTest, IntArrayTest) {
    int intArray[] = { 1, 2, 3, 4, 2, 5, 6, 3, 7, 8, 1 };
    int uniqueIntCount;
    int* uniqueIntArray = removeDuplicates(intArray, 11, uniqueIntCount);

    int expectedUniqueIntArray[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int expectedUniqueIntCount = 8;

    ASSERT_EQ(uniqueIntCount, expectedUniqueIntCount);

    delete[] uniqueIntArray;
}

TEST(RemoveDuplicatesTest, CharArrayTest) {
    char charArray[] = { 'a', 'b', 'c', 'b', 'd', 'e', 'a' };
    int uniqueCharCount;
    char* uniqueCharArray = removeDuplicates(charArray, 7, uniqueCharCount);

    char expectedUniqueCharArray[] = { 'a', 'b', 'c', 'd', 'e' };
    int expectedUniqueCharCount = 5;

    ASSERT_EQ(uniqueCharCount, expectedUniqueCharCount);


    delete[] uniqueCharArray;
}*/

