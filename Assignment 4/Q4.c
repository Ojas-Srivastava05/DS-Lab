#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtFirst(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    new_node->next = *head_ref;
    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
    display(*head_ref);
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        display(*head_ref);
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
    display(*head_ref);
}

void insertAtMiddle(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* slow = *head_ref;
    struct Node* fast = *head_ref;
    
    if (*head_ref == NULL) {
        *head_ref = new_node;
        display(*head_ref);
        return;
    }
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL) {
            slow = slow->next;
        }
    }
    
    new_node->next = slow;
    new_node->prev = slow->prev;
    if (slow->prev != NULL) {
        slow->prev->next = new_node;
    } else {
        *head_ref = new_node;
    }
    slow->prev = new_node;
    display(*head_ref);
}

void insertAfterNode(struct Node** head_ref, struct Node* given_node, int new_data) {
    if (given_node == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }
    struct Node* new_node = createNode(new_data);
    new_node->next = given_node->next;
    given_node->next = new_node;
    new_node->prev = given_node;
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
    display(*head_ref);
}

void display(struct Node* node) {
    struct Node* last = NULL;
    printf("Linked list: ");
    while (node != NULL) {
        printf("%d", node->data);
        last = node;
        node = node->next;
        if (node != NULL) {
            printf(" <-> ");
        }
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    insertAtFirst(&head, 5);
    insertAtEnd(&head, 60);
    insertAtMiddle(&head, 25);
    insertAfterNode(&head, head->next->next->next, 35); // Insert 35 after the node with data 30

    return 0;
}
