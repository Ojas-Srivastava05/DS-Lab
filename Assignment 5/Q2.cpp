#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

struct stack {
    int stArr[MAXSIZE];
    int top;
};

typedef struct stack STACK;

// Function to create a stack
void create(STACK *s) {
    s->top = -1;
}

// Function to check if the stack is full
bool isFull(STACK *s) {
    return s->top == MAXSIZE - 1;
}

// Function to check if the stack is empty
bool isEmpty(STACK *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(STACK *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d.\n", value);
        return;
    }
    s->stArr[++(s->top)] = value;
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    }
    int value = s->stArr[(s->top)--];
    printf("Popped %d from the stack.\n", value);
    return value;
}

// Function to get the top element without removing it
int peek(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No top element.\n");
        return -1;
    }
    return s->stArr[s->top];
}

// Main function to test the stack operations
int main() {
    STACK s;
    create(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));

    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);  // Extra pop to show underflow case

    return 0;
}
