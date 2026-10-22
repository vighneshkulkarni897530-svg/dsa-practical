
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node *head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Create List (replaces existing list)
    void create() {
        int n, value;

        cout << "Enter number of nodes: ";
        cin >> n;

        if (n < 0) {
            cout << "Invalid number of nodes\n";
            return;
        }

        // Clear old list
        while (head != NULL) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        for (int i = 0; i < n; i++) {
            cout << "Enter data: ";
            cin >> value;

            Node *newNode = new Node(value);

            if (head == NULL) {
                head = newNode;
            } else {
                Node *temp = head;

                while (temp->next != NULL)
                    temp = temp->next;

                temp->next = newNode;
                newNode->prev = temp;
            }
        }
    }

    // Insert at Beginning
    void insertBeginning() {
        int value;
        cout << "Enter value: ";
        cin >> value;

        Node *newNode = new Node(value);

        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }

        head = newNode;
    }

    // Delete from End
    void deleteEnd() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;
    }

    // Forward Traversal
    void traverseForward() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node *temp = head;
        cout << "Forward: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Backward Traversal
    void traverseBackward() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        cout << "Backward: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }

    // Reverse List
    void reverse() {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node *current = head;
        Node *temp = NULL;

        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            current = current->prev;
        }

        if (temp != NULL)
            head = temp->prev;

        cout << "List Reversed Successfully.\n";
    }

    // Destructor
    ~DoublyLinkedList() {
        while (head != NULL) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    int choice;

    do {
        cout << "\n----- Doubly Linked List -----";
        cout << "\n1. Create";
        cout << "\n2. Insert at Beginning";
        cout << "\n3. Delete from End";
        cout << "\n4. Traverse Forward";
        cout << "\n5. Traverse Backward";
        cout << "\n6. Reverse";
        cout << "\n7. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            dll.create();
            break;

        case 2:
            dll.insertBeginning();
            break;

        case 3:
            dll.deleteEnd();
            break;

        case 4:
            dll.traverseForward();
            break;

        case 5:
            dll.traverseBackward();
            break;

        case 6:
            dll.reverse();
            break;

        case 7:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 7);

    return 0;
}
