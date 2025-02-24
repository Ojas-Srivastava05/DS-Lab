#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularQueue {
    Node* rear;
} CircularQueue;

CircularQueue* createQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->rear = NULL;
    return queue;
}

int isEmpty(CircularQueue* queue) {
    return queue->rear == NULL;
}

void enqueue(CircularQueue* queue, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (isEmpty(queue)) {
        queue->rear = new_node;
        queue->rear->next = queue->rear;
    } else {
        new_node->next = queue->rear->next;
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int removed_data;
    if (queue->rear->next == queue->rear) {
        removed_data = queue->rear->data;
        free(queue->rear);
        queue->rear = NULL;
    } else {
        Node* temp = queue->rear->next;
        removed_data = temp->data;
        queue->rear->next = temp->next;
        free(temp);
    }
    return removed_data;
}

int peek(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->rear->next->data;
}

int isFull(CircularQueue* queue) {
    return 0;
}

void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = queue->rear->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != queue->rear->next);
    printf("\n");
}

int main() {
    CircularQueue* cq = createQueue();
    int choice, value;
    
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(cq, value);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue(cq));
                break;
            case 3:
                printf("Peek: %d\n", peek(cq));
                break;
            case 4:
                display(cq);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}