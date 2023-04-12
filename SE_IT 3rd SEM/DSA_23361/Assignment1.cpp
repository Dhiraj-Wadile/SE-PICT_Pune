// Consider a student database of SEIT class (at least 15 records). Database contains different fields of
// every student like Roll No, Name and SGPA.(array of structure)
// a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use
// Bubble Sort)
// b) Arrange list of students alphabetically. (Use Insertion sort)
// c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
// d) Search students according to SGPA. If more than one student having same SGPA, then print list
// of all students having same SGPA.
// e) Search a particular student according to name using binary search without recursion. (all the
// student records having the presence of search key should be displayed)
// (Note: Implement either Bubble sort or Insertion Sort.)
#include <iostream>
using namespace std;

struct Student // Student Structure
{
public:
    string name;
    int rno;
    float SGPA;
};

class StudentData // Declaring a class
{
public:
    Student s[3];
    int i;

    void addData()
    {
        cout << "Student DataBase: ";
        for (i = 0; i < 3; i++) // Taking input from user
        {
            cout << "\nEnter Student name: ";
            cin >> s[i].name;
            cout << "Enter Student roll no: ";
            cin >> s[i].rno;
            cout << "Enter Student SGPA: ";
            cin >> s[i].SGPA;
        }
    }

    void viewData()
    { // Printing the Student Data
        cout << "\nStudent DataBase: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "\nStudent name: " << s[i].name << endl;
            cout << "Student Roll no: " << s[i].rno << endl;
            cout << "Student SGPA: " << s[i].SGPA << endl;
        }
    }

    void viewData1()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "\nStudent name: " << s[i].name << endl
                 << "Student Roll no: " << s[i].rno << endl
                 << "Student SGPA: " << s[i].SGPA << endl;
        }
    }

    void LinearSearch(Student arr[], int n)
    { // Linear searching on Student Database
        int key;
        cout << "\nLinear Searching: " << endl;
        cout << "\nEnter Roll no for linear search: ";
        cin >> key;
        for (i = 0; i < n; i++)
        {
            if (arr[i].rno == key)
            {
                cout << "The Roll no found at index " << i << endl;
                return;
            }
        }
        cout << "\nThe Roll no not found." << endl;
        cout << "\n\n<<-------------------------------------------->>";
    }

    void BinarySearch(Student arr[], int n)
    { // Binary searching on Student Database
        int low = 0;
        int high = n -1;
        float key;
        cout << "\nEnter SGPA for Binary Search: ";
        cin >> key;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid].SGPA == key)
            {
                cout << "SGPA Found.";
                return;
            }
            else if (key > arr[mid].SGPA)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (low > high)
        {
            cout << "\nThe SGPA not found.";
        }

        cout << "\n\n<<-------------------------------------------->>";
    }

    void Bubblesort(Student s[], int n)
    { // Bubble Sorting Roll no of Student Database

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (s[j].rno > s[j + 1].rno)
                {
                    swap(s[j], s[j + 1]);
                }
            }
        }
        cout << "\n\n<<-------------------------------------------->>";
    }

    void Insertionsort(Student s[], int n)
    { // Insertion Sorting of Student names alphabetically

        for (int i = 1; i < n; i++)
        {
            string key = s[i].name;
            int key1 = s[i].rno;
            float key2 = s[i].SGPA;

            int j = i - 1;
            while ((j >= 0) && (key < s[j].name))
            {
                s[j + 1] = s[j];
                j--;
            }
            s[j + 1].name = key;
            s[j + 1].rno = key1;
            s[j + 1].SGPA = key2;
        }
        cout << "\n\n<<-------------------------------------------->>";
    }

    int partition(Student s[], int low, int high, float key)
    {
        int i = low;
        int j = low;

        while (i <= high)
        {
            if (s[i].SGPA > key)
                i++;
            else
            {
                swap(s[i], s[j]);
                i++;
                j++;
            }
        }
        return j - 1;
    }

    void QuickSort(Student s[], int low, int high)
    {
        int pindex;
        float key;
        if (low < high)
        {
            key = s[high].SGPA;
            if (low <= high)
            {
                pindex = partition(s, low, high, key);
                QuickSort(s, low, pindex - 1);
                QuickSort(s, pindex + 1, high);
            }
        }
    }
};

int main() // Main function
{
    int choice;

    StudentData SEstudent; // Object of class StudentData

    SEstudent.addData();
    SEstudent.viewData();
    do
    {
        cout << "\n1.Enter an element for linear search in Database";
        cout << "\n2.Enter an element for Binary search in Database";
        cout << "\n3.Bubble Sorting Roll no of Database";
        cout << "\n4.Insertion Sorting to arrange names alphabetically of Database";
        cout << "\n5.Quick Sorting of 10 Toppers of Database";
        cout << "\n6.Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            SEstudent.LinearSearch(SEstudent.s, 3);
            break;
        case 2:
            SEstudent.BinarySearch(SEstudent.s, 3);
            break;
        case 3:
            SEstudent.Bubblesort(SEstudent.s, 3);
            cout << "\n\nAfter BubbleSorting Roll no:" << endl;
            SEstudent.viewData();
            break;
        case 4:
            SEstudent.Insertionsort(SEstudent.s, 3);
            cout << "\n\nAfter InsertionSorting Student name Alphabetically:" << endl;
            SEstudent.viewData();
            break;
        case 5:
            SEstudent.QuickSort(SEstudent.s, 0, 2);
            cout << "\n\nThe Array after Quick sort is: ";
            SEstudent.viewData1();
            break;
        }
    } while (choice!= 5);
    return 0;
}
