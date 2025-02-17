#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

struct stack {
    int stArr[MAXSIZE];
    int top;
};

typedef struct stack STACK;

void create(STACK *s) {
    s->top = -1;
}

bool isFull(STACK *s) {
    return s->top == MAXSIZE - 1;
}

bool isEmpty(STACK *s) {
    return s->top == -1;
}

void push(STACK *s, int value) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->stArr[++(s->top)] = value;
}

int pop(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->stArr[(s->top)--];
}

int peek(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->stArr[s->top];
}

struct Node {
    int data;
    struct Node* next;
};

struct LinkedStack {
    struct Node* top;
};

void createLinked(struct LinkedStack *s) {
    s->top = NULL;
}

bool isEmptyLinked(struct LinkedStack *s) {
    return s->top == NULL;
}

void pushLinked(struct LinkedStack *s, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int popLinked(struct LinkedStack *s) {
    if (isEmptyLinked(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    struct Node* temp = s->top;
    int poppedValue = temp->data;
    s->top = s->top->next;
    free(temp);
    return poppedValue;
}

int peekLinked(struct LinkedStack *s) {
    if (isEmptyLinked(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->top->data;
}

int main() {
    STACK s1;
    create(&s1);
    push(&s1, 10);
    push(&s1, 20);
    printf("Top element (Array Stack): %d\n", peek(&s1));
    printf("Popped element (Array Stack): %d\n", pop(&s1));

    struct LinkedStack s2;
    createLinked(&s2);
    pushLinked(&s2, 30);
    pushLinked(&s2, 40);
    printf("Top element (Linked List Stack): %d\n", peekLinked(&s2));
    printf("Popped element (Linked List Stack): %d\n", popLinked(&s2));
    
    return 0;
}
