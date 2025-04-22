#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    int exp;
    struct Node* next;
}Node;

Node* createNode(int data,int exp)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->exp=exp;
    newNode->next=NULL;
    return newNode;
}

Node* createLL(int A[],int n,int B[])
{
    if(n==0)
    {
        return NULL;
    }
    Node* head=createNode(A[0],B[0]);
    Node* temp=head;
    for(int i=1;i<n;i++)
    {
        Node* newNode=createNode(A[i],B[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    return head;

}

Node* addition(Node* head1,Node* head2)
{
    Node* head3=(Node*)malloc(sizeof(Node));
    Node* temp3=head3;
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1->exp==temp2->exp)
        {
            temp3->next=createNode(temp1->data+temp2->data,temp1->exp);
            temp3=temp3->next;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1!=NULL)
    {
        temp3->next=createNode(temp1->data,temp1->exp);
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        temp3->next=createNode(temp2->data,temp2->exp);
        temp2=temp2->next;
    }
    return head3->next;
}
int main()
{
    int A1[]={1,2,3,4,5};
    int B1[]={1,2,3,4,5};
    int A2[]={5,6,7,8,9};
    int B2[]={1,2,3,4,5};
    Node* head1=createLL(A1,5,B1);
    Node* head2=createLL(A2,5,B2);
    Node* head3=addition(head1,head2);
    while(head3!=NULL)
    {
        printf("Data %d Exponent %d\n",head3->data,head3->exp);
        head3=head3->next;
    }
    return 0;
}