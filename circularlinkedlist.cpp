
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int bookID;
    string title;
    string author;
    Node *next;

    Node(int id, string t, string a) {
        bookID = id;
        title = t;
        author = a;
        next = NULL;
    }
};

class CircularLinkedList {
private:
    Node *head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    // Check for duplicate Book ID
    bool isDuplicate(int id) {
        if (head == NULL)
            return false;

        Node *temp = head;

        do {
            if (temp->bookID == id)
                return true;

            temp = temp->next;
        } while (temp != head);

        return false;
    }

    // Insert in descending order
    void insertBook(int id, string title, string author) {
        if (isDuplicate(id)) {
            cout << "\nDuplicate Book ID not allowed.\n";
            return;
        }

        Node *newNode = new Node(id, title, author);

        // Empty list
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            cout << "\nBook Record Inserted Successfully.\n";
            return;
        }

        // Insert before head
        if (id > head->bookID) {
            Node *last = head;

            while (last->next != head)
                last = last->next;

            newNode->next = head;
            last->next = newNode;
            head = newNode;

            cout << "\nBook Record Inserted Successfully.\n";
            return;
        }

        // Insert in middle or at end
        Node *current = head;

        while (current->next != head &&
               current->next->bookID > id) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        cout << "\nBook Record Inserted Successfully.\n";
    }

    // Display Records
    void display() {
        if (head == NULL) {
            cout << "\nLibrary is Empty.\n";
            return;
        }

        Node *temp = head;

        cout << "\n========== Library Records ==========\n";

        do {
            cout << "Book ID : " << temp->bookID << endl;
            cout << "Title   : " << temp->title << endl;
            cout << "Author  : " << temp->author << endl;
            cout << "-------------------------------------\n";

            temp = temp->next;
        } while (temp != head);
    }

    // Free memory
    ~CircularLinkedList() {
        if (head == NULL)
            return;

        Node *current = head->next;

        while (current != head) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }

        delete head;
        head = NULL;
    }
};

int main() {
    CircularLinkedList library;

    int choice, id;
    string title, author;

    do {
        cout << "\n===== Library Menu =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Exit";
        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID : ";
            cin >> id;

            cin.ignore(10000, '\n');

            cout << "Enter Book Title : ";
            getline(cin, title);

            cout << "Enter Author Name : ";
            getline(cin, author);

            library.insertBook(id, title, author);
            break;

        case 2:
            library.display();
            break;

        case 3:
            cout << "\nProgram Terminated.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 3);

    return 0;
}
