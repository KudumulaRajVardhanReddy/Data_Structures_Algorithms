#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* nxt;
    
    public:
    Node(int data_ip, Node* nxt_ip) {
        data = data_ip;
        nxt = nxt_ip;
    }
    
    public:
    Node(int data_ip) {
        data = data_ip;
        nxt = nullptr;
    }
};

Node* convertStr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i=0; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->nxt = temp;
        mover = temp;
    }

    return head;
}

int lengthOfLL(Node* head) {
    int cntr{0};
    Node* temp = head;

    while(temp) {
        temp = temp->nxt;
        cntr++;
    }
    return cntr;
}

Node* 

int main() {
    vector<int> arr = {3453,34,3234,253,345,56,46,757};
    
    Node* head = convertStr2LL(arr);

    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->nxt;
    }

    cout << endl;

    int size = lengthOfLL(head);
    cout << size << endl;

    return 0;
}