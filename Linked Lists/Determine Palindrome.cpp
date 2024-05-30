/*Determining Palindromes
Consider the problem of determining whether a given string is an even palindrome or an odd palindrome
using a Linked List.*/

include<iostream>
using namespace std;

template <class T>
class Node
{
public:
    Node<T>* next;
    Node<T>* prev;

    T data;          // add variable data

};


template <class T>
class LinkedList
{

public:
    Node<T>* head;


//public:
    LinkedList()
    {
        head = nullptr;
    }

    Node<T>* getHead()
    {
        return head;
    }

    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    Node<T>* insert(T data)
    {
        Node<T>* tempNode = head;

        while (tempNode != nullptr && tempNode->next != nullptr)
        {
            tempNode = tempNode->next;
        }

        Node<T>* newNode = new Node<T>;

        newNode->data = data;

        newNode->next = nullptr;

        newNode->prev = tempNode;


        if (head == nullptr)
        {
            head = newNode;
        }

        else
        {
            tempNode->next = newNode;
        }


        return newNode;
    }


    bool isPalindrome()
    {
        if (isEmpty())
        {
            return false;
        }

        Node<T>* tempNode1 = head;
        Node<T>* tempNode2 = head;

        int length = 1;

        while (tempNode2->next != NULL)
        {
            tempNode2 = tempNode2->next;
            length++;
        }

        for (int i = 0; i < length / 2; i++)
        {
            if (tempNode1->data != tempNode2->data)
            {
                return false;
            }

            tempNode1 = tempNode1->next;
            tempNode2 = tempNode2->prev;
        }

        if (length % 2 == 0)
        {
            cout << "Even Palindrome" << endl;
        }

        else
        {
            cout << "Odd Palindrome" << endl;
        }

        return true;

    }

};

//TEST CASES:

//TEST(PalindromeTest, Test1a) {
//    LinkedList<char> list;
//    std::string str = "abcddcba";
//
//    for (char c : str) {
//        list.insert(c);
//    }
//
//    EXPECT_TRUE(list.isPalindrome());
//}
//
//TEST(PalindromeTest, Test1b) {
//    LinkedList<char> list;
//    std::string str = "abcdcdba";
//
//    for (char c : str) {
//        list.insert(c);
//    }
//
//    EXPECT_FALSE(list.isPalindrome());
//}
//
//TEST(PalindromeTest, Test1c) {
//    LinkedList<char> list;
//    std::string str = "pakistanatsikap";
//
//    for (char c : str) {
//        list.insert(c);
//    }
//
//    EXPECT_TRUE(list.isPalindrome());
//}
//
//TEST(PalindromeTest, Test1d) {
//    LinkedList<char> list;
//    std::string str = "abcdedcbaba";
//
//    for (char c : str) {
//        list.insert(c);
//    }
//
//    EXPECT_FALSE(list.isPalindrome());
//}
