#include <iostream>
using namespace std;

class Node {
        public:
        int data, height;
        Node* left, * right;
        Node(int data) {
                this->data = data;
                left = right = nullptr;
                height = 1;
        }
};

int getHeight(Node* root) {
        if (!root) return 0;
        return root->height;
}

int getBalance(Node* root) {
        if (!root) return 0;
        return getHeight(root->left) - getHeight(root->right);
}

Node* rotateRight(Node* y) {
        Node* x = y->left, * z = x->right;
        x->right = y;
        y->left = z;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
}

Node* rotateLeft(Node* y) {
        Node* x = y->right, * z = x->left;
        x->left = y; y->right = z;

        y->height = 1+max(getHeight(y->left), getHeight(y->right));
        x->height = 1+ max(getHeight(x->left), getHeight(x->right));

        return x;
}

Node* insert(Node* root, int val) {
        if (!root) return new Node(val);

        if (val < root->data) root->left = insert(root->left, val);
        else if (val > root->data) root->right = insert(root->right, val);
        else return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);

        if (balance > 1 && val < root->left->data) return rotateRight(root);
        if (balance < -1 && val > root->right->data) return rotateLeft(root);

        if (balance > 1 && val > root->left->data) {
                root->left = rotateLeft(root->left);
                return rotateRight(root);
        }
        if (balance < -1 && val < root->right->data) {
                root->right = rotateRight(root->right);
                return rotateLeft(root);
        }

        return root;
}

Node* minVal(Node* root) {
        while (root->left) root = root->left;
        return root;
}

Node* remove(Node* root, int val) {
        if (!root) return root;
        if (val < root->data) root->left = remove(root->left, val);
        else if (val > root->data) root->right = remove(root->right, val);
        else {
                if (!root->left && !root->right) {
                        delete root;
                        return nullptr;
                }
                else if (!root->left && root->right) {
                        Node* temp = root;
                        root = root->right;
                        delete temp;
                }
                else if (root->left && !root->right) {
                        Node* temp = root;
                        root = root->left;
                        delete temp;
                }
                else {
                        Node* temp = minVal(root->right);
                        root->data = temp->data;
                        root->right = remove(root->right, temp->data);
                }
        }

        if (!root) return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0) return rotateRight(root);
        if (balance > 1 && getBalance(root->left) < 0) {
                root->left = rotateLeft(root->left);
                return rotateRight(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0) return rotateLeft(root);
        if (balance < -1 && getBalance(root->right) > 0) {
                root->right = rotateRight(root->right);
                return rotateLeft(root);
        }
        return root;
}

void inorderTraversal(Node* root) {
        if (!root) return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
}

int main() {

        Node* avl = new Node(32);
        avl = insert(avl, 42);
        avl = insert(avl, 23);
        avl = insert(avl, 59);
        avl = insert(avl, 73);
        avl = insert(avl, 45);
        inorderTraversal(avl);
        cout << endl;
        avl = remove(avl, 42);
        avl = remove(avl, 59);
        inorderTraversal(avl);
        cout << endl;
        return 0;
}
