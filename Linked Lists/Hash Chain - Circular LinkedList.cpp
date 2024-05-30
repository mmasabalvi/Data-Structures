/*Design a system to create a hash chain where each index is denoted by a character ’A-Z’. Every time a
sentence is added, it should be placed in the circular linked list corresponding to the first character of the
sentence. Ensure that the hash chain contains only unique sentences.In case of exception input store them
in a separate node.*/


#include "ListMachine.h"

template <class h, class T>
class Node_Hash 
{
public:
    Node_Hash<h, T>* next;
    h character;
    LinkedList<T>  data;   
};


template <class h, class T> 
class HashChain
{
private:
    Node_Hash<h, T>* head;

public:

    HashChain()
    {
        head = nullptr;

        Node_Hash<h, T>* current = nullptr;

        for (char letter = 'A'; letter <= 'Z'; letter++)
        {
            Node_Hash<h, T>* temp = new Node_Hash<h, T>;

            if (head == nullptr)
            {
                head = temp;                                                //If empty then put node on head
            }

            else
            {
                current->next = temp;                                         //If not empty, then put on current->next
            }

            temp->next = head;                                             //connect new node with head, make circular
            current = temp;                                                 //Update current
            temp->character = letter;                                       //put letter on character
        }

        Node_Hash<h, T>* temp = new Node_Hash<h, T>;
        temp->character = '*';                                              //* manually added 
        temp->next = head;  
        current->next = temp;

    }

    bool addSentence(string s)
    {
        char letter = s[0];                                                             //store first letter

        Node_Hash<h, T>* temp = head;

        while (temp != nullptr && temp->character != letter && temp->next != head)
        {
            temp = temp->next;                                                          //compare until found, if not found then already would be pinting at lastnode
        }                                                                               //in this case '*'

        if (temp != nullptr)                                                             //exceptions handled, as will already point to * node if letter not found
        {
            LinkedList<T>& list = temp->data;                                           //temp linkedlist made

            Node<T>* current = list.getHead();                                          //ptr to linked list

            while (current != nullptr)
            {
                if (current->data == s)                                                 //compares if linked list already has the sentence
                {
                    return false;                                                       //if found, then returns false
                }

                current = current->next;
            }

            list.insert(s);                                                             
            return true;
        }

        else
        {
            return false; 
        }
    }


    Node_Hash<h, T>* getHead()
    {
        return head;
    }


    LinkedList<T>* getIndexList(h index)              
    {
        Node_Hash<h, T>* temp = head;

        while (temp->character != index && temp->next != head)
        {
            temp = temp->next;
        }

        if (temp->character == index) 
        {
            return &temp->data;
        }

        else 
        {
            return nullptr;
        }
    }
    
};

//TEST CASES


//TEST(HashChainTest, Test2a) {
//    HashChain<char, string> hashChain;
//
//    std::string sentence = "This is a unique sentence.";
//
//    EXPECT_TRUE(hashChain.addSentence(sentence));
//}
//
//TEST(HashChainTest, Test2b) {
//    HashChain<char, std::string> hashChain;
//    std::string sentence = "This is a duplicate sentence.";
//
//    // Add the sentence twice
//    hashChain.addSentence(sentence);
//    bool secondAddResult = hashChain.addSentence(sentence);
//
//    EXPECT_FALSE(secondAddResult);
//}
//
//TEST(HashChainTest, Test2c) {
//    HashChain<char, std::string> hashChain;
//
//    // Add some sentences to the hash chain
//    hashChain.addSentence("Apple is a fruit.");
//    hashChain.addSentence("Banana is yellow.");
//    hashChain.addSentence("Cat is an animal.");
//    hashChain.addSentence("Austrailia won world CUP!");
//    hashChain.addSentence("Canada is a country");
//
//
//    char indexCharacter = 'C';
//    LinkedList<std::string>* indexList = hashChain.getIndexList(indexCharacter);
//
//    // Verify that the index list is not null
//    ASSERT_NE(indexList, nullptr);
//
//    // Convert the index list to a vector for comparison
//    std::vector<std::string> sentencesInIndexList;
//    Node<std::string>* current = indexList->getHead();
//    Node<std::string>* current2 = current;
//
//    while (current) {
//        sentencesInIndexList.push_back(current->data);
//        current = current->next;
//
//        if (current == current2)
//            break;
//    }
//
//    // Expect that the retrieved index list contains the added sentences
//    EXPECT_EQ(sentencesInIndexList.size(), 2);
//    EXPECT_EQ(sentencesInIndexList[0], "Cat is an animal.");
//    EXPECT_EQ(sentencesInIndexList[1], "Canada is a country");
//}
//
//TEST(HashChainTest, Test2d) {
//    HashChain<char, std::string> hashChain;
//
//    // Add some sentences to the hash chain
//    hashChain.addSentence("Apple is a fruit.");
//    hashChain.addSentence("Banana is yellow.");
//    hashChain.addSentence("#123abc");
//    hashChain.addSentence("*12345");
//    hashChain.addSentence("*zz*zz");
//
//
//    char indexCharacter = '*';
//    LinkedList<std::string>* indexList = hashChain.getIndexList(indexCharacter);
//
//    // Verify that the index list is not null
//    ASSERT_NE(indexList, nullptr);
//
//    // Convert the index list to a vector for comparison
//    std::vector<std::string> sentencesInIndexList;
//    Node<std::string>* current = indexList->getHead();
//    Node<std::string>* current2 = current;
//
//    while (current) {
//        sentencesInIndexList.push_back(current->data);
//        current = current->next;
//
//        if (current == current2)
//            break;
//    }
//
//    // Expect that the retrieved index list contains the added sentences
//    EXPECT_EQ(sentencesInIndexList.size(), 3);
//    EXPECT_EQ(sentencesInIndexList[0], "#123abc");
//    EXPECT_EQ(sentencesInIndexList[1], "*12345");
//    EXPECT_EQ(sentencesInIndexList[2], "*zz*zz");
//}
