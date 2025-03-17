/*
 Let A[n] be an array of n distinct integers. If I < j and A[i] > A[j], then the pair (I, j) Is 
called an inversion of A. Write a C/C++ program that determines the number of 
Inversions in any permutation on n elements in O(n lg n) worst-case time. (Hint: Modify 
merge sort)  
Example: A = {4, 1, 3, 2} output is 4 
  
*/

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n;
    printf("Enter the number of elements in the array");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int inv = mergeSort(arr, 0, n-1);
    printf("Number of inversions: %d\n", inv);
}

void mergesort(int arr,int low,int high)
{
    if(low < high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
    }
}