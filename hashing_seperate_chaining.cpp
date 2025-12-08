#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

class HashTable {
    int size;
    Node** table;

public:
    HashTable(int size) {
        this->size = size;
        table = new Node*[size];
        for (int i = 0; i < size; i++) table[i] = nullptr;
    }

    int hashFunction(int key) { return key % size; }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);

        if (table[index] == nullptr)
            table[index] = newNode;
        else {
            Node* temp = table[index];
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (prev == nullptr)
            table[index] = temp->next;
        else
            prev->next = temp->next;

        delete temp;
    }

    bool search(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    ~HashTable() {
        for (int i = 0; i < size; i++) {
            Node* temp = table[i];
            while (temp) {
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
        }
        delete[] table;
    }
};

int main() {
    HashTable h(7);

    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(7);
    h.insert(22);
    h.insert(35);

    h.display();

    cout << "Search 22: " << (h.search(22) ? "Found" : "Not Found") << "\n";
    cout << "Search 99: " << (h.search(99) ? "Found" : "Not Found") << "\n";

    h.remove(22);
    h.display();

    return 0;
}
