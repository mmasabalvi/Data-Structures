/*Program that simulates a checkout line at a supermarket.

Customers arrive in random integer intervals of 1-4 minutes. Each customer is served in random integer intervals of 1-4 minutes.
Obviously, the rates need to be balanced. If the average arrival rate is larger than the average service rate, 
the queue will grow infinitely. Even with "balanced" rates, randomness can still cause long lines. 
Run the supermarket simulation for a 12-hour day (720 minutes) using the following algorithm:

1. Choose a random integer from 1 to 4 to determine the minute at which the first customer arrives.

2. At the first customer's arrival time:
Determine customer's service time (random integer from 1 to 4); Begin servicing thecustomer.
Schedule arrival time of next customer (random integer 1 to 4 added to the current time),

3. For each minute of the day:
If the next customer arrives,
Say so, enqueue the customer and schedule the arrival time of next customer.
If service was completed for the last customer.
Say so, dequeue next customer to be serviced and determine customer's service
completion time (random time (random integer from 1 to 4 added to the current time)
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


class Node
{
public:
    int minutes;
    Node* next;

    Node()
    {
        next = nullptr;
    }

    Node(int minutes)
    {
        this->minutes = minutes;
        next = nullptr;
    }
};

class  Queue
{
public:
    Node* front;
    Node* rear;

    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int val)
    {
        Node* temp = new Node(val);

        if (front == nullptr)
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
        if (rear == nullptr)
        {
            return -1;
        }

        else
        {
            Node* temp = front;
            int minutes = front->minutes;

            front = front->next;

            if (front == nullptr)
            {
                rear = nullptr; //if Queue empty
            }

            delete temp;
            return minutes;
        }
    }


    int peek()
    {
        return front->minutes;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    int size()
    {
        Node* temp = front;
        int count = 0;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void clear()
    {
        Node* x = front;

        while (front != nullptr)
        {
            front = front->next;
            delete x;
            x = front;
        }
    }

};


int main()
{
    Queue line;
    srand(time(0));

    int totalTime = 0;
    int prev = 0;

    int interval = rand() % 4 + 1;
    int nextArrivalTime = interval;     //initially

    int serviceDone = 0;
    int cust = 4;

    int maxLength = 0;
    int maxTime = 0;

    while (totalTime < 720)
    {
        if (totalTime == nextArrivalTime)       //whenever totalTime equals interval+totalTime, then customer arrives
        {                                       //for first customer, always equal to interval only
            int serviceTime = rand() % 4 + 1;
            line.enqueue(serviceTime);

            cout << "\n-> Customer Arrives..." << endl;
            cout << "Arrival Interval: " << interval << " minutes" << endl;
            cout << "Current Time: " << totalTime << " minutes" << endl;
            cout << "Service Time (Estimated): " << serviceTime << " minutes" << endl << endl;


            if (line.size() == 1)                           //if queue initially empty
            {                                               //as the first customer does not have any sort of additional waiting time
                serviceDone = totalTime + serviceTime;
            }

            if (line.size() > 1)                         //for max Wait
            {
                int wait = serviceDone - nextArrivalTime;

                if (wait > maxTime)
                {
                    maxTime = wait + prev/cust;
                }
            }

            if (line.size() > maxLength)
            {
                maxLength = line.size();
            }

            interval = rand() % 4 + 1;              //For next customer
            nextArrivalTime = totalTime + interval; // Next customer's arrival time (total)
        }


        if (!line.isEmpty() && totalTime == serviceDone)
        {
            int serviceTime = line.dequeue();
            cout << "\n->Customer Service Completed..." << endl;
            cout << "Current Time: " << totalTime << " minutes" << endl;
            cout << "Service Took: " << serviceTime << " minutes" << endl << endl;


            if (!line.isEmpty())                            //if queue is not empty, then each customers service time 
            {                                               //is affected by the customer in front, so service time of front added
                serviceDone = totalTime + line.front->minutes;
                prev = serviceDone;
            }

        }

        totalTime++;
    }

    cout << "12 Hours Completed..." << endl;
    cout << "Max number of customers at any time: " << maxLength << endl;
    cout << "Longest wait for any customer: " << maxTime << " minutes" << endl;

    return 0;
}
