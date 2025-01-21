#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
int printNode(struct Node*ptr)
{
    while(ptr!=NULL)
    {
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }
}
int InsertNodeAtBeginning(struct Node *head,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(int));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
int main()
{
    struct Node *first=(struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    first->data=10;
    first->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=NULL;

    first=InsertNodeAtBeginning(first,69);
    printNode(first);
    
}