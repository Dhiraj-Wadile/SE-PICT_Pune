/*Implement Circular Queue using Array. Perform following operations on it.
a) Insertion (Enqueue)
b) Deletion (Dequeue)
c) Display
(Note: Handle queue full condition by considering a fixed size of a queue.)*/
#include <iostream>
using namespace std;
struct Student // Structure of student
{
    string name;
    int rn; 
};

class Queue // Declaring Class
{
public:
    int front, rear;
    Student sQueue[5];

    Queue() // Constructor
    {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() // IsEmpty Function
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool IsFull() // IsFull Function
    {
        if ((rear + 1) % 5 == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Enqueue() // Enqueue Functioin
    {
        string name;
        int rollno;
        cout << "\nEnter your name and roll no: ";
        cin >> name >> rollno;
        if (!IsFull())
        {
            rear = (rear + 1) % 5;
            sQueue[rear].name = name;
            sQueue[rear].rn = rollno;
            cout << "\nElement is added successfully." << endl;
        }
        else
            cout << "\nQueue is Full." << endl;
    }

    void Dequeue() // Dequeue Function
    {
        if (!IsEmpty())
        {
            front = (front + 1) % 5;
            cout << "\nElement is removed successfully." << endl;
        }
        else
            cout << "\nQueue is Empty." << endl;
    }
    
    void display() // Display Function
    {
        if (IsEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "\nThe Queue is :";
            for (int i = front + 1; i <= rear; i++)
            {
                cout << sQueue[i].name << "  ";
                cout << sQueue[i].rn << " ";
            }
        }
    }
};

int main()
{
    int choice;
    Queue a1; // Instance of class Queue

    do
    {
        cout << "\n-------------------------";
        cout << "\n---Operations on Queue---";
        cout << "\n1.IsEmpty";
        cout << "\n2.Enqueue";
        cout << "\n3.Dequeue";
        cout << "\n4.Display";
        cout << "\n5.Exit";
        cout << "\n-------------------------";
        cout << "\nEnter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (a1.IsEmpty())
                cout << "\nQueue is Empty\n";
            else
                cout << "\nQueue is not empty\n";
            break;

        case 2:
            a1.Enqueue();
            break;

        case 3:
            a1.Dequeue();
            break;

        case 4:
            a1.display();
            break;
        }

    } while (choice!=4);
}
