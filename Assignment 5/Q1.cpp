#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last;
public:
    CircularLinkedList() : last(nullptr) {}

    // Insert at a specific position
    void insertAtPosition(int data, int pos) {
        Node* newNode = new Node{data, nullptr};
        if (!last) {
            if (pos == 1) {
                last = newNode;
                last->next = last;
            } else {
                cout << "Invalid position!" << endl;
                delete newNode;
            }
            return;
        }
        Node* temp = last->next;
        Node* prev = nullptr;
        int count = 1;
        do {
            if (count == pos) {
                newNode->next = temp;
                if (prev) {
                    prev->next = newNode;
                } else {
                    last->next = newNode;
                }
                if (pos == 1) last = newNode;
                return;
            }
            prev = temp;
            temp = temp->next;
            count++;
        } while (temp != last->next);
        cout << "Invalid position!" << endl;
        delete newNode;
    }

    // Insert at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node{data, nullptr};
        if (!last) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    // Insert at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node{data, nullptr};
        if (!last) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    // Delete from a specific position
    void deleteAtPosition(int pos) {
        if (!last) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = last->next;
        Node* prev = nullptr;
        int count = 1;
        do {
            if (count == pos) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    last->next = temp->next;
                }
                if (temp == last) last = prev;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
            count++;
        } while (temp != last->next);
        cout << "Invalid position!" << endl;
    }

    // Delete first element
    void deleteFirst() {
        if (!last) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = last->next;
        if (temp == last) {
            delete last;
            last = nullptr;
        } else {
            last->next = temp->next;
            delete temp;
        }
    }

    // Delete last element
    void deleteLast() {
        if (!last) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = last->next;
        Node* prev = nullptr;
        while (temp->next != last->next) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == last) {
            delete last;
            last = nullptr;
        } else {
            prev->next = last->next;
            delete last;
            last = prev;
        }
    }

    // Display the list
    void display() {
        if (!last) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = last->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "(circular)" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, data, pos;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Position\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at End\n";
        cout << "4. Delete at Position\n";
        cout << "5. Delete First\n";
        cout << "6. Delete Last\n";
        cout << "7. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data and position: ";
                cin >> data >> pos;
                cll.insertAtPosition(data, pos);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                cll.insertAtBeginning(data);
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data;
                cll.insertAtEnd(data);
                break;
            case 4:
                cout << "Enter position: ";
                cin >> pos;
                cll.deleteAtPosition(pos);
                break;
            case 5:
                cll.deleteFirst();
                break;
            case 6:
                cll.deleteLast();
                break;
            case 7:
                cll.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}
