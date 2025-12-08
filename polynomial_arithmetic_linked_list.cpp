#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int coeff;
    int power;
    Node* next;

    Node(int coeff, int power, Node* next) {
        this->coeff = coeff;
        this->power = power;
        this->next = next;
    }

    Node(int coeff, int pow) {
        this->coeff = coeff;
        this->power = pow;
        next = nullptr;
    }
};

class Polynomial {
public:
    Node* head;
    Polynomial() { head = nullptr; }

    void insertTerm(int coeff, int power) {
        if (coeff == 0) return;
        Node* newNode = new Node(coeff, power);
        if (head == nullptr || head->power < power) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->power > power) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != nullptr && temp->power == power) {
            temp->coeff += coeff;
            delete newNode;
            if (temp->coeff == 0) removeTerm(power);
        } else {
            newNode->next = temp;
            if (prev) prev->next = newNode;
        }
    }

    void removeTerm(int power) {
        if (!head) return;
        if (head->power == power) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->power != power) temp = temp->next;
        if (!temp->next) return;
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    Polynomial addPolynomial(Polynomial& p2) {
        Polynomial result;
        Node *a = head, *b = p2.head;
        while (a && b) {
            if (a->power > b->power) {
                result.insertTerm(a->coeff, a->power);
                a = a->next;
            } else if (a->power < b->power) {
                result.insertTerm(b->coeff, b->power);
                b = b->next;
            } else {
                result.insertTerm(a->coeff + b->coeff, a->power);
                a = a->next; b = b->next;
            }
        }
        while (a) { result.insertTerm(a->coeff, a->power); a = a->next; }
        while (b) { result.insertTerm(b->coeff, b->power); b = b->next; }
        return result;
    }

    Polynomial subtractPolynomial(Polynomial& p2) {
        Polynomial result;
        Node *a = head, *b = p2.head;
        while (a && b) {
            if (a->power > b->power) {
                result.insertTerm(a->coeff, a->power);
                a = a->next;
            } else if (a->power < b->power) {
                result.insertTerm(-b->coeff, b->power);
                b = b->next;
            } else {
                result.insertTerm(a->coeff - b->coeff, a->power);
                a = a->next; b = b->next;
            }
        }
        while (a) { result.insertTerm(a->coeff, a->power); a = a->next; }
        while (b) { result.insertTerm(-b->coeff, b->power); b = b->next; }
        return result;
    }

    Polynomial multiplyPolynomial(Polynomial& p2) {
        Polynomial result;
        if (!head || !p2.head) return result;
        for (Node* a = head; a; a = a->next)
            for (Node* b = p2.head; b; b = b->next)
                result.insertTerm(a->coeff * b->coeff, a->power + b->power);
        return result;
    }

    void display() {
        if (!head) { cout << "0\n"; return; }
        Node* t = head;
        while (t) {
            if (t != head && t->coeff > 0) cout << "+";
            cout << t->coeff;
            if (t->power) {
                cout << "x";
                if (t->power != 1) cout << "^" << t->power;
            }
            t = t->next;
        }
        cout << "\n";
    }
};

int main() {
    Polynomial p1, p2, r;

    p1.insertTerm(3, 3);
    p1.insertTerm(2, 2);
    p1.insertTerm(1, 0);

    p2.insertTerm(2, 2);
    p2.insertTerm(1, 1);
    p2.insertTerm(4, 0);

    cout << "P1(x): "; p1.display();
    cout << "P2(x): "; p2.display();

    cout << "Add: "; r = p1.addPolynomial(p2); r.display();
    cout << "Subtract: "; r = p1.subtractPolynomial(p2); r.display();
    cout << "Multiply: "; r = p1.multiplyPolynomial(p2); r.display();

    return 0;
}
