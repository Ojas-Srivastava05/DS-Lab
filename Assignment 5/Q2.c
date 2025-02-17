#include <stdio.h>
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
        printf("Stack overflow! Cannot push %d.\n", value);
        return;
    }
    s->stArr[++(s->top)] = value;
    printf("Pushed %d onto the stack.\n", value);
}

int pop(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    }
    int value = s->stArr[(s->top)--];
    printf("Popped %d from the stack.\n", value);
    return value;
}

int peek(STACK *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No top element.\n");
        return -1;
    }
    return s->stArr[s->top];
}

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
    pop(&s);  
    
    return 0;
}
