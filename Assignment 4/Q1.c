//rotation by k steps
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int rotation(struct Node* ptr,int k)
{
    for(int i=0;i<k;i++)
    {
        ptr=ptr->next;
    }
    for(int i=0;i<11;i++)
    {
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }
}
void main()
{
    int k;
    printf("Enter the value you want to rotate the array by");
    scanf("%d",&k);
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first=(struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *sixth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *seventh = (struct Node *)malloc(sizeof(struct Node));
    struct Node *eighth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ninth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *tenth = (struct Node *)malloc(sizeof(struct Node));
    head->data=10;
    head->next=first;
    first->data = 20;
    first->next = second;
    second->data = 30;
    second->next = third;
    third->data = 40;
    third->next = fourth;
    fourth->data = 50;
    fourth->next = fifth;
    fifth->data = 60;
    fifth->next = sixth;
    sixth->data = 70;
    sixth->next = seventh;
    seventh->data = 80;
    seventh->next = eighth;
    eighth->data = 90;
    eighth->next = ninth;
    ninth->data = 100;
    ninth->next = tenth;
    tenth->data=110;
    tenth->next=head;
    struct Node *ptr1=head;
    printf("The nodes before rotation were");
    for (int i = 0; i < 11; i++)
    {
        printf("%d \n", ptr1->data);
        ptr1 = ptr1->next;
    }
    printf("-----------------------\n");
    rotation(head,k);

}