#include <bits/stdc++.h>
using namespace std;

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

Node* convertVecToHead(vector<int> &arr) {
    Node* referenceNode = new Node(arr[0]), * traversalNode = referenceNode, *newNode{nullptr};
    for (int i{1}; i < arr.size(); i++) {
        newNode = new Node(arr[i]);
        traversalNode->next = newNode;
        traversalNode = traversalNode->next;
    }
    newNode->next = referenceNode;
    return referenceNode;
}

void displayAll(Node* referenceNode) {
    cout << referenceNode->data << endl;
    Node* traversalNode = referenceNode->next;
    while(traversalNode != referenceNode) {
        cout << traversalNode->data << endl;
        traversalNode = traversalNode->next;
    }
}

Node* deleteKthElement(Node* refNode, int value) {
    if (!refNode) return nullptr;
    if (refNode->data == value) {
        Node* prevNode{refNode->next};
        while(prevNode->next != refNode) {
            prevNode = prevNode->next;
        }
        prevNode->next = refNode->next;
        Node* newRefNode = refNode;
        refNode = refNode->next;
        delete(newRefNode);
        return refNode;
    }
    Node* traversalNode = refNode, * prevNode{nullptr};
    while(traversalNode->data != value) {
        prevNode = traversalNode;
        traversalNode = traversalNode->next;
        if (traversalNode == refNode) return refNode;
    }
    prevNode->next = traversalNode->next;
    delete(traversalNode);
    return refNode;
}

Node* insertBeforeKthElement(Node* referenceNode, int insert_value, int value) {
    return referenceNode;
}

int main() {
    vector<int> arr = {12,325,79,432,7,23,90,13};
    Node* referenceNode = convertVecToHead(arr);
    displayAll(referenceNode);
    cout << endl;
    referenceNode = deleteKthElement(referenceNode, 79);
    displayAll(referenceNode);
}
