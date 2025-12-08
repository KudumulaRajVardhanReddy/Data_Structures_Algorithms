#include <bits/stdc++.h>
using namespace std;

class HashTable {
    int* table, size, count, EMPTY = -1, DELETED = -2;

    public:
    HashTable(int size) {
        this->size = size;
        count = 0;
        table = new int[size];
        for (int i=0; i < size; i++) table[i] = EMPTY;
    }

    int hashFunction(int key) { return key%size; }

    void insert(int key) {
        int index{hashFunction(key)}, start = key;
        while (table[index] != EMPTY && table[index] != DELETED) {
            index = (index+1)%size;
            if (index == start) return;        
        }
        table[index] = key;
        count++;
    }

    bool search(int key) {
        int index{hashFunction(key)};
        int start{index};

        while (table[index] != EMPTY) {
            if (table[index] == key) return true;
            index = (index+1)%size;
            if (index == start) break;
        }
        return false;
    }

    void remove(int key) {
        int index{hashFunction(key)};
        int start{index};

        while(table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = DELETED;
                count--;
            }
            index = (index+1)%size;
            if (index == start) break;
        }
    }

    void display() {
        for (int i{0}; i < size; i++) {
            cout << i << ": ";
            if (table[i] == EMPTY) cout << "EMPTY";
            else if (table[i] == DELETED) cout << "DELETED";
            else cout << table[i] << endl;
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