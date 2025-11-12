#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next, * back;

        Node(int data, Node* next, Node* back) {
            this->data = data;
            this->next = next;
            this->back = back;
        }
        Node(int data) {
            this->data = data;
            next = nullptr;
            back = nullptr;
        }
};

Node* createCLL(vector<int> &arr) {
    Node* referenceNode = new Node(arr[0]);
    Node* newNode = nullptr, * prevNode = referenceNode;
    if (arr.size() == 1) {
        referenceNode->next = referenceNode;
        referenceNode->back = referenceNode;
        return referenceNode;
    }
    for (int i = 1; i < arr.size(); i++) {
        newNode = new Node(arr[i], nullptr, prevNode);
        prevNode->next = newNode;
        prevNode = newNode;
    }
    newNode->next = referenceNode;
    referenceNode->back = newNode;

    return referenceNode;
}

void displayAll(Node* referenceNode) {
    cout << referenceNode->data << endl;
    Node* traverseNode = referenceNode->next;
    while(traverseNode != referenceNode) {
        cout << traverseNode->data << endl;
        traverseNode = traverseNode->next;
    }
}

Node* deleteKthValue(Node* referenceNode, int k) {
    if (referenceNode->next == referenceNode) {
        delete(referenceNode); 
        return nullptr;
    }
    Node* deleterNode = referenceNode;
    while(deleterNode->data != k) {
        deleterNode = deleterNode->next;
        if (deleterNode == referenceNode) return referenceNode;
    }
    if (deleterNode == referenceNode) {
        referenceNode->back->next = referenceNode->next;
        referenceNode->next->back = referenceNode->back;
        referenceNode = referenceNode->next;
        delete(deleterNode);
    }
    else { 
    Node* prevNode = deleterNode->back;
    prevNode->next = deleterNode->next;
    deleterNode->next->back = prevNode;
    deleterNode->next = deleterNode->back = nullptr;
    delete(deleterNode);
    }
    return referenceNode;
}

Node* insertBeforeKthValue(Node* referenceNode, int insert_value, int value) {
    if (referenceNode->data == value) {
    Node* newNode = new Node(insert_value, referenceNode, referenceNode->back);
    referenceNode->back->next = newNode;
    referenceNode->back = newNode;
    return referenceNode;
}
    Node* traversalNode = referenceNode;
    while(traversalNode->next->data != value) {
        traversalNode = traversalNode->next;
        if (traversalNode->next == referenceNode) return referenceNode;
    }
    Node* newNode = new Node(insert_value, traversalNode->next, traversalNode);
    traversalNode->next->back = newNode;
    traversalNode->next = newNode;

    return referenceNode;
}

Node* insertAfterKthValue(Node* referenceNode, int insert_value, int value) {
    if (referenceNode->data == value) {
        Node* newNode = new Node(insert_value, referenceNode->next, referenceNode);
        referenceNode->next->back = newNode;
        referenceNode->next = newNode; 

        return referenceNode;
    }
    Node* traversalNode = referenceNode;
    while(traversalNode->data != value) {
        traversalNode = traversalNode->next;
        if (traversalNode == referenceNode) return referenceNode;
    }
    Node* newNode = new Node(insert_value, traversalNode->next, traversalNode);
    traversalNode->next->back = newNode;
    traversalNode->next = newNode;

    return referenceNode;
}


int noOfElems(Node* referenceNode) {
    if (!referenceNode) return 0;
    int count{1};
    Node* traversalNode = referenceNode->next;
    while(traversalNode != referenceNode) {
        traversalNode = traversalNode->next;
        count++;
    }
    return count;
}

int main() {

    vector<int> arr = {12,142,63,64,124,5,46,6,8};

    Node* referenceNode = createCLL(arr);
    displayAll(referenceNode);
    cout << endl;
    referenceNode = deleteKthValue(referenceNode, 64);
    displayAll(referenceNode);
    cout << endl;
    referenceNode = insertBeforeKthValue(referenceNode, 92, 124);
    displayAll(referenceNode);
    cout << endl;
    referenceNode = insertAfterKthValue(referenceNode, 92, 124);
    displayAll(referenceNode);
    cout << endl;
    cout << noOfElems(referenceNode) << endl;

    return 0;
}
