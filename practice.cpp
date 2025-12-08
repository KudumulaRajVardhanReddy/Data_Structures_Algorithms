#include <iostream>
using namespace std;

/*
class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

Node* insertAtBeginning(Node* refNode, int val) {
    if (!refNode) return nullptr;
    return new Node(val, refNode);
}

Node* insertNewTail(Node* refNode, int val) {
    if (!refNode) return nullptr;
    Node* traverseNode = refNode;
    while (traverseNode->next) {
        traverseNode = traverseNode->next;
    }
    Node* newNode = new Node(val, nullptr);
    traverseNode->next = newNode;
    
    return refNode;
}

Node* insertBeforeKthPosition(Node* refNode, int k, int val) {
    if (!refNode) return nullptr;
    if (k == 1) return insertAtBeginning(refNode, val);
    Node* tempNode = refNode; Node* prev = nullptr; int count = 1;
    while (tempNode && count < k) {
        prev = tempNode;
        tempNode = tempNode->next;
        count++;
    }
    Node* newNode = new Node(val, tempNode);
    prev->next = newNode;

    return refNode;
}

Node* removeHead(Node* refNode) {
    if (!refNode) return nullptr;
    Node* tempNode = refNode;
    refNode = refNode->next;
    delete tempNode;

    return refNode;
}

Node* removeTail(Node* refNode) {
    if (!refNode ) return nullptr;
    Node* tempNode = refNode, * prevNode = nullptr;
    while (tempNode->next) {
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    prevNode->next = nullptr;
    delete tempNode;

    return refNode;
}

Node* removeKthPositionNode(Node* refNode, int k) {
    if (!refNode) return nullptr;
    Node* tempNode = refNode, * prevNode = nullptr; int count = 1;
    while (tempNode && count < k) {
        prevNode = tempNode;
        tempNode = tempNode->next;
        count++;
    }
    prevNode->next = tempNode->next;
    delete tempNode;

    return refNode;
}

void print(Node* refNode) {
    if (!refNode) return;
    while (refNode->next) {
        cout << refNode->data << endl;
        refNode = refNode->next;
    }
}

void sizeOfLL(Node* refNode) {
    if (!refNode) return;
    int count = 0;
    while (refNode->next) {
        refNode = refNode->next;
        count++;
    }
    cout << "Size is : " << count << endl;
}

int main() {
    Node* refNode = new Node(45);
    refNode = insertAtBeginning(refNode, 32);
    refNode = insertAtBeginning(refNode, 37);
    refNode = insertBeforeKthPosition(refNode, 2, 52);
    cout << endl;
    print(refNode);
    cout << endl;
    refNode = removeHead(refNode);
    print(refNode);
    refNode = removeTail(refNode);
    cout << endl;
    print(refNode);
    refNode = insertBeforeKthPosition(refNode, 2, 46);
    refNode = insertBeforeKthPosition(refNode, 2, 92);
    refNode = insertBeforeKthPosition(refNode, 2, 79);
    cout << endl;
    print(refNode);
    refNode = removeKthPositionNode(refNode, 2);
    cout << endl;
    print(refNode);
    cout << endl;
    sizeOfLL(refNode);
}
*/

#include <iostream>
using namespace std;

