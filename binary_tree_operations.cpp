#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
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

    // search
    bool search(Node* rootBT, int key) {
        if (!rootBT) return false;
        if (rootBT->data == key) return true;
        return search(rootBT->left, key) || search(rootBT->right, key);
    }

    // count total nodes
    int countNodes(Node* rootBT) {
        if (!rootBT) return 0;
        return 1 + countNodes(rootBT->left) + countNodes(rootBT->right);
    }

    // count leaf nodes (direct)
    int countLeaves(Node* rootBT) {
        if (!rootBT) return 0;
        if (!rootBT->left && !rootBT->right) return 1;
        return countLeaves(rootBT->left) + countLeaves(rootBT->right);
    }

    // count internal nodes (nodes with at least one child)
    int countInternalNodes(Node* rootBT) {
        if (!rootBT) return 0;
        if (!rootBT->left && !rootBT->right) return 0; // leaf
        return 1 + countInternalNodes(rootBT->left) + countInternalNodes(rootBT->right);
    }

    // height
    int height(Node* rootBT) {
        if (!rootBT) return 0;
        int lh = height(rootBT->left);
        int rh = height(rootBT->right);
        return 1 + (lh > rh ? lh : rh);
    }

    // mirror (in-place)
    Node* mirror(Node* rootBT) {
        if (!rootBT) return nullptr;
        Node* leftMirror = mirror(rootBT->left);
        Node* rightMirror = mirror(rootBT->right);
        rootBT->left = rightMirror;
        rootBT->right = leftMirror;
        return rootBT;
    }

    // deep copy
    Node* copyTree(Node* rootBT) {
        if (!rootBT) return nullptr;
        Node* newNode = new Node(rootBT->data);
        newNode->left = copyTree(rootBT->left);
        newNode->right = copyTree(rootBT->right);
        return newNode;
    }

    // delete entire tree and set caller pointer to nullptr
    void deleteTree(Node*& rootBT) {
        if (!rootBT) return;
        deleteTree(rootBT->left);
        deleteTree(rootBT->right);
        delete rootBT;
        rootBT = nullptr;
    }

    // level order (simple queue inside)
    class Queue {
        Node** arr;
        int front, rear, cap;
    public:
        Queue(int c = 1000) {
            cap = c;
            arr = new Node*[cap];
            front = 0; rear = -1;
        }
        bool isEmpty() { return rear < front; }
        void enqueue(Node* x) { arr[++rear] = x; }
        Node* dequeue() { return arr[front++]; }
        ~Queue() { delete[] arr; }
    };

    void levelOrderTraversal(Node* rootBT) {
        if (!rootBT) return;
        Queue q;
        q.enqueue(rootBT);
        while (!q.isEmpty()) {
            Node* curr = q.dequeue();
            cout << curr->data << " ";
            if (curr->left) q.enqueue(curr->left);
            if (curr->right) q.enqueue(curr->right);
        }
    }
};

int main() {
    BinaryTree bt;
    cout << "Enter tree (-1 for NULL):\n";
    bt.root = bt.create();

    cout << "\nSearch 5: " << (bt.search(bt.root, 5) ? "Found" : "Not Found") << "\n";
    cout << "Total nodes: " << bt.countNodes(bt.root) << "\n";
    cout << "Leaf nodes: " << bt.countLeaves(bt.root) << "\n";
    cout << "Internal nodes: " << bt.countInternalNodes(bt.root) << "\n";
    cout << "Height: " << bt.height(bt.root) << "\n";

    cout << "\nLevel Order: ";
    bt.levelOrderTraversal(bt.root);
    cout << "\n";

    Node* copy = bt.copyTree(bt.root);
    cout << "Copy Level Order: ";
    bt.levelOrderTraversal(copy);
    cout << "\n";

    bt.mirror(bt.root);
    cout << "Mirror Level Order: ";
    bt.levelOrderTraversal(bt.root);
    cout << "\n";

    bt.deleteTree(bt.root);         // sets bt.root = nullptr
    bt.deleteTree(copy);            // delete the copy as well
    cout << "\nTree Deleted.\n";

    return 0;
}
