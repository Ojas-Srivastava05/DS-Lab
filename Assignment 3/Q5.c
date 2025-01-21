#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int convertoarray(struct Node* ptr)
{
    int arr[4],i=0;
    while(ptr!=NULL)
    {
        arr[i]=ptr->data;
        printf("%d \n",arr[i]);
        ptr=ptr->next;
        i++;
    }
}
void main()
{
    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    head->data=10;
    head->next=first;
    first->data=20;
    first->next=second;
    second->data=30;
    second->next=third;
    third->data=40;
    third->next=NULL;
    convertoarray(head);

}