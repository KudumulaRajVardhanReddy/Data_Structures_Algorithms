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
    Node* root;

    public:
    BinaryTree() { root = nullptr; }

    Node* create() {
        int data; cin >> data;
        if (data == -1) return nullptr;
        Node* newNode = new Node(data);
        newNode->left = create();
        newNode->right = create();

        return newNode;
    }

    bool searchBT(Node* rootBT, int key) {
        if (!rootBT) return false;
        if (rootBT->data == key) return true;
        return searchBT(rootBT->left, key) || searchBT(root->right, key);
    }

    int countNodes(Node* rootBT) {
        if (!rootBT) return 0;
        return 1 + countNodes(rootBT->left) + countNodes(rootBT->right);
    }

    int countInternalNodes(Node* rootBT) {
        if (!rootBT) return 0;
        if (!rootBT->left || !rootBT->right) return 0;
        return 1 + countInternalNodes(rootBT->left) + countInternalNodes(rootBT->right);
    }

    int countLeaves(Node* rootBT) {
        if (!rootBT) return 0;
        return countNodes(rootBT) - countNodes(rootBT);
    }

    /* Method 2 for counting leaves
    
    int countLeaves(Node* rootBT) {
        if (!rootBT) return 0;
        return (!rootBT->left && !rootBT->right) return 1;
        return countLeaves(rootLeaves->left) + countLeaves(rootLeaves->right);
    }
    
    */

    

};



int main() {
    return 0;
}
