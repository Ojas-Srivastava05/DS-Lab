#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct Queue
{
    int items[MAX];
    int front;
    int rear;
}Queue;

void Enqueue(Queue*q,int data)
{
    if(isFull(q))
    {
        printf("The queue is full");
        return ;
    }
    q->items[++(q->rear)]=data;
}