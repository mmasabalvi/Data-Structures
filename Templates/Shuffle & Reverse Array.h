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


//-----------------------------------------//
//         Shuffle  and Reverse            //
//-----------------------------------------//

/*TEST(DeckOperationsTest, ReverseDeckTest) {
    // Create a reversed array
    int originalArray[] = { 5, 4, 3, 2, 1 };
    int reversedArray[] = { 1, 2, 3, 4, 5 };

    // Call the reverse_deck function
    reverse_deck(originalArray, 5);

    // Check if the reversed array is equal to the array returned by the function
    for (int i = 0; i < 5; ++i) {
        ASSERT_TRUE(originalArray[i] == reversedArray[i]);
    }
}

// Test case for shuffle_deck function
TEST(DeckOperationsTest, ShuffleDeckTest) {
    // Create an array
    int originalArray[] = { 1, 2, 3, 4, 5 };

    // Make a copy of the original array
    int expectedArray[5];
    for (int i = 0; i < 5; ++i) {
        expectedArray[i] = originalArray[i];
    }

    // Call the shuffle_deck function
    shuffle_deck(originalArray, 5);
    std::cout << "Original Array\n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << originalArray[i] << "\n";
    }
    std::cout << "Expected Array\n";
    for (int i = 0; i < 5; i++)
    {
        std::cout << expectedArray[i] << "\n";
    }
    // Check if the shuffled array is a permutation of the original array
    int matchCount = 0;
    for (int i = 0; i < 5; ++i) {
        if (originalArray[i] == expectedArray[i]) {
            ++matchCount;
            break;
        }
    }


    // Assert that at least one element has changed its position
    ASSERT_TRUE(matchCount < 5);
}*/
