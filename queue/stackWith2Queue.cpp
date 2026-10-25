#include<iostream>
#include<queue>
using namespace std;

class Stack {
    queue<int> q1;
    queue<int> q2;

public:
    void push(int val) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(val);

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty";
            return;
        }

        q1.pop();
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty";
            return -1;
        }

        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }

};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}