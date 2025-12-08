#include <iostream>
using namespace std;

class Node {
        public:
        int val;
        Node* prev,* next;

        Node(int val) {
                this->val = val;
                prev = next = nullptr;
        }
};

class DLL {
        public:
        Node* head, * tail;

        DLL() {
                head = tail = nullptr;
        }

        bool isEmpty() { return head == nullptr; }

        void insertHead(int val) {
                if (isEmpty()) {
                        Node* newNode = new Node(val);
                        head = tail = newNode;
                        return;
                }
                Node* temp = head;
                Node* newNode = new Node(val);
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
        }

        void insertTail(int val) {
                if (isEmpty()) {
                        Node* newNode = new Node(val);
                        head = tail = newNode;
                        return;
                }
                Node* newNode = new Node(val);
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
        }

        void insertAtKthPosition(int K, int val) {
                if (isEmpty()) return;
                Node* temp = head; int count = 1;
                while (temp && count < K-1) {
                        temp = temp->next;
                }
                if (temp == tail) {
                        insertTail(val);
                        return;
                }
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
        }

        void removeHead() {
                if (isEmpty()) return;
                Node* temp = head;
                if (head == tail) {
                        head = tail = nullptr;
                        delete temp;
                        return;
                }
                head = head->next;
                head->prev = temp;
                delete temp;
        }

        void removeTail() {
                if (isEmpty()) return;
                Node* temp = tail;
                if (head == tail) {
                        head = tail = nullptr;
                        delete temp;
                        return;
                }
                tail = tail->prev;
                delete temp;
        }

        void removeByValue(int val) {
                if (isEmpty()) return;
                if (head->val == val) {
                        removeHead();
                        return;
                }
                if (tail->val == val) {
                        removeTail();
                        return;
                }
                Node* temp = head;
                while (temp && temp->val != val) {
                        temp = temp->next;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
        }

        void removeKthNode(int K) {
                if (isEmpty()) return;
                if (K == 1) {
                        removeHead();
                        return;
                }
                int count = 1; Node* temp;
                while (temp && count < K) {
                        temp = temp->next;
                }
                if (temp == tail) {
                        removeTail();
                        return;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
        }

        void display() {
                Node* temp = head;
                while (temp) {
                        cout << temp->val << " <-> ";
                        temp = temp->next;
                }
                cout << " NULL \n";
        }

        void display_reverse() {
                Node* temp = tail;
                while (temp) {
                        cout << temp->val << " <-> ";
                        temp = temp->prev;
                }
                cout << " NULL \n";
        }

        void deleteList() {
                if (isEmpty()) return;
                Node* temp = head;
                while (temp) {
                        Node* del = temp;
                        temp = temp->next;
                        delete del;
                }
                head = tail = nullptr;
        }
        void countNodes() {
                if (isEmpty()) return;
                if (head == tail) {
                        cout << "No. of Nodes = 1\n";
                        return;
                }
                Node* temp = head;
                int count = 0;
                while (temp) {
                        temp = temp->next;
                        count++;
                }
                cout << "No. of Nodes = " << count << "\n";
        }
};

int main() {
        DLL dll;
        dll.insertHead(32);
        dll.insertHead(34);
        dll.display();
        dll.countNodes();
        dll.insertAtKthPosition(2, 76);
        dll.removeHead();
        dll.insertAtKthPosition(2, 78);
        dll.display();
        dll.insertAtKthPosition(2, 24);
        dll.display();
        dll.countNodes();

        return 0;
}