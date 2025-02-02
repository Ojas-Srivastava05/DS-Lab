#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int loopcheck(*ptr)
{
    
}
void main()
{
    int arr[10];
    printf("Enter the elements of the array ");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    struct Node *first=(struct Node*)malloc(sizeof(struct Node));
    struct Node *second=(struct Node*)malloc(sizeof(struct Node));
    struct Node *third=(struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth=(struct Node*)malloc(sizeof(struct Node));
    struct Node *fifth=(struct Node*)malloc(sizeof(struct Node));
    struct Node *sixth=(struct Node*)malloc(sizeof(struct Node));
    struct Node *seventh=(struct Node*)malloc(sizeof(struct Node));
    struct Node *eighth=(struct Node*)malloc(sizeof(struct Node));
    struct Node *ninth=(struct Node*)malloc(sizeof(struct Node));
    head->data=arr[0];
    head->next=first;
    first->data=arr[1];
    first->next=second;
    second->data=arr[2];
    second->next=third;
    third->data=arr[3];
    third->next=fourth;
    fourth->data=arr[4];
    fourth->next=fifth;
    fifth->data=arr[5];
    fifth->next=sixth;
    sixth->data=arr[6];
    sixth->next=seventh;
    seventh->data=arr[7];
    seventh->next=eighth;
    eighth->data=arr[8];
    eighth->next=ninth;
    ninth->data=arr[9];
    ninth->next=NULL;
    loopcheck(head);
}