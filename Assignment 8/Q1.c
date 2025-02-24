#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node* front = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int data, int priority) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;
    
    if (isEmpty() || front->priority > priority) {
        new_node->next = front;
        front = new_node;
    } else {
        Node* temp = front;
        while (temp->next && temp->next->priority <= priority) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int removed_data = front->data;
    Node* temp = front;
    front = front->next;
    free(temp);
    return removed_data;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

int isFull() {
    return 0;
}

void display() {
    Node* temp = front;
    while (temp) {
        printf("(%d, %d) -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, priority;
    
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &data, &priority);
                enqueue(data, priority);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue());
                break;
            case 3:
                printf("Peek: %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}