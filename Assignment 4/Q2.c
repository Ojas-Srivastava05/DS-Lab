#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


void removeDuplicates(struct Node* head) {
    struct Node *current = head, *runner, *prev;

    while (current != NULL) {
        prev = current;
        runner = current->next;

        while (runner != NULL) {
            if (runner->data == current->data) {
                
                prev->next = runner->next;
                free(runner);
                runner = prev->next;  
            } else {
                prev = runner;
                runner = runner->next;
            }
        }
        current = current->next;
    }
}


int main() {
   
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(10);
    head->next->next->next = createNode(30);
    head->next->next->next->next = createNode(20);

    printf("Original linked list:\n");
    printList(head);

    removeDuplicates(head);

    printf("Linked list after removing duplicates:\n");
    printList(head);

    
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
