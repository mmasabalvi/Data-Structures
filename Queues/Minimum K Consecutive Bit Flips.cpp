/*
Minimum Number of K Consecutive Bit Flips

You are given a binary array of nums and an integer k.
A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0
in the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not
possible, return -1.

A subarray is a contiguous part of an array.
Here's a step-by-step explanation of how to solve the problem of finding the minimum number of
k-bit flips required so that there are no zeros in the array:

● Initialize variables:
○ - Initialize a variable to keep track of the total number of flips needed.
○ - Create a queue to keep track of the indices where a flip was applied.

● Maintain a sliding window:
○ - As we iterate through the queue, maintain a sliding window of size `k`. Use a
queue to track the indices of the elements within the window.

● Check if a flip is needed:
○ - At each iteration, check if the current element is 0.

● Flip the subarray:
○ - If the current element is 0, it indicates that a flip is needed. Increment the total
flips count.
○ - Push the index of the current element into the queue to mark it for flipping.
○ - Update the elements within the sliding window by flipping them (changing 0s
to 1s and vice versa).

● Return the total number of flips:
○ - After processing all elements, return the total number of flips needed to ensure
there are no zeros in the array.

● Handle edge cases:
○ - If the given array contains only ones initially, no flips are needed, so return 0.
○ - If it's not possible to flip the subarray to eliminate all zeros, return -1.

Example 1:
Input: nums = [0,1,0], k = 1
Output: 2
Explanation: Flip nums[0], then flip nums[2].
Example 2:
Input: nums = [1,1,0], k = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, we cannot make the array become
[1,1,1].
Example 3:
Input: nums = [0,0,0,1,0,1,1,0], k = 3
Output: 3
Explanation:
Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]
*/

#include<iostream>
#include<string>
using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node<T>* next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
};


template<class T>
class  Queue
{
public:
    Node<T>* front;
    Node<T>* rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(T val)
    {
        Node<T>* temp = new Node<T>(val);

        if (front == NULL)
        {
            rear = temp;
            front = rear;
        }

        else
        {
            rear->next = temp;
            rear = temp;
        }

    }


    int dequeue()
    {
        if (rear == NULL)
        {
            return -1;
        }

        else
        {
            Node<T>* temp = front;
            int data = front->data;

            front = front->next;

            delete temp;
            return data;
        }
    }


    int peek()
    {
        if (front != nullptr)
        {
            return front->data;
        }
        
    }

    bool is_empty()
    {
        if (front == NULL)
        {
            return 1;
        }

        return 0;
    }

};


int minKBitFlips(Queue<int> nums, int k)
{
    int flipsNeeded = 0;

    int window = k;

    Node<int>* temp = nums.front;

    Queue<int> holdIndices;

    int indice = 0;

    while (temp != nullptr)
    {
        if (temp->data == 1)
        {
            //temp = temp->next;
            indice++;
        }

        else
        {
            int counter = 1;
            int counter2 = 1;

            Node<int>* temp2 = temp; //add edge case

            bool checkforwindow = 1;

            ////For Edge Case: To ensure window does not go out of bounds

            Node<int>* temp3 = temp2;
            while (counter2 < window)
            {
                temp3 = temp3->next;
                counter2++;

                if (temp3 == nullptr)
                {
                    checkforwindow = 0;
                    indice++;
                    break;
                }  
            }

      
            //cout << "check for window: " << checkforwindow << endl;
            
            while (counter <= window && holdIndices.peek() != indice && checkforwindow == 1)
            {
                
                cout << "Flips Needed: ";
                flipsNeeded++;//divide by window in the end
                cout << flipsNeeded << endl;

                if (temp2->data == 0)
                {
                    temp2->data = 1;
                }

                else
                {
                    temp2->data = 0;
                }

                holdIndices.enqueue(indice);
                indice++;
                counter++;
                temp2 = temp2->next;
            }

        }

        temp = temp->next;

        if (holdIndices.is_empty() == 0)
        {
            holdIndices.dequeue();
        }

    }

   
    bool check = 0;
    Node<int>* tempp = nums.front;

    while (tempp != nullptr)
    {
        if (tempp->data == 0)
        {
            return -1;
        }


        tempp = tempp->next;
    }

    return flipsNeeded / window;

}


//TEST CASES:
/*
TEST(MinKBitFlipsTest, ProvidedExamples) {
    Queue<int> nums1;
    nums1.enqueue(0);
    nums1.enqueue(1);
    nums1.enqueue(0);
    EXPECT_EQ(minKBitFlips(nums1, 1), 2);

    Queue<int> nums2;
    nums2. enqueue(1);
    nums2. enqueue(1);
    nums2. enqueue(0);
    EXPECT_EQ(minKBitFlips(nums2, 2), -1);

    Queue<int> nums3;
    nums3.enqueue(0);
    nums3.enqueue(0);
    nums3.enqueue(0);
    nums3.enqueue(1);
    nums3.enqueue(0);
    nums3.enqueue(1);
    nums3.enqueue(1);
    nums3.enqueue(0);
    EXPECT_EQ(minKBitFlips(nums3, 3), 3);
}
*/
