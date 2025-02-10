#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct stack{
    char data;
    struct stack*next;
};
void main()
{
    struct stack *A;
    char exp[100];
    printf("Enter the expression ");
    scanf("%s",exp);
    createstack(&A);
}

void createstack(struct stack **top)
{
    *top=NULL;
}

int postfix(char exp)
{
    struct stack *A;
    
}

void push(struct stack **top,int num)
{
    struct stack *new=(struct stack*)malloc(sizeof(struct stack));
    if(new==NULL)
    {
        printf("\n Stack is full");
        exit(-1);
    }



}

int pop(){

}