/*
class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

Node* insertAtBeginning(Node* refNode, int val) {
    if (!refNode) return nullptr;
    return new Node(val, refNode);
}

Node* insertNewTail(Node* refNode, int val) {
    if (!refNode) return nullptr;
    Node* traverseNode = refNode;
    while (traverseNode->next) {
        traverseNode = traverseNode->next;
    }
    Node* newNode = new Node(val, nullptr);
    traverseNode->next = newNode;
    
    return refNode;
}

Node* insertBeforeKthPosition(Node* refNode, int k, int val) {
    if (!refNode) return nullptr;
    if (k == 1) return insertAtBeginning(refNode, val);
    Node* tempNode = refNode; Node* prev = nullptr; int count = 1;
    while (tempNode && count < k) {
        prev = tempNode;
        tempNode = tempNode->next;
        count++;
    }
    Node* newNode = new Node(val, tempNode);
    prev->next = newNode;

    return refNode;
}

Node* removeHead(Node* refNode) {
    if (!refNode) return nullptr;
    Node* tempNode = refNode;
    refNode = refNode->next;
    delete tempNode;

    return refNode;
}

Node* removeTail(Node* refNode) {
    if (!refNode ) return nullptr;
    Node* tempNode = refNode, * prevNode = nullptr;
    while (tempNode->next) {
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    prevNode->next = nullptr;
    delete tempNode;

    return refNode;
}

Node* removeKthPositionNode(Node* refNode, int k) {
    if (!refNode) return nullptr;
    Node* tempNode = refNode, * prevNode = nullptr; int count = 1;
    while (tempNode && count < k) {
        prevNode = tempNode;
        tempNode = tempNode->next;
        count++;
    }
    prevNode->next = tempNode->next;
    delete tempNode;

    return refNode;
}

void print(Node* refNode) {
    if (!refNode) return;
    while (refNode->next) {
        cout << refNode->data << endl;
        refNode = refNode->next;
    }
}

void sizeOfLL(Node* refNode) {
    if (!refNode) return;
    int count = 0;
    while (refNode->next) {
        refNode = refNode->next;
        count++;
    }
    cout << "Size is : " << count << endl;
}

int main() {
    Node* refNode = new Node(45);
    refNode = insertAtBeginning(refNode, 32);
    refNode = insertAtBeginning(refNode, 37);
    refNode = insertBeforeKthPosition(refNode, 2, 52);
    cout << endl;
    print(refNode);
    cout << endl;
    refNode = removeHead(refNode);
    print(refNode);
    refNode = removeTail(refNode);
    cout << endl;
    print(refNode);
    refNode = insertBeforeKthPosition(refNode, 2, 46);
    refNode = insertBeforeKthPosition(refNode, 2, 92);
    refNode = insertBeforeKthPosition(refNode, 2, 79);
    cout << endl;
    print(refNode);
    refNode = removeKthPositionNode(refNode, 2);
    cout << endl;
    print(refNode);
    cout << endl;
    sizeOfLL(refNode);
}
*/

/*

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = next;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

class Queue {
    Node* front = nullptr, * rear = nullptr;

    public:
    bool isEmpty() { return front == nullptr; }

    void enqueue(int val) {
        Node* newNode = new Node(val, nullptr);
        if (isEmpty()) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (isEmpty()) return;
        Node* deleterNode = front;
        front = front->next;
        delete deleterNode;

        if (front == nullptr) rear = nullptr;
    }

    void display() {
        if (isEmpty()) return;
        Node* traverseNode = front;
        while (traverseNode) {
            cout << traverseNode->data << endl;
            traverseNode = traverseNode->next;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(32);
    q.enqueue(43);
    q.display();
    cout << endl;
    q.enqueue(82);
    q.display();
    q.dequeue();
    cout << endl;
    q.display();
    
    return 0;

}

*/

/*

#include <iostream>
using namespace std;

class CircularQueue {
    int size;
    int* arr;
    int front, rear;

    public:
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty() { return front == -1; }
    bool isFull() {
        return front == 0 && rear == size-1 || front == (rear+1)%size;
    }

    void enqueue(int value) {
        if (isEmpty()) {
            front = rear = 0;
            arr[front] = value;
            cout << "Enqueued " << arr[rear] << "." << endl;
            return;
        }
        if (isFull()) return;
        rear = (rear+1)%size;
        arr[rear] = value;
        cout << "Enqueued " << arr[rear] << "." << endl;
    }

    void dequeue() {
        if (isEmpty()) return;
        if (rear == front) {
            rear = front = -1;
            return;
        }
        front = (front+1)%size;
    }

    void peek() {
        if (isEmpty()) return;
        cout << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) return;
        int i = front;
        while (true) {
            cout << arr[i];
            if (i == rear) break;
            cout << endl;
            i = (i+1)%size;
        }
        cout << "\n";
    }
    ~CircularQueue() { delete[] arr;}
};

int main() {
    CircularQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << endl;
    q.display();
    cout << endl;

    q.enqueue(4);
    q.enqueue(5);
    cout << endl;
    q.dequeue();
    cout << endl;
    q.display();
    cout << endl;
    q.peek();
    
    return 0;
}

*/


