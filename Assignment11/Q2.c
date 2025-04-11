#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int max = arr[0];
    
    // maximum element dhund rha hun
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // count array banake usko initialize kar rha hun yha par mei malloc bhi use kar sakta tha
    int *count = (int *)calloc(max + 1, sizeof(int));

    // Count occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // waapas sorted array ko banaya
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    free(count);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
