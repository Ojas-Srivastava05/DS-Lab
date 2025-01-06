#include<stdio.h>
void main()
{
    printf("ENTER THE NUMBER OF ELEMENTS IN THE BITONIC ARRAY ");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("ENTER THE %d ELEMENTS OF THE ARRAY \n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int ul=n,ll=0,mid;
    int maxi;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<arr[i+1])
        {
            maxi=i+1;
        }
        if(arr[i]>arr[i+1])
        {
            break;
        }
    }
    printf("\n THE MAXIMUM ELEMENT INDEX NUMBER IS %d",maxi);
    int flag=1;
    while(ll<ul)//BINARY SEARCH HAS TIME COMPLEXITY OF O(log(nś))
    {
        mid=(ll+ul)/2;
        if(mid==maxi)
        {
            flag=0;
            break;
        }
        if(mid>maxi)
        {
            ul=mid-1;
        }
        if(mid<maxi)
        {
            ll=mid-1;
        }

    }
    if(flag==0)
    {
        printf("\n THE MAXIMUM ELEMENT HAS BEEN FOUND AT %d ",maxi);
        printf("\n THE MAXIMUM ELEMENT IS %d",arr[maxi]);
    }
    

}
