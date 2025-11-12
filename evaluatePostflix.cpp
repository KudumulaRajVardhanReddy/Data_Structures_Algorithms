#include <bits/stdc++.h>
using namespace std;

class Stack {
    int *arr, top, size;
public:
    Stack(int n) {
        size = n;
        arr = new int[size];
        top = -1;
    }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == size - 1; }
    void push(int x) { if (!isFull()) arr[++top] = x; }
    int pop() { return isEmpty() ? 0 : arr[top--]; }
    int peek() { return isEmpty() ? 0 : arr[top]; }
    ~Stack() { delete[] arr; }
};

int evaluatePostfix(string exp) {
    Stack s(exp.size());
    for (char c : exp) {
        if (c == ' ') continue;
        if (isdigit(c)) s.push(c - '0');
        else {
            int b = s.pop();
            int a = s.pop();
            switch (c) {
                case '+': s.push(a+b);
                case '-': s.push(a-b);
                case '*': s.push(a*b);
                case '/': s.push(a/b);
                case '%': s.push(a%b);
                case '^': s.push(pow(a, b));
            }
        }
    }
    return s.pop();
}

int main() {
    string exp = "52+3-*4/"; 
    cout << evaluatePostfix(exp) << "\n";
}
