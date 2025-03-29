#include <stdio.h>

void countingSort(int array[], int size, int exp) {
    int output[size];
    int count[10] = {0};
    for (int i = 0; i < size; i++) {
        count[(array[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

int getMax(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void radixSort(int array[], int size) {
    int max = getMax(array, size);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(array, size, exp);
    }
}

int main() {
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(array) / sizeof(array[0]);
    radixSort(array, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
