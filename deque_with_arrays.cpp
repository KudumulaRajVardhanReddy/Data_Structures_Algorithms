#include <bits/stdc++.h>
using namespace std;

class DequeWithArrays {
    int* arr, size, front, rear;

    public:
    DequeWithArrays(int size) {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == size-1 || front == rear+1; }

    void insertFront(int value) {
        if (isFull()) return;
        if (isEmpty()) { front = rear = -1; }
        else if (front == 0) front = size -1;
        else front--;
        arr[front] = value;
    }

    void insertRear(int value) {
        if (isFull()) return;
        if (isEmpty()) { front = rear = 0; }
        else rear = (rear+1)%size;  
        arr[rear] = value;
    }

    void deleteFront() {
        if (isEmpty()) return;
        if (front == rear) front = rear = -1;
        else front = (front + 1)%size;
    }

    void deleteRear() {
        if (isEmpty()) return;
        if (front == rear) front = rear = -1;
        else if (rear == 0) rear = size - 1;
        else rear;
    }

    int getFront() { return isEmpty()? -1: arr[front]; }
    int getRear() { return isEmpty()? -1: arr[rear]; }

    void display() {
        if (isEmpty()) { cout << "Empty\n"; return; }
        int i = front;
        while (true) {
            cout << arr[i];
            if (i == rear) break;
            cout << " ";
            i = (i+1)%size;
        }
        cout << "\n";
    }
    ~DequeWithArrays() { delete []arr; }
};

int main() {
    DequeWithArrays dq(5);
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertRear(30);
    dq.display();
    dq.deleteFront();
    dq.display();
    dq.deleteRear();
    dq.display();
    dq.insertFront(99);
    dq.insertRear(77);
    dq.display();
    cout << "Front: " << dq.getFront() << " Rear: " << dq.getRear() << "\n";
}