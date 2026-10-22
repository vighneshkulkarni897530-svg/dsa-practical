
#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue
{
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue()
    {
        front = rear = -1;
    }

    // Insert element
    void enqueue(int value)
    {
        // Check queue overflow
        if ((rear + 1) % SIZE == front)
        {
            cout << "Queue is Full\n";
            return;
        }

        // First insertion
        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        arr[rear] = value;
    }

    // Delete element
    void dequeue()
    {
        // Check queue underflow
        if (front == -1)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        // Reset if queue becomes empty
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    // Display queue elements
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue: ";

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q;

    // Insert elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    // Delete one element
    q.dequeue();
    q.display();

    // Insert more elements
    q.enqueue(50);
    q.enqueue(60);
    q.display();

    return 0;
}
