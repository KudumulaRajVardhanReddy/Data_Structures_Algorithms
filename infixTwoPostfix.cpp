#include <bits/stdc++.h>
using namespace std;

class Stack {
    char *arr;
    int top, size;
public:
    Stack(int n) {
        size = n;
        arr = new char[size];
        top = -1;
    }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == size - 1; }
    void push(char x) { if (!isFull()) arr[++top] = x; }
    char pop() { return isEmpty() ? '\0' : arr[top--]; }
    char peek() { return isEmpty() ? '\0' : arr[top]; }
    ~Stack() { delete[] arr; }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '%' || op == '/') return 2;
    if (op == '-' || op == '+') return 1;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

bool isRightPrecedence(char c) { return c == '^'; }

string infixToPostfix(string exp) {
    Stack s(exp.size());
    string result = "";

    for (char c: exp) {
        if (c == ' ') continue;
        if (isalnum(c)) result += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') result += s.pop();
            if (!s.isEmpty() && s.peek() == '(') s.pop();
        }
        else if (isOperator(c)) {
            if (!s.isEmpty() && isOperator(s.peek()) && 
            precedence(c) < precedence(s.peek()) ||
            (precedence(c) == precedence(s.peek())) && !isRightPrecedence(s.peek())) result += s.pop();
            s.push(c);
        }
    }

    while (!s.isEmpty()) result += s.pop();

    return result;
}

int main() {
    string exp = "A+(B*C-(D/E^F)*G)*H";
    cout << infixToPostfix(exp) << "\n";
}

