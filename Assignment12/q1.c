#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 7
#define ARRAY_SIZE 9

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** bucket, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*bucket == NULL || value < (*bucket)->data) {
        newNode->next = *bucket;
        *bucket = newNode;
    } else {
        struct Node* current = *bucket;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void bucketSort(int arr[], int n) {
    struct Node* buckets[BUCKET_SIZE] = {NULL};

    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = (max - min + 1) / BUCKET_SIZE + 1;

    for (int i = 0; i < n; i++) {
        int index = (arr[i] - min) / range;
        insert(&buckets[index], arr[i]);
    }

    int idx = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[idx++] = current->data;
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int arr[ARRAY_SIZE] = {12, 45, 33, 87, 56, 9, 11, 7, 67};

    bucketSort(arr, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
