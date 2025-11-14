#include <bits/stdc++.h>
using namespace std;

class HashTable {
    int* table, size, count;
    const int EMPTY = -1;
    const int DELETED = -2;

public:
    HashTable(int size) {
        this->size = size;
        count = 0;
        table = new int[size];
        for (int i = 0; i < size; i++) table[i] = EMPTY;
    }

    int hashFunction(int key) { return key % size; }

    void insert(int key) {
        if (count == size) return;
        int index = hashFunction(key);

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i * i) % size;
            if (table[newIndex] == EMPTY || table[newIndex] == DELETED) {
                table[newIndex] = key;
                count++;
                return;
            }
        }
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int i = 0; i < size; i++) {
            int newIndex = (index + i * i) % size;
            if (table[newIndex] == EMPTY) return false;
            if (table[newIndex] == key) return true;
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        for (int i = 0; i < size; i++) {
            int newIndex = (index + i * i) % size;
            if (table[newIndex] == EMPTY) return;
            if (table[newIndex] == key) {
                table[newIndex] = DELETED;
                count--;
                return;
            }
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (table[i] == EMPTY) cout << "EMPTY";
            else if (table[i] == DELETED) cout << "DELETED";
            else cout << table[i];
            cout << "\n";
        }
    }

    ~HashTable() { delete[] table; }
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
    cout << "\nSearch 22: " << (h.search(22) ? "Found" : "Not Found") << "\n";
    cout << "Search 99: " << (h.search(99) ? "Found" : "Not Found") << "\n";

    h.remove(22);
    cout << "\nAfter deletion:\n";
    h.display();

    return 0;
}
