#include <stdio.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int roll;
    char department[50];
} Student;

void bubbleSort(Student s[], int n);
void binarySearch(Student s[], int n);

int main() {
    FILE *fp;
    Student s[100];
    int n = 0;

    // Open file
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("File not found\n");
        return 0;
    }

    // Read student records safely
    while (fgets(s[n].name, 50, fp)) {
        s[n].name[strcspn(s[n].name, "\n")] = '\0'; // Remove trailing newline
        fscanf(fp, "%d\n", &s[n].roll);
        fgets(s[n].department, 50, fp);
        s[n].department[strcspn(s[n].department, "\n")] = '\0'; // Remove trailing newline
        n++;
    }
    fclose(fp);

    int choice;
    while (1) {
        printf("\n1. Bubble Sort\n");
        printf("2. Binary Search\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                bubbleSort(s, n);
                printf("Records sorted successfully.\n");
                break;
            case 2:
                binarySearch(s, n);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Bubble Sort: Sort by Name, then Roll No (if names are same)
void bubbleSort(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(s[j].name, s[j + 1].name) > 0 || 
                (strcmp(s[j].name, s[j + 1].name) == 0 && s[j].roll > s[j + 1].roll)) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("\nSorted Student Records:\n");
    for (int i = 0; i < n; i++) {
        printf("%s, %d, %s\n", s[i].name, s[i].roll, s[i].department);
    }
}

// Binary Search for Student Name
void binarySearch(Student s[], int n) {
    char searchName[50];
    printf("Enter student name to search: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove trailing newline

    int low = 0, high = n - 1, found = 0;

    // Perform binary search for name
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(s[mid].name, searchName);

        if (cmp == 0) { // Name found
            // Print all matching records
            int i = mid;
            while (i >= 0 && strcmp(s[i].name, searchName) == 0) { 
                printf("Student found: %s, %d, %s\n", s[i].name, s[i].roll, s[i].department);
                i--;
            }
            i = mid + 1;
            while (i < n && strcmp(s[i].name, searchName) == 0) { 
                printf("Student found: %s, %d, %s\n", s[i].name, s[i].roll, s[i].department);
                i++;
            }
            found = 1;
            break;
        } else if (cmp > 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}