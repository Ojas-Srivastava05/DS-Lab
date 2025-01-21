#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void main()
{
    int arr[4];
    for (int i = 0; i < 4; i++)
    {
        printf("ENTER THE %d ELEMENTS OUT OF %d ELEMENTS ", i+1, 4);
        scanf("%d", &arr[i]);
    }
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    head->data=arr[0];
    head->next=first;
    first->data =arr[1];
    first->next = second;
    second->data = arr[2];
    second->next =third;
    third->data = arr[3];
    third->next = NULL;
    struct Node *p=head;
    while(p!=NULL)
    {
        printf("%d \n",p->data);
        p=p->next;
    }
}