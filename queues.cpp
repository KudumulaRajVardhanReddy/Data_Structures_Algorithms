#include <bits/stdc++.h>
using namespace std;

class QueuesWithArrays {
    int arr[10];
    int rear = -1, front = -1;

    public:
    bool isEmpty() { return front == -1;}
    bool isFull() { return rear == 9; }

    void enqueue(int value) {
        if (isEmpty()) {
            rear++;
            front++;
            arr[front] = value;
            cout << "Pushed " << arr[front] << ". It's first element in Queue." << endl;
            return;
        }
        if (isFull()) {
            cout << "Queue is Full." << endl;
            return;
        }
        rear++;
        arr[rear] = value;
        cout << "Pushed " << arr[rear]  << "." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
            return;
        }
        cout << arr[front] << " removed." << endl;
        front++;

        if (front > rear) front = rear = -1;
    }

    void firstElement() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
            return;
        }
        cout << arr[front] << " is the first element." << endl;
        return;
    }

    void lastElement() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
            return;
        }
        cout << arr[rear] << " is the last element." << endl;
    }

    void size() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << rear-front+1 << " is the size." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) cout << arr[i] << " " << endl;
        cout << endl;
    }
};

class Node {
    public:
    int data;
    Node* next;

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class QueuesWithLLs {
    Node* start = nullptr, * end = nullptr; int counter{0};

    public:
    bool isEmpty() { return start == nullptr; }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            start = end = newNode;
            counter++;
            return;
        }
        end->next = newNode;
        end = newNode;
        counter++;
        cout << value << " added to Queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Removed " << start->data << " from Queue." << endl;
        Node* newNode = start;
        start = start->next;
        free(newNode);
    }
    
    void firstElement() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << start->data << endl;
    }
    
    void lastElement() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << end->data << endl;
    }

    void size() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << counter << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* traverseNode = start;
        while (traverseNode != nullptr) {
            cout << traverseNode->data << endl;
            traverseNode = traverseNode->next;
        }
    }
};

int main() {
    QueuesWithArrays q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.firstElement();
    q.lastElement();
    q.size();
    q.dequeue();
    q.display();
    q.size();

    cout << endl;

    QueuesWithLLs qll;
    qll.enqueue(10);
    qll.enqueue(20);
    qll.enqueue(30);
    qll.display();
    qll.firstElement();
    qll.lastElement();
    qll.size();
    qll.dequeue();
    qll.display();
    qll.size();

    return 0;
}
