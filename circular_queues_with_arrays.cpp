#include <bits/stdc++.h>
using namespace std;

class CircularQueueWithArrays {
    int size;
    int* arr;
    int front, rear;

    public:
    CircularQueueWithArrays(int size) {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty() { return front == -1; }
    bool isFull() { return front == 0 && rear == size-1 || rear+1 == front; }

    void enqueue(int value) {
        if (isFull()) return;
        if (isEmpty()) front = 0;
        rear = (rear + 1)%size;
        arr[rear] = value;
        cout << "Enqueued " << arr[rear] << "." << endl;
    }

    void dequeue() {
        if (isEmpty()) return;
        if (rear == front) {rear = front = -1; return; }
        cout << "Dequeued " << arr[front] << "." << endl;
        front = (front + 1)%size;
    }

    void peek() {
        if (isEmpty()) return;
        cout << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) return;
        int i = front;
        while (true) {
            cout << arr[i];
            if (i == rear) break;
            cout << " ";
            i = (i+1)%size;
        }
        cout << "\n";
    }

    ~CircularQueueWithArrays() { delete []arr; }
};

int main() {
    CircularQueueWithArrays q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.display();
    q.peek();
    return 0;
}