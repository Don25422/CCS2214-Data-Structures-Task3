#include <iostream>
#define MAX 4
using namespace std;

class LinearQueue {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    LinearQueue() {
        front = -1;
        rear = -1;
    }

    // Enqueue: insert element at the rear
    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow! Cannot insert " << value << "\n";
            return;
        }
        if (front == -1) {
            front = 0; // First element being inserted
        }
        rear++;
        arr[rear] = value;
        cout << "Enqueued: " << value << "\n";
    }

    // Dequeue: remove element from the front
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! Queue is empty.\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << "\n";
        front++;

        // Reset pointers if the last element was just removed
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    // Display elements from front to rear
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Linear Queue (front -> rear): [ ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "]\n";
    }
};

int main() {
    LinearQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    q.dequeue();       // Removes 10 (index 0 is now wasted!)
    q.display();

    q.enqueue(50);     // Triggers Overflow because rear == MAX - 1
    return 0;
}