/*
#include <iostream>
using namespace std;

class Deque {
    int size;
    int* arr;
    int front, rear;

    public:
    Deque(int size) {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == size - 1; }

    void insertFromBeginning(int val) {
        if (isEmpty()) {
            front = rear = 0;
            arr[front] = val;
            cout << "inserted from beginning : " << arr[front] << "." << endl;
            return;
        }
        if (isFull()) return;
        if (front == 0) return;
        front -= 1;
        arr[front] = val;
        cout << "inserted from beginning : " << arr[front] << "." << endl;
    }

    void insertFromEnd(int val) {
        if (isEmpty()) {
            front = rear = 0;
            arr[front] = val;
            cout << "inserted from end : " << arr[front] << "." << endl;
            return;
        }
        if (isFull()) return;
        rear = rear+1;
        arr[rear] = val;
        cout << "inserted from end : " << arr[rear] << "." << endl;
    }

    void removeFromBeginning() {
        if (isEmpty()) return;
        if (front == rear) {
            cout << "removed from beginning : " << arr[front] << "." << endl;
            front = rear = -1;
            cout << "Stack is empty now." << endl;
            return;
        }
        cout << "removed from beginning : " << arr[front] << "." << endl;
        front = front+1;
    }

    void removeFromEnd() {
        if (isEmpty()) return;
        if (rear == front) {
            cout << "Stack is empty now." << endl;
            rear = front = -1;
            return;
        }
        cout << "removed from end : " << arr[rear--] << endl;
    }

    void showLastElement() {
        if (isEmpty()) return;
        if (front == rear) cout << arr[front] << endl;
        cout << "Rear element : " << arr[rear] << "." << endl;
    }

    void showFirstElement() {
        if (isEmpty()) return;
        if (front == rear) cout << arr[front] << endl;
        cout << "First element : " << arr[front] << "." << endl;
    }

    void display() {
        if (isEmpty()) return;
        if (front == rear) cout << arr[front] << endl;
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << endl;
        }        
    }
};

int main() {
    Deque dq(5);
    dq.insertFromEnd(1);
    dq.insertFromEnd(2);
    dq.insertFromEnd(3);
    cout << endl;
    dq.removeFromBeginning();
    dq.removeFromBeginning();
    dq.removeFromBeginning();
    cout << endl;
    dq.insertFromEnd(4);
    dq.insertFromEnd(5);
    dq.insertFromEnd(6);   
    cout << endl;
    dq.showLastElement();
    cout << endl;
    dq.showFirstElement();
    cout << endl;
    dq.display();

    return 0;
}

*/

/*

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next) {
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

    int hashIndex(int i) { return i%size; }

    void insert(int key) {
        int index = hashIndex(key);
        Node* newNode = new Node(key);

        if (!table[index]) table[index] = newNode;
        else {
            Node* temp = table[index];
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void remove(int key) {
        int index = hashIndex(key);
        Node* temp = table[index], * prev = nullptr;

        while (temp && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) return;
        if (!prev) table[index] = temp->next;
        else prev->next = temp->next;

        delete temp;
    }

    bool search(int key) {
        int index = hashIndex(key);
        if (!table[index]) return false;
        Node* temp = table[index];
        while (temp) {
            if (key == temp->data) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            Node* temp = table[i];
            while(temp) {
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

*/


