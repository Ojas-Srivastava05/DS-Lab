#include <stdio.h>
#include<string.h>

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
    
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("File not found\n");
        return 0;
    }
    
    while (fscanf(fp, "%[^,],%d,%[^,]\n", s[n].name, &s[n].roll, s[n].department) != EOF) {
        n++;
    }
    fclose(fp);

    int choice;
    while (1) {
        printf("1. Bubble Sort\n");
        printf("2. Binary Search\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(s, n);
                break;
            case 2:
                binarySearch(s, n);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void bubbleSort(Student s[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // First sort by name (lexicographically)
            if (strcmp(s[j].name, s[j + 1].name) > 0 || 
                (strcmp(s[j].name, s[j + 1].name) == 0 && s[j].roll > s[j + 1].roll)) {
                
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void binarySearch(Student s[], int n) {
    int low = 0, high = n - 1, mid;
    int roll;

    printf("Enter roll number to search\n");
    scanf("%d", &roll);

    while (low <= high) {
        mid = (low + high) / 2;
        if (s[mid].roll == roll) {
            printf("Student found: %s, %d, %s\n", s[mid].name, s[mid].roll, s[mid].department);
            return;
        } else if (s[mid].roll > roll) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("Student not found\n");
}