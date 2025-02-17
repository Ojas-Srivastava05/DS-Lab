#include <iostream>
#define MAXSIZE 100

using namespace std;


struct stack {
    int stArr[MAXSIZE];
    int top;
};
typedef struct stack STACK;


void create(STACK &s) {
    s.top = -1;
}


bool isFull(STACK &s) {
    return s.top == MAXSIZE - 1;
}


bool isEmpty(STACK &s) {
    return s.top == -1;
}


void push(STACK &s, int value) {
    if (isFull(s)) {
        cout << "Stack is full!" << endl;
        return;
    }
    s.stArr[++s.top] = value;
}


int pop(STACK &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return s.stArr[s.top--];
}


int peek(STACK &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return s.stArr[s.top];
}


struct Node {
    int data;
    Node* next;
};

struct LinkedStack {
    Node* top;
};


void create(LinkedStack &s) {
    s.top = nullptr;
}


bool isEmpty(LinkedStack &s) {
    return s.top == nullptr;
}


void push(LinkedStack &s, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = s.top;
    s.top = newNode;
}

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


int peek(LinkedStack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return s.top->data;
}

int main() {
    
    STACK s1;  
    create(s1);
    push(s1, 10);
    push(s1, 20);
    cout << "Top element (Array Stack): " << peek(s1) << endl;
    cout << "Popped element (Array Stack): " << pop(s1) << endl;

    
    LinkedStack s2;
    create(s2);
    push(s2, 30);
    push(s2, 40);
    cout << "Top element (Linked List Stack): " << peek(s2) << endl;
    cout << "Popped element (Linked List Stack): " << pop(s2) << endl;

    return 0;
}
