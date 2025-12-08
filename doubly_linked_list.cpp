#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next, * back;

    public:
    Node(int data,  Node* next, Node* back) {
        this->data = data;
        this->next = next;
        this->back = back;
    }

    public:
    Node(int data) {
        this->data = data;
        next = nullptr;
        back = nullptr;
    }
    public:
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
        this->back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* beheadDLL(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    if (head!= nullptr) head->back = nullptr;
    temp->next = nullptr;
    delete temp;

    return head;
}

Node* cutTheTail(Node* head) {
    if (head == nullptr) return nullptr;
    if(head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while(temp->next) temp = temp->next;
    Node* tail = temp;
    temp = temp->back;
    temp->next = nullptr;
    tail->back = nullptr;
    delete(tail);

    return head;
}

Node* deleteKthElement(Node* head, int k) {
    Node* temp = head, * prev, * front;
    int cntr{0};
    if (head == nullptr) return head;
    while(temp) {
        cntr++;
        if (cntr == k) break;
        temp = temp->next;
    }
    prev = temp->back;
    front = temp->next;
    if (prev == nullptr && front == nullptr) {
        delete temp;
        return nullptr;
    }
    if (prev == nullptr) return beheadDLL(head);
    if (front == nullptr) return cutTheTail(head);
    front->back = prev;
    prev->next = front;
    temp->back = nullptr;
    temp->next = nullptr;
    delete temp;

    return head;
}

Node* insertNewHead(Node* head, int value) {
    Node* newHead = new Node(value, head);
    head->back = newHead;
    return newHead;
}

Node* insertNewTail(Node* head, int value) {
    if (head == nullptr) return head;
    Node* temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    Node* newTail = new Node(value, nullptr, temp);
    temp->next = newTail;

    return head;
}

Node* insertBeforeKthPosn(Node* head, int val, int k) {
    if (head == nullptr) return head;
    if (k == 1) return insertNewHead(head, val);
    Node* temp = head; int count{0};
    while(temp && count < k) {
        count++;
        if (count == k) break;
        temp = temp->next;
    }
    Node* newNode = new Node(val, temp, temp->back);
    temp->back->next = newNode;
    temp->back = newNode;

    return head;
}

void print(Node* head) {
    while(head) {
        cout << head->data << endl;
        head = head->next;
    }
}

int main() {
     vector<int> arr = {1, 2, 3, 4, 5, 6};
     Node* head = convertArr2DLL(arr);

     print(head);
     cout << endl;
     head = beheadDLL(head);
     print(head);
     cout << endl;
     head = cutTheTail(head);
     print(head);
     cout << endl;
     head = deleteKthElement(head, 3);
     print(head);
     cout << endl;
     head = insertNewHead(head, 1);
     print(head);
     cout << endl;
     head = insertNewTail(head, 6);
     print(head);
     cout << endl;
     head = insertBeforeKthPosn(head, 4, 3);
     print(head);
     cout << endl;
}
