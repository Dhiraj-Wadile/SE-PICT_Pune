// Department maintains student’s database. The file contains roll number, name, division and address.
// Write a program to create a sequential file to store and maintain student data. It should allow the
// user to add, delete information of student. Display information of particular student. If record of
// student does not exist an appropriate message is displayed. If student record is found it should
// display the student details.
#include <iostream>
#include <fstream>
#include<climits>
#include<sstream>
using namespace std;

struct Student
{
    int roll_no;
    string name;
    int division;
    string address;
};
class StudentD
{
public:
    Student record;
    int num_student=1;
public:
    void newFile();
    void clearFile();
    void add();
    void display();
    void search();
    void delete_record();

    StudentD(){
        clearFile();
        newFile();
    }
};

void StudentD::newFile()
{
    ofstream obj("Student_Database.txt");
    obj<<"Roll No\t\tName\t\tDivision\tAddress"<<endl;
    obj.close();
    cout<<"\n\nNew File Created Succesfully!!!"<<endl;
    return;
}
void StudentD::clearFile()
{
    ofstream obj("Student_Database.txt",ios::trunc);
    cout<<"\n\nFile Cleared SuccessFully!!!";
    obj.close();
}
void StudentD::add()
{
    cout<<"\nEnter Record "<<num_student<<endl;
    ofstream obj;
    obj.open("Student_Database.txt",ios::app);
    cout<<"\nEnter Roll No : ";
    cin>>record.roll_no;
    cout<<"Enter Name : ";
    cin>>record.name;
    cout<<"Enter Division : ";
    cin>>record.division;
    cout<<"Enter Address : ";
    cin>>record.address;

    num_student++;
    obj<<record.roll_no<<"\t\t"<<record.name<<"\t\t"<<record.division<<"\t\t"<<record.address<<endl;
    obj.close();
}
void StudentD::display()
{
    ifstream obj;
    obj.open("Student_Database.txt");
    if(obj.is_open())
    {
        string line;
        while(getline(obj,line))
        {
            cout<<line<<endl;
        }
        obj.close();
    }
    else
    {
        cout<<"File not Found";
    }
    cout<<endl;
}
void StudentD::search()
{
    int rn;
    cout<<"\nEnter Roll No to Be Found : ";
    cin>>rn;
	ifstream obj;
    obj.open("Student_Database.txt");
    if(obj.is_open())
    {
        int j=0;
        string line;
        while(getline(obj,line))
        {
            string arr[4];
			int i=0;
            stringstream input(line);
            while(input.good() && i<4)
            {
                input>>arr[i];
                i++;
            }       
            if(to_string(rn)==arr[0])
            {
                cout<<"\n\nSearch Succesful!!! \n\nRecord Found at Position "<<j<<"\n\nRecord : ";
                for(int i=0;i<4;i++)
                {
                    cout<<arr[i]<<" ";
                }
                return;
            }
            j++;
        }
        cout<<"\nRecord Not Found";
        obj.close();
    }
    else
    {
        cout<<"File not Found";
    }
    cout<<endl;
}
void StudentD::delete_record()
{
    int rn;
    cout<<"\nEnter Roll No to Be Deleted : ";
    cin>>rn;
	ifstream obj;
    ofstream temp("temp_samp.txt");
    obj.open("Student_Database.txt");
    if(obj.is_open())
    {
        string line;
        while(getline(obj,line))
        {
            string arr[4];
			int i=0;
            stringstream input(line);
            while(input.good() && i<4)
            {
                input>>arr[i];
                i++;
            }       
            if(to_string(rn)!=arr[0])
            {
                temp<<line<<endl;
            }
        }
        cout<<"\nData Deleted Successfully!!!";
        obj.close();
        temp.close();
        remove("Student_Database.txt");
        rename("temp_samp.txt","Student_Database.txt");
    }
    else
    {
        cout<<"File not Found";
    }
    cout<<endl;
}

int main()
{
    StudentD s;
    int choice;
    do{
        cout<<"\n------------Menu--------------";
        cout<<"\n\n1.Create New File";
        cout<<"\n2.Add Record";
        cout<<"\n3.Display Record";
        cout<<"\n4.Delete Record";
        cout<<"\n5.Search Record";
        cout<<"\n6.Clear File";
        cout<<"\n7.Exit";
        cout<<"\n\nChoose an Option : ";
        int choice;
        cin>>choice;

        switch(choice)
        {
            case 1:
				s.newFile();
				break;
			case 2:
				s.add();
				break;
			case 3:
				s.display();
				break;
			case 4:
				s.delete_record();
				break;
			case 5:
				s.search();
				break;
            case 6:
                s.clearFile();
                break;
			case 7:
				cout<<"\n-----------------Thank You-------------------";
				break;
			default:
				cout<<"\n\nInvalid Input";					
        }
    }while(choice!=7);
    return 0;
}