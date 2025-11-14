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

    void preOrderTraversal(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void inOrderTraversal(Node* root) {
        if (!root) return;
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    void postOrderTraversal(Node* root) {
        if (!root) return;
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
};

int main() {

    BinaryTree bt;
    cout << "Enter nodes (-1 for NULL) : \n";

    bt.root = bt.create();

    cout << "\nRecursive Traversals: \n";
    cout << "Preorder : ";
    bt.preOrderTraversal(bt.root);
    cout << "\n";
    cout << "Inorder : ";
    bt.inOrderTraversal(bt.root);
    cout << "\n";    cout << "PostOrder : ";
    bt.postOrderTraversal(bt.root);
    cout << "\n";

    return 0;
}
