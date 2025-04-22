#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

Node* createLL(int A[],int n)
{
    if(n==0)
    {
        return NULL;
    }
    Node* head=createNode(A[0]);
    Node* temp=head;
    for(int i=1;i<n;i++)
    {
        Node* newNode=createNode(A[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    return head;

}

int leng(Node* head)
{
    Node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count; 
}

void main()
{
    int A[]={10,20,30,40,50};
    int n=5;
    Node* head=createLL(A,n);
    int result=leng(head);
    printf("%d ",result);
}