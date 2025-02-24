#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
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
    int i = 0, val1, val2, num;
    char ch;
    
    while (expr[i] != '\0') {
        while (expr[i] == ' ') i++;  // Skip spaces
        
        if (isdigit(expr[i]) || (expr[i] == '-' && isdigit(expr[i + 1]))) {
            num = 0;
            int sign = 1;
            
            if (expr[i] == '-') {
                sign = -1;
                i++;
            }
            
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            push(num * sign);
        } else {
            ch = expr[i];
            i++;
            
            val2 = pop();
            val1 = pop();
            
            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    push(val1 / val2); 
                    break;
                default: 
                    printf("Invalid operator: %c\n", ch); 
                    exit(1);
            }
        }
    }
    return pop();
}

int main() {
    char expression[MAX];
    int i = 0;
    char c;
    
    while ((c = getchar()) != '\n' && i < MAX - 1) {
        expression[i++] = c;
    }
    expression[i] = '\0';
    
    printf("%d\n", evaluatePostfix(expression));
    return 0;
}