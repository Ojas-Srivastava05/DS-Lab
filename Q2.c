#include<stdio.h>
void main()
{
    int n;
    printf("ENTER THE NUMBER OF ELEMENTS IN TNE ARRAY \n");
    scanf("%d",&n);
    printf("ENTER THE %d ELEMENTS OF THE ARRAY \n",n);
    int arr[n],count=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j] && i<j)
            {
                count++;
            }
        }
    }
    printf("THE NUMBER OF PERMUTATIONS ARE %d ",count);
}