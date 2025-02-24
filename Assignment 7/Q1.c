#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char *expr) {
    int i, val1, val2;

    for (i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');
        } else {
            val2 = pop();
            val1 = pop();

            switch (expr[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main() {
    char expression[MAX];
    scanf("%s", expression);
    printf("%d\n", evaluatePostfix(expression));
    return 0;
}