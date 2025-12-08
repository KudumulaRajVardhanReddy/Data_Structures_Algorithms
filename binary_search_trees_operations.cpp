#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* right, * left;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class BST {
    public:
    Node* rootBST;

    BST() {
        rootBST = nullptr;
    }

    Node* insert(Node* rootBST, int key) {
         if (!rootBST) return new Node(key);

         if (key < rootBST->data) rootBST->left = insert(rootBST->left, key);
         else if (key > rootBST->data) rootBST->right = insert(rootBST->right, key);

         return rootBST;
    }

    bool search(Node* rootBST, int key) {
        if (!rootBST) return false;
        if (rootBST->data == key) return true;
        if (rootBST->data > key) return search(rootBST->left, key);
        return search(rootBST->right, key);
    }

    int minKey(Node* rootBST) {
        if (!rootBST) return -1;
        while (rootBST->left) rootBST = rootBST->left;
        return rootBST->data;
    }

    int maxKey(Node* rootBST) {
        if (!rootBST) return -1;
        while(rootBST->right) rootBST = rootBST->right;
        return rootBST->data;
    }  

    Node* deleteNode(Node* rootBST, int key) {
        if (!rootBST) return nullptr;

        if (key < rootBST->data) rootBST->left = deleteNode(rootBST->left, key);
        if (key > rootBST->data) rootBST->right = deleteNode(rootBST->right, key);
        else {
            if (!rootBST->left && !rootBST->right) {
                delete rootBST;
                return nullptr;
            }
            if (!rootBST->left) {
                Node* temp = rootBST->right;
                delete rootBST;
                return temp;
            }
            if (!rootBST->right) {
                Node* temp = rootBST->left;
                delete rootBST;
                return temp;
            }
            int miniSuccessorToRight = minKey(rootBST->right);
            rootBST->data = miniSuccessorToRight;
            rootBST->right = deleteNode(rootBST->right, miniSuccessorToRight);
        }
        return rootBST;
    }

    void inorderTraversal(Node* rootBST) {
        if (!rootBST) return;
        inorderTraversal(rootBST->left);
        cout << rootBST->data << " ";
        inorderTraversal(rootBST->right);
    }

    void preorderTraversal(Node* rootBST) {
        if (!rootBST) return;
        cout << rootBST->data << endl;
        preorderTraversal(rootBST->left);
        preorderTraversal(rootBST->right);
    }

    void postorderTraversal(Node* rootBST) {
        if (!rootBST) return;
        postorderTraversal(rootBST->left);
        postorderTraversal(rootBST->right);
        cout << rootBST->data << endl;
    }
}; 

int main() {
    BST b;

    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    for (int x: arr) b.rootBST = b.insert(b.rootBST, x);

    cout << "Inorder : ";
    b.inorderTraversal(b.rootBST);

    cout << "Preorder : ";
    b.preorderTraversal(b.rootBST);

    cout << "Postorder : ";
    b.postorderTraversal(b.rootBST);

    cout << "\nMin :" << b.minKey(b.rootBST);
    cout << "\nMax :" << b.maxKey(b.rootBST);

    cout << "\nSearch 40: " << (b.search(b.rootBST, 40) ? "Found" : "Not Found");
    cout << "\nSearch 99: " << (b.search(b.rootBST, 99) ? "Found" : "Not Found");

    cout << "Inorder after delete: ";
    b.inorderTraversal(b.rootBST);
    cout << "\n";

    return 0;
}
