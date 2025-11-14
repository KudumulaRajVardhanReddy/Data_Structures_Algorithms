#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class Stack {
    Node** arr;
    int topIndex;
    int capacity;

    public:
    Stack(int capacity = 1000) {
        this->capacity = capacity;
        arr = new Node*[capacity];
        topIndex = -1;
    }

    bool isEmpty() { return topIndex == -1; }
    bool isFull() { return topIndex == capacity-1; }
    void push(Node* x) { if (!isFull()) arr[++topIndex] = x; }
    Node* pop() { return isEmpty()? nullptr : arr[topIndex--]; }
    Node* peek() { return isEmpty()? nullptr : arr[topIndex]; }
    ~Stack() { delete[] arr; }
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

    void preOrderTraversal(Node * root) {
        if (!root) return;
        Stack s;
        s.push(root);
        while (!s.isEmpty()) {
            Node* curr = s.pop();
            cout << curr->data << " ";
            if (curr->right) s.push(curr->right);
            if (curr->left) s.push(curr->left);  
        }
    }

    void inOrderTraversal(Node* root) {
        Stack s;
        Node* curr = root;
        while (curr || !s.isEmpty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }

    void postOrderTraversal(Node* root) {
        if (!root) return;
        Stack s1, s2;
        s1.push(root);
        while (!s1.isEmpty()) {
            Node* curr = s1.pop();
            s2.push(curr);
            if (curr->left) s1.push(curr->left);
            if (curr->right) s1.push(curr->right); 
        }
        while (!s2.isEmpty()) cout << s2.pop()->data << " ";
    }
};

int main() {
    BinaryTree bt;

    bt.root = bt.create();

    cout << "Iterative Preorder: ";
    bt.preOrderTraversal(bt.root);
    cout << "\nIterative Inorder: ";
    bt.inOrderTraversal(bt.root);
    cout << "\nIterative Postorder: ";
    bt.postOrderTraversal(bt.root);
    cout << "\n";
    return 0;
}