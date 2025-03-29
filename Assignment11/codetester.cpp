#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

int max_student = 50;

struct Student 
{
    string name;
    int roll_no;
    string dept;
};

// Function to read the records from file
int reading(Student students[], int &count) 
{
    ifstream file("STUDENT.TXT");
    if (!file.is_open()) 
    {
       cout << "\n Entered file can't be opened! ";
       return 0;
    }

    string line;
    count = 0;

    while (getline(file, line) && count < max_student) 
    {
       stringstream s(line);
       getline(s, students[count].name, ',');
       s >> students[count].roll_no;
       s.ignore();
       getline(s, students[count].dept);
       count++;
    }

    file.close();
    return count;
}

// Bubble sort function
void bubbleSort(Student students[], int count) 
{
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (students[j].name > students[j + 1].name ||
			(students[j].name == students[j + 1].name && students[j].roll_no > students[j + 1].roll_no))
			{
				swap(students[j], students[j + 1]);
			}
		}
	}
}


// Binary search function
void binarySearch(Student students[], int count, string searchName)
{
	int low = 0, high = count - 1;
       bool found = false;
       
       while (low <= high)
       {
       	int mid = low + (high - low) / 2;

              if (students[mid].name == searchName)
              {
              	found = true;
                     cout << students[mid].name << ", " << students[mid].roll_no << ", " << students[mid].dept << endl;
                     return;
		}
		else if (students[mid].name < searchName){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	if (!found)
	{
		cout << "\n Student not found!";
	}

}

//Function to display the records.
void display(Student students[], int count) 
{
    for (int i = 0; i < count; i++) 
    {
    	cout << students[i].name << ", " << students[i].roll_no << ", " << students[i].dept << endl;
    }
}

int main() {
    Student students[max_student]; 
    int count = 0; // Number of students

    if (reading(students, count) == 0) {
       cout << "\n NO RECORD FOUND!";
       return 0;
       }

    int choice;
    do {
    	
       cout << "\n MENU: \n 1. BUBBLE SORT. \n 2. BINARY SEARCH. \n 3. QUIT. \n 4. Enter your choice: ";
       cin >> choice;
       cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

       switch (choice) {
            case 1:
                bubbleSort(students, count);
                cout << "\n Sorted Records: ";
                display(students, count);
                break;

            case 2:
                cout << "\n Enter name to be searched: ";
                string searchName;
                getline(cin, searchName);
                binarySearch(students, count, searchName);
                break;

            case 3:
                cout << "\n Exiting program."<<endl;
                return 0;
              

            default:
                cout << "\n Invalid choice! Try again.";
        }
    } while (choice != 3);

    return 0;
}