#include <iostream>
#include <fstream>
#include <sstream>
#include<algorithm>

using namespace std;

int max_student = 50;

struct Student{
	string name;
	int roll_no;
	string dept;
};

 //reading the records from file.
int reading(Student students[50], int &count)
{
	ifstream file("STUDENT.TXT");
	if (!file.is_open()) 
	{
		cout<<"\n Entered file can't be opened! ";
		return 0;
	}

//reading and getting the data from file.
string line;
count = 0;

while( getline(file,line) && count < max_student) 
{
	stringstream s(line); //Converts the entire line into a stream to split the values.
	getline ( s, students[count].name, ',');
	s >> students[count].roll_no;
	s.ignore();  //Skips the comma after the roll number.
       getline ( s, students[count].dept);
       count++;
}

file.close(); 
    return count;
}


//Bubble sort func.
void bubbleSort(Student students[], int count) 
{
	for ( int i=0; i< count-1; i++)
	{
		for (int j=0; j < count-i-1; j++)
		{
			if((students[j].name > students[j + 1].name) || (students[j].name == students[j + 1].name) 
			     && (students[j].roll_no > students[j + 1].roll_no) )
			     {
			     	swap(students[j], students[j+1]);
			     }
			   
		}
	}
}

//Binary search func.
void binarySearch(Student students[], int count, string searchName) 
{
	bool found = false;
	for (int i =0; i<count; i++)
	{
		if(students[i].name == searchName)
		{
		       cout<<students[i].name << ", " << students[i].roll_no << ", " << students[i].dept << endl;
			found = true;
		}
	}
	
	if(!found)
	{
		cout<< "\n Student not found!";
		
	}
}

//func to display the record.
void display(Student students[], int count)
{
	for (int i = 0; i<count; i++)
	{
		cout<<students[i].name << ", " << students[i].roll_no << ", " << students[i].dept << endl;
	}
}

int main()
{
	Student students[max_student]; //array declaration 
	int count=0; // no of students.
	
	if(reading(students, count) == 0)
	{
		cout<< "\n NO RECORD FOUND!";
		return 0; 
	}
	
	int choice;
	do {
		cout<<"\n MENU: \n 1. BUBBLE SORT. \n 2. BINARY SEARCH. \n 3. QUIT. \n 4. Enter your choice: ." ;
		cin>>choice;
		cin.ignore(); //ignore newline
		
	switch (choice)
	 {
		case 1:
			bubbleSort(students, count);
			cout<<"\n Sorted Records: ";
			display(students, count);
			break;
		
		case 2:
			cout<<"\n Enter name to be searched: ";
			string searchName;
			getline(cin, searchName);
			binarySearch(students, count, searchName);
                     break;
                     
              case 3 :
              	{
			cout <<"\n Exiting program.";
              	return 0;
                     break;
                     }
                     
              default:
              	cout<<"\n Invalid choice! Try again please.";
		 
        }
       } while(choice != 3);
       
       return 0;
       
}