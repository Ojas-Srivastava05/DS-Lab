#include<stdio.h>
struct question2
{
  int *ptr1;
  int *ptr2;
}ques;
int main()
{
    int n1;
    printf("ENTER THE NUMBER OF ELEMENTS IN ARRAY ");
    scanf("%d",&n1);
    int arr1[n1];
    int arr2[n1];
    ques.ptr1=&arr1[0];
    ques.ptr2=&arr2[0];
    printf("ENTER THE ELEMENTS OF ARRAY 1");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",ques.ptr1+i);
    }
    for(int i=0;i<n1;i++)
    {
        *(ques.ptr2+i)=*(ques.ptr1+i);
    }
    for(int i=0;i<n1;i++)
    {
        if(i%2==1)
        {
            if (i > 0 && i < n1 - 1)
            {
                arr2[i] = *(ques.ptr2 + i - 1) * *(ques.ptr2 + i + 1);
            }
        }
    }
    for(int i=0;i<n1;i++)
    {
        printf("%d ",*(ques.ptr2+i));
    }


}