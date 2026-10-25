#include<iostream>
#include<stack>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;

public:
    void push(int val) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return;
        }

        s1.pop();
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return -1;
        }

        return s1.top();
    }

    bool isEmpty() {
        return s1.empty();
    }
};

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.isEmpty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}