#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '#';
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '#';
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isRightAssociative(char c) {
    return c == '^';
}

int isValidParentheses(char *expr) {
    char tempStack[MAX];
    int tempTop = -1;
    
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            tempStack[++tempTop] = '(';
        } else if (expr[i] == ')') {
            if (tempTop == -1) return 0;
            tempTop--;
        }
    }
    return tempTop == -1;
}

void infixToPostfix(char *infix, char *postfix) {
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else {
            while (top != -1 && precedence(peek()) > precedence(infix[i])) {
                postfix[j++] = pop();
            }
            if (!isRightAssociative(infix[i])) {
                while (top != -1 && precedence(peek()) >= precedence(infix[i])) {
                    postfix[j++] = pop();
                }
            }
            push(infix[i]);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);

    if (!isValidParentheses(infix)) {
        printf("Error: Invalid parentheses!\n");
        return 1;
    }

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}