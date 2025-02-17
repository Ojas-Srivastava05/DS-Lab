#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct {
    struct Node* last;
} CircularLinkedList;

void init(CircularLinkedList* cll) {
    cll->last = NULL;
}

void insertAtPosition(CircularLinkedList* cll, int data, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (!cll->last) {
        if (pos == 1) {
            cll->last = newNode;
            cll->last->next = cll->last;
        } else {
            free(newNode);
        }
        return;
    }
    struct Node* temp = cll->last->next;
    struct Node* prev = NULL;
    int count = 1;
    do {
        if (count == pos) {
            newNode->next = temp;
            if (prev) {
                prev->next = newNode;
            } else {
                cll->last->next = newNode;
            }
            if (pos == 1) cll->last = newNode;
            return;
        }
        prev = temp;
        temp = temp->next;
        count++;
    } while (temp != cll->last->next);
    free(newNode);
}

void insertAtBeginning(CircularLinkedList* cll, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (!cll->last) {
        cll->last = newNode;
        cll->last->next = cll->last;
    } else {
        newNode->next = cll->last->next;
        cll->last->next = newNode;
    }
}

void insertAtEnd(CircularLinkedList* cll, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (!cll->last) {
        cll->last = newNode;
        cll->last->next = cll->last;
    } else {
        newNode->next = cll->last->next;
        cll->last->next = newNode;
        cll->last = newNode;
    }
}

void deleteAtPosition(CircularLinkedList* cll, int pos) {
    if (!cll->last) return;
    struct Node* temp = cll->last->next;
    struct Node* prev = NULL;
    int count = 1;
    do {
        if (count == pos) {
            if (prev) {
                prev->next = temp->next;
            } else {
                cll->last->next = temp->next;
            }
            if (temp == cll->last) cll->last = prev;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
        count++;
    } while (temp != cll->last->next);
}

void deleteFirst(CircularLinkedList* cll) {
    if (!cll->last) return;
    struct Node* temp = cll->last->next;
    if (temp == cll->last) {
        free(cll->last);
        cll->last = NULL;
    } else {
        cll->last->next = temp->next;
        free(temp);
    }
}

void deleteLast(CircularLinkedList* cll) {
    if (!cll->last) return;
    struct Node* temp = cll->last->next;
    struct Node* prev = NULL;
    while (temp->next != cll->last->next) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == cll->last) {
        free(cll->last);
        cll->last = NULL;
    } else {
        prev->next = cll->last->next;
        free(cll->last);
        cll->last = prev;
    }
}

void display(CircularLinkedList* cll) {
    if (!cll->last) return;
    struct Node* temp = cll->last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != cll->last->next);
    printf("(circular)\n");
}

int main() {
    CircularLinkedList cll;
    init(&cll);
    int choice, data, pos;
    do {
        printf("\nMenu:\n");
        printf("1. Insert at Position\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Position\n");
        printf("5. Delete First\n");
        printf("6. Delete Last\n");
        printf("7. Display List\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(&cll, data, pos);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&cll, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&cll, data);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(&cll, pos);
                break;
            case 5:
                deleteFirst(&cll);
                break;
            case 6:
                deleteLast(&cll);
                break;
            case 7:
                display(&cll);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
    return 0;
}
