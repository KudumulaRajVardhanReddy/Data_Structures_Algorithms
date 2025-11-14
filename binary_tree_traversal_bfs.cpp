#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left, * right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class Queue {
    Node** arr;
    int front, rear, capacity;
    public:
    Queue(int capacity = 1000) {
        this->capacity = capacity;
        arr = new Node*[capacity];
        front = 0;
        rear = -1;
    }

    bool isEmpty() { return rear < front; }
    bool isFull() { return rear = capacity - 1; }
    void enqueue(Node* x) { if (!isFull()) arr[++rear] = x; }
    Node* dequeue() { return isEmpty()? nullptr : arr[front++]; }
    ~Queue() { delete[] arr; }

};

class BinaryTree {
    public:
    Node* root;
    BinaryTree() { root = nullptr; }

    Node* create() {
        int data;
        cin >> data;
        if (data == -1) return nullptr;
        Node* newNode = new Node(data);
        newNode->left = create();
        newNode->right = create();
        return newNode;
    }

    void BFS(Node* rootOfTree) {
        if (!rootOfTree) return;
        Queue q;
        q.enqueue(rootOfTree);
        while(!q.isEmpty()) {
            Node* curr = q.dequeue();
            cout << curr->data << " ";
            if (curr->left) q.enqueue(curr->left);
            if (curr->right) q.enqueue(curr->right);
        }
    }
};

int main() {

    return 0;
}
