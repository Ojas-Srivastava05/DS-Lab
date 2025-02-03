//removal of duplicates
#include<stdlib.h>
#include<stdio.h>
struct Node{
    int data;
    struct Node* next;
};
int duplicate(struct Node* ptr,struct Node* ptr1)
{
    for(int i=0;i<8;i++)
    {
       
        for(int j=i+1;j<8;j++)
        {
            ptr1=ptr1->next;
            if(ptr->data==ptr1->data)
            {
                ptr=ptr->next;
            }
            else
            {
                printf("%d \n",ptr->data);
                ptr=ptr->next;
            }
        }
        ptr = ptr->next;
    }
}
void main()
{
    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *sixth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *seventh = (struct Node *)malloc(sizeof(struct Node));
    head->data=10;
    head->next=first;
    first->data=20;
    first->next=second;
    second->data=30;
    second->next=third;
    third->data=40;
    third->next=fourth;
    fourth->data=50;
    fourth->next=fifth;
    fifth->data=60;
    fifth->next=sixth;
    sixth->data=60;
    sixth->next=seventh;
    seventh->data=30;
    seventh->next=NULL;

    duplicate(head,first);
}
