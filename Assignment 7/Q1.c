#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char *expr) {
    int i, val1, val2;
    char *token = strtok(expr, " ");
    
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        } else {
            val2 = pop();
            val1 = pop();
            
            switch (token[0]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                default: printf("Invalid operator: %s\n", token); exit(1);
            }
        }
        token = strtok(NULL, " ");
    }
    return pop();
}

int main() {
    char expression[MAX];
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = 0;
    printf("%d\n", evaluatePostfix(expression));
    return 0;
}
