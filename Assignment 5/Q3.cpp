#include <iostream>
#define MAXSIZE 100

using namespace std;

// Stack using Array
struct stack {
    int stArr[MAXSIZE];
    int top;
};
typedef struct stack STACK;

// Function to create a stack
void create(STACK &s) {
    s.top = -1;
}

// Function to check if the stack is full
bool isFull(STACK &s) {
    return s.top == MAXSIZE - 1;
}

// Function to check if the stack is empty
bool isEmpty(STACK &s) {
    return s.top == -1;
}

// Function to push an element onto the stack
void push(STACK &s, int value) {
    if (isFull(s)) {
        cout << "Stack is full!" << endl;
        return;
    }
    s.stArr[++s.top] = value;
}

// Function to pop an element from the stack
int pop(STACK &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return s.stArr[s.top--];
}

// Function to get the top element
int peek(STACK &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return s.stArr[s.top];
}

// Stack using Linked List
struct Node {
    int data;
    Node* next;
};

struct LinkedStack {
    Node* top;
};

// Function to create a stack
void create(LinkedStack &s) {
    s.top = nullptr;
}

// Function to check if the stack is empty
bool isEmpty(LinkedStack &s) {
    return s.top == nullptr;
}

// Function to push an element onto the stack
void push(LinkedStack &s, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = s.top;
    s.top = newNode;
}

// Function to pop an element from the stack
int pop(LinkedStack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    Node* temp = s.top;
    int poppedValue = temp->data;
    s.top = s.top->next;
    delete temp;
    return poppedValue;
}

// Function to get the top element
int peek(LinkedStack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return s.top->data;
}

int main() {
    // Stack using Array
    STACK s1;
    create(s1);
    push(s1, 10);
    push(s1, 20);
    cout << "Top element (Array Stack): " << peek(s1) << endl;
    cout << "Popped element (Array Stack): " << pop(s1) << endl;

    // Stack using Linked List
    LinkedStack s2;
    create(s2);
    push(s2, 30);
    push(s2, 40);
    cout << "Top element (Linked List Stack): " << peek(s2) << endl;
    cout << "Popped element (Linked List Stack): " << pop(s2) << endl;

    return 0;
}
