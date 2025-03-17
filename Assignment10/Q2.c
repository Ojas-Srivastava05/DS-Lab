// /*
//  Let A[n] be an array of n distinct integers. If I < j and A[i] > A[j], then the pair (I, j) Is 
// called an inversion of A. Write a C/C++ program that determines the number of 
// Inversions in any permutation on n elements in O(n lg n) worst-case time. (Hint: Modify 
// merge sort)  
// Example: A = {4, 1, 3, 2} output is 4 
  
// */

#include <stdio.h>
#include <stdlib.h>

int mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int invCount = mergeSort(arr, temp, 0, n - 1);
    printf("Number of inversions: %d\n", invCount);

    free(arr);
    free(temp);
    return 0;
}

// Merge Sort function that returns the number of inversions
int mergeSort(int arr[], int temp[], int left, int right) {
    int mid, invCount = 0;
    if (left < right) {
        mid = (left + right) / 2;

        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);
        invCount += merge(arr, temp, left, mid, right);
    }
    return invCount;
}

// Merge function that merges two halves and counts inversions
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);  // Count inversions
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

// #include<stdio.h>
// #include<stdlib.h>

// void main()
// {
//     int n;
//     printf("Enter the number of elements in the array");
//     scanf("%d",&n);
//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     int inv = mergeSort(arr, 0, n-1);
//     printf("Number of inversions: %d\n", inv);
// }

// void mergesort(int arr[],int low,int high)
// {
//     if(low < high)
//     {
//         int mid=(low+high)/2;
//         mergesort(a,low,mid);
//         mergesort(a,mid+1,high);
//         merge(arr,low,mid,high)
//     }
// }

// int merge(int arr[],int low,int mid,int high)
// {
//     int i=low;
//     int j=mid+1;
//     int b[high-low+1];
//     int k=0;
//     int count=0;
//     while(i<=mid&&j<=high)
//     {
//         if(arr[i]>arr[j])
//         {
//             b[k++]=arr[j];
//             j++;
//             count++;
//         }
//         else
//         {
//             b[k]=a[i];
//             i++;
//             k++;
//         }
//         while(j!=high)
//         {
//             b[k]=a[j];
//             k++;
//             j++;
//         }
//         while(i!=mid)
//         {
//             b[k]=a[i];
//             k++;
//             i++;
//         }
//         for(j=0,i=low;i<=high;j++,i++)
//         {
//             a[i]=b[j];
//         }
//         return count;
    
// }