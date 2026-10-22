
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
    Node *head;

public:
    LinkedList() {
        head = NULL;
    }

    void createList(int n) {
        if (n < 0) {
            cout << "Invalid number of nodes\n";
            return;
        }

        int value;
        for (int i = 0; i < n; i++) {
            cout << "Enter value: ";
            cin >> value;
            insertEnd(value);
        }
    }

    void insertBeginning(int value) {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int value) {
        Node *newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void insertPosition(int pos, int value) {
        if (pos <= 0) {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1) {
            insertBeginning(value);
            return;
        }

        Node *temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Invalid Position\n";
            return;
        }

        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteBeginning() {
        if (head == NULL) {
            cout << "List Empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (head == NULL) {
            cout << "List Empty\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;

        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    void deletePosition(int pos) {
        if (head == NULL) {
            cout << "List Empty\n";
            return;
        }

        if (pos <= 0) {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1) {
            deleteBeginning();
            return;
        }

        Node *temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL || temp->next == NULL) {
            cout << "Invalid Position\n";
            return;
        }

        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void display() {
        Node *temp = head;

        if (head == NULL) {
            cout << "List Empty\n";
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void countNodes() {
        int count = 0;
        Node *temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        cout << "Total Nodes = " << count << endl;
    }

    // Free dynamically allocated nodes
    ~LinkedList() {
        while (head != NULL) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value, pos, n;

    do {
        cout << "\n1.Create List";
        cout << "\n2.Insert Beginning";
        cout << "\n3.Insert End";
        cout << "\n4.Insert Position";
        cout << "\n5.Delete Beginning";
        cout << "\n6.Delete End";
        cout << "\n7.Delete Position";
        cout << "\n8.Display";
        cout << "\n9.Count Nodes";
        cout << "\n0.Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Number of Nodes: ";
            cin >> n;
            list.createList(n);
            break;

        case 2:
            cout << "Enter Value: ";
            cin >> value;
            list.insertBeginning(value);
            break;

        case 3:
            cout << "Enter Value: ";
            cin >> value;
            list.insertEnd(value);
            break;

        case 4:
            cout << "Enter Position and Value: ";
            cin >> pos >> value;
            list.insertPosition(pos, value);
            break;

        case 5:
            list.deleteBeginning();
            break;

        case 6:
            list.deleteEnd();
            break;

        case 7:
            cout << "Enter Position: ";
            cin >> pos;
            list.deletePosition(pos);
            break;

        case 8:
            list.display();
            break;

        case 9:
            list.countNodes();
            break;

        case 0:
            cout << "Exiting Program\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 0);

    return 0;
}
