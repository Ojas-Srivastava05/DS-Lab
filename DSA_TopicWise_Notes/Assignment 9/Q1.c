#include<stdio.h>
void main()
{
    int num;
    printf("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY ");
    scanf("%d",&num);
    int arr[num];
    printf("ENTER THE ELEMENTS OF THE ARRAY ");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<num;i++)//pass loop
    {
        for(int j=0;j<num-1-i;j++)//swap loop
        {
            if(arr[j]>arr[j+1])
            {
                arr[j]=arr[j]^arr[j+1];
                arr[j+1]=arr[j]^arr[j+1];
                arr[j]=arr[j]^arr[j+1];
            }
        }
    }
    printf("\n THE SORTED ARRAY IS : ");
    for(int i=0;i<num;i++)
    {
        printf("%d ",arr[i]);
    }
}

