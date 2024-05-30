/*List Arithmetic Operations
Let’s design a machine to perform arithmetic operations on strings represented as linked lists. In this
context:

• Addition: aaaaa + aaa = aaaaaaaa
• Subtraction: aaaa − aa = aa
• Addition with different characters: ab + ba = abba
• Subtraction with exact matches: ab − ab = ””
• Subtraction with different characters: ab − ba = ”abba”*/


#include<iostream>
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

    int find(T data)
    {
        Node<T>* tempNode = head;

        int node = 1;

        while (tempNode != nullptr && tempNode->data != data)
        {
            tempNode = tempNode->next;
            node++;
        }

        int index;

        if (tempNode != nullptr)
        {
            index = node - 1;
            return index;
        }

        else
        {
            index = -1;
            return index;
        }
    }


    LinkedList<T> ArithmeticOperation()
    {
        int Pluspos = find('+');                                                                    //looks to check if there is + or  -
        int Minuspos = find('-');

        LinkedList<T> obj;
        
        Node<T>* tempNode = head;
         
        if (tempNode->next != nullptr)
        {
             tempNode = tempNode->next;                                                             //temp pointer points to second node, # purposely missed
        }

        obj.insert('#');                                                                            //hash added manually

        while (tempNode != nullptr && tempNode->data != '#')
        {
            obj.insert(tempNode->data);                                                             //inserts all data until # appears
            tempNode = tempNode->next;
        }

        obj.insert('=');                                                                            //adds equal 

        Node<T>* start = head;

        if (start->next != nullptr)
        {
            start = start->next;                                                                    //another pointer head points at second element
        }

        int index = 1;

        if (Pluspos != -1)
        {
            while (start != nullptr && index < Pluspos)
            {
                obj.insert(start->data);                                                           //inserts all points until + appears
                start = start->next;                                        
                index++;
            }

            start = start->next;                                                                  //at end of loop, points at plus so moved one node forward

            while (start != nullptr)
            {
                obj.insert(start->data);
                start = start->next;                                                                //adds all elements from +, excluding it to hash
            }
        }

        else
        {
            Node<T>* end = head;
            int index = 0;

            while (end != nullptr && index != Minuspos + 1)                                        //end points to node after -
            {
                end = end->next;
                index++;
            }

            while (start->data != '-' || end->data != '#')                                         //loop runs until both of them reach their respective ends
            {
                int count = 0;
                
                bool anyExactMatches = true;
                                                                                                    //this condition when either of them reaches the end, and are not same then added, 
                                                                                                    //now implement condition if both of them end reached, then add both
                if (start->data != end->data || count > 0)                                         //count checking if any of them reached end         
                {                                                                                  //for aaaaa-aa
                    obj.insert(start->data);                                                        //data simply added, now real game begins

                    if (start->data != end->data)                                                   //if data at nodes not same, then we set anymatches as false
                    {
                        anyExactMatches = false;

                        if (end->data == '#')                                                       //but bear in mind that in last node for end, when it reaches #, we shall have to compare it with the last element before #
                        {
                            if (end->prev->data == start->data)                                     //if the last element before # same as start ka data
                            {
                                anyExactMatches = true;                                                  //then anymatches is true and we do not need to add the elements in end
                            }
                        }
                    }

                    if (anyExactMatches == false && start->next->data == '-')                            //if elements not same, and we have added all elements from current
                    {                                                                               //while reaching the end, then we will add elements from '-' to '#'
                        Node<T>* check = start->next;

                        while (check->next->data != '#')
                        {
                            check = check->next;
                            obj.insert(check->data);
                        }
                        
                    }
                }


                if (start->data != '-')
                {
                    start = start->next;
                }

                else
                {
                    count++;
                }

                if (end->data != '#')
                {
                    end = end->next;
             
                }

                else
                {
                    count++;
                }
            }

            obj.insert('#');
        }
      
        return obj;
    }
};

//TEST CASES:
/*
TEST(StringArithmeticTest, Test1_2a) {
    LinkedList<char> num;

    std::string str = "#aaaaaaaaaaaaaaaaaaaaaa+aa#";

    for (char c : str) {
        num.insert(c);
    }

    LinkedList<char> result = num.ArithmeticOperation();

    // Convert result linked list to string for comparison
    std::string resultStr;
    Node<char>* current = result.head;
    while (current) {
        resultStr += current->data;
        current = current->next;
    }

    EXPECT_EQ(resultStr, "#aaaaaaaaaaaaaaaaaaaaaa+aa=aaaaaaaaaaaaaaaaaaaaaaaa#");
}

TEST(StringArithmeticTest, Test1_2b) {
    LinkedList<char> num;

    std::string str = "#aaaaaaaaaaaaaaaaaaaaaa-aa#";

    for (char c : str) {
        num.insert(c);
    }

    LinkedList<char> result = num.ArithmeticOperation();

    // Convert result linked list to string for comparison
    std::string resultStr;
    Node<char>* current = result.head;
    while (current) {
        resultStr += current->data;
        current = current->next;
    }

    EXPECT_EQ(resultStr, "#aaaaaaaaaaaaaaaaaaaaaa-aa=aaaaaaaaaaaaaaaaaaaa#");
}

TEST(StringArithmeticTest, Test1_2c) {
    LinkedList<char> num;

    std::string str = "#aaabbabaaab+abababbb#";

    for (char c : str) {
        num.insert(c);
    }

    LinkedList<char> result = num.ArithmeticOperation();

    // Convert result linked list to string for comparison
    std::string resultStr;
    Node<char>* current = result.head;
    while (current) {
        resultStr += current->data;
        current = current->next;
    }

    EXPECT_EQ(resultStr, "#aaabbabaaab+abababbb=aaabbabaaababababbb#");
}

TEST(StringArithmeticTest, Test1_2e) {
    LinkedList<char> num;

    std::string str = "#abababb-abababb#";

    for (char c : str) {
        num.insert(c);
    }

    LinkedList<char> result = num.ArithmeticOperation();

    // Convert result linked list to string for comparison
    std::string resultStr;
    Node<char>* current = result.head;
    while (current) {
        resultStr += current->data;
        current = current->next;
    }

    EXPECT_EQ(resultStr, "#abababb-abababb=#");
}*/
