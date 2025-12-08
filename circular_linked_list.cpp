#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class CLL {
public:
    Node* tail;

    CLL() {
        tail = nullptr;
    }

    bool isEmpty() { return tail == nullptr; }

    Node* head() { return tail ? tail->next : nullptr; }

    void insertHead(int val) {
        Node* newNode = new Node(val);

        if (isEmpty()) {
            tail = newNode;
            tail->next = tail;
            return;
        }

        newNode->next = tail->next;
        tail->next = newNode;
    }

    void insertTail(int val) {
        Node* newNode = new Node(val);

        if (isEmpty()) {
            tail = newNode;
            tail->next = tail;
            return;
        }

        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void insertAtPos(int pos, int val) {
        if (pos <= 1 || isEmpty()) {
            insertHead(val);
            return;
        }

        int count = 1;
        Node* temp = head();

        while (count < pos - 1 && temp != tail) {
            temp = temp->next;
            count++;
        }

        if (temp == tail) {
            insertTail(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteHead() {
        if (isEmpty()) return;

        Node* h = head();

        if (h == tail) {
            delete tail;
            tail = nullptr;
            return;
        }

        tail->next = h->next;
        delete h;
    }

    void deleteTail() {
        if (isEmpty()) return;

        Node* h = head();

        if (h == tail) {
            delete tail;
            tail = nullptr;
            return;
        }

        Node* temp = h;
        while (temp->next != tail) {
            temp = temp->next;
        }

        temp->next = tail->next;
        delete tail;
        tail = temp;
    }

    void deleteAtPos(int pos) {
        if (isEmpty()) return;

        if (pos <= 1) {
            deleteHead();
            return;
        }

        int count = 1;
        Node* temp = head();

        while (count < pos - 1 && temp->next != head()) {
            temp = temp->next;
            count++;
        }

        Node* del = temp->next;

        if (del == head()) { deleteHead(); return; }
        if (del == tail) { deleteTail(); return; }

        temp->next = del->next;
        delete del;
    }

    void deleteByValue(int val) {
        if (isEmpty()) return;

        Node* temp = head();
        Node* prev = tail;

        while (temp != tail && temp->val != val) {
            prev = temp;
            temp = temp->next;
        }

        if (temp->val != val) return;

        if (temp == head()) { deleteHead(); return; }
        if (temp == tail) { deleteTail(); return; }

        prev->next = temp->next;
        delete temp;
    }

    bool search(int val) {
        if (isEmpty()) return false;

        Node* temp = head();
        do {
            if (temp->val == val) return true;
            temp = temp->next;
        } while (temp != head());

        return false;
    }

    int countNodes() {
        if (isEmpty()) return 0;

        int count = 0;
        Node* temp = head();
        do {
            count++;
            temp = temp->next;
        } while (temp != head());

        return count;
    }

    void display() {
        if (isEmpty()) {
            cout << "NULL\n";
            return;
        }

        Node* temp = head();
        do {
            cout << temp->val << " -> ";
            temp = temp->next;
        } while (temp != head());
        cout << "(back to head)\n";
    }

    void clear() {
        if (isEmpty()) return;

        Node* start = head();
        Node* curr = start;
        Node* nxt;

        do {
            nxt = curr->next;
            delete curr;
            curr = nxt;
        } while (curr != start);

        tail = nullptr;
    }

    ~CLL() {
        clear();
    }
};

int main() {
    CLL cll;

    cll.insertHead(20);
    cll.insertHead(10);
    cll.insertTail(30);
    cll.insertTail(40);
    cll.insertAtPos(3, 25);

    cout << "List: ";
    cll.display();

    cll.deleteHead();
    cll.deleteTail();
    cll.deleteByValue(25);

    cout << "\nAfter deletions:\n";
    cll.display();

    cout << "\nCount: " << cll.countNodes() << "\n";
    cout << "Search 40: " << (cll.search(40) ? "Found" : "Not Found") << "\n";

    cll.clear();
    cout << "After clearing: ";
    cll.display();
}