#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }

    public:
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
}; 

Node* convertArrToLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(Node* LL) {
    Node* temp = LL;
    int counter{0};

    while(temp) {
        temp = temp->next;
        counter++;
    }
    return counter;
}

bool checkIfPresent(Node* head, int val) {
    Node* temp = head;

    while(temp) {
        if (temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

Node* beheadLL(Node* head) {
    if (head == nullptr) return head;
    Node* temp = head;
    head = head -> next;
    delete temp;

    return head;
}

Node* cutTail(Node* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    while(temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* delKElem(Node* head, int k) {
    if (head == nullptr) return head;
    if (k == 1) return beheadLL(head);

    Node* temp = head, * prev;
    int count{0};
    while(temp) {
        count++;
        if (k == count) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertNewHead(Node* head, int val) {
    return new Node(val, head);
}

Node* insertNewTail(Node* head, int val) {
    Node* temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    Node* newTail = new Node(val);
    temp->next = newTail;

    return head;
}

Node* insertAtKthPosn(Node* head, int val, int k) {
    int count{0};
    Node* temp = head, * prev = nullptr;
    if (head == nullptr) return head;
    if (k == 1) return insertNewHead(head, val);
    while (temp) {
        count++;
        if (count == k) {
            Node* newElem = new Node(val, prev->next);
            prev->next = newElem;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (k == count+1) return insertNewTail(head, val);
    return head;
}

Node* insertBeforeValue(Node* head, int val, int ref_val) {
    if (head == nullptr) return nullptr;
    if (head->data == ref_val) return new Node(val, head);
    Node* temp = head;
    while(temp->next) {
        if (temp->next->data == ref_val) {
            Node* insertNode = new Node(val, temp->next);
            temp->next = insertNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {12, 13, 24, 65, 76, 85};
    Node* head = convertArrToLL(arr);
    Node* temp = head;

    while(temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
    cout << lengthOfLL(head) << endl;
    cout << boolalpha << checkIfPresent(head, 24) << endl;
    head = beheadLL(head);
    cout << head->data << endl;
    cout << endl;
    head = cutTail(head);
    temp = head;
    while(temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
    head = delKElem(head, 2);
    temp = head;
    while (temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
    head = insertNewHead(head, 53);
    temp = head;
    while (temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
    head = insertNewTail(head, 32);
    temp = head;
    while (temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
    head = insertAtKthPosn(head, 10, 2);
    temp = head;
    while (temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
    head = insertBeforeValue(head, 97 ,65);
    temp = head;
    while (temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}