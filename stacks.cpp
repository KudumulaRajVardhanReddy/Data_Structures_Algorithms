#include <bits/stdc++.h>
using namespace std;

class StacksWithArrays {
    int arr[10];
    int topIndex = -1;

    public:
    bool isEmpty() { return topIndex == -1; }
    bool isFull() { return topIndex == 9; }

    void push(int value) {
        if (isFull()) cout << "Stack is full" << endl;  
        else {
            topIndex++;
            arr[topIndex] = value;
            cout << "Pushed " << value << " into stack." << endl;
        }
    }

    void pop() {
        if (isEmpty()) cout << "Stack is Empty." << endl;
        else {
            cout << "Popped out " << arr[topIndex] << "." << endl; 
            topIndex--;
        }
    }

    void top() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }    
        cout << "Top value is " << arr[topIndex] << "." << endl;
    }
    void size() {
        cout << "Stack size is " << topIndex + 1 << "." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty bro." << endl;
            return;
        }
        for (int i=0; i <= topIndex; i++) cout << arr[i] << endl;
    }
};

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};


class StacksWithLLs {
    Node* topNode = nullptr;

    public:

    bool isEmpty() { return topNode == nullptr; }

    void push(int value) {
        Node* newNode = new Node(value, topNode);
        topNode = newNode;
        cout << "Pushed " << value << " into stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Popped out " << topNode->data << "." << endl;
        Node* deleterNode = topNode;
        topNode = topNode->next;
        deleterNode->next = nullptr;
        delete(deleterNode);
    }

    void top() {
        if (isEmpty()) {
            cout << "Stack is Empty." << endl;
            return;
        }
        cout << topNode->data << endl;
    }

    void size() {
        Node* traverseNode = topNode; int size{0};
        while (traverseNode != nullptr) {
            size++;
            traverseNode = traverseNode->next;
        }
        cout << "Stack size is " << size << "." << endl;
    }
    void display() {
        Node* traverseNode = topNode; 
        while (traverseNode != nullptr) {
            cout << traverseNode->data << endl;
            traverseNode = traverseNode->next;
        }
    }
};

int main() {
    StacksWithArrays stck;

    stck.pop();
    cout << boolalpha << stck.isFull() << endl;
    stck.push(2131);
    stck.push(8735);
    stck.pop();
    stck.push(7655);
    stck.push(5647);
    stck.pop();
    stck.top();
    stck.push(8756);
    cout << boolalpha << stck.isFull() << endl;
    stck.push(9484);
    stck.pop();
    stck.push(65454);
    cout << boolalpha << stck.isEmpty() << endl;
    stck.size();
    stck.display();

    cout << endl;

    StacksWithLLs stcck;

    stcck.pop();
    stcck.push(2131);
    stcck.push(8735);
    stcck.pop();
    stcck.push(7655);
    stcck.push(5647);
    stcck.pop();
    stcck.top();
    stcck.push(8756);
    stcck.push(9484);
    stcck.pop();
    stcck.push(65454);
    cout << boolalpha << stcck.isEmpty() << endl;
    stcck.size();
    stcck.display();

    return 0;
}

