#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

int isFull(void) {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int isEmpty(void) {
    return (front == -1);
}

// a) Front Insertion
void insertFront(int key) {
    if (isFull()) {
        printf("Overflow: Deque is full. Cannot insert %d at front.\n", key);
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX - 1; // Wrap around to the end
    } else {
        front = front - 1;
    }
    deque[front] = key;
    printf("Inserted %d at front.\n", key);
}

// b) Rear Insertion
void insertRear(int key) {
    if (isFull()) {
        printf("Overflow: Deque is full. Cannot insert %d at rear.\n", key);
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0; // Wrap around to the start
    } else {
        rear = rear + 1;
    }
    deque[rear] = key;
    printf("Inserted %d at rear.\n", key);
}

// c) Front Deletion
void deleteFront(void) {
    if (isEmpty()) {
        printf("Underflow: Deque is empty.\n");
        return;
    }
    printf("Deleted %d from front.\n", deque[front]);

    if (front == rear) { // Only one element was in the deque
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front = front + 1;
    }
}

// d) Rear Deletion
void deleteRear(void) {
    if (isEmpty()) {
        printf("Underflow: Deque is empty.\n");
        return;
    }
    printf("Deleted %d from rear.\n", deque[rear]);

    if (front == rear) { // Only one element was in the deque
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear = rear - 1;
    }
}

void display(void) {
    if (isEmpty()) {
        printf("Deque: [] (Empty)\n");
        return;
    }
    printf("Deque (front -> rear): [ ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("]\n");
}

int main(void) {
    insertRear(10);   // [ 10 ]
    insertRear(20);   // [ 10 20 ]
    insertFront(5);   // [ 5 10 20 ]
    insertFront(2);   // [ 2 5 10 20 ]
    display();

    deleteFront();    // Removes 2 -> [ 5 10 20 ]
    deleteRear();     // Removes 20 -> [ 5 10 ]
    display();

    return 0;
}