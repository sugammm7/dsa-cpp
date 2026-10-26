#include<iostream>
#include<deque>
using namespace std;

class Stack {
    deque<int> deq;
public:
    void push(int val) {
        deq.push_front(val);
    }

    void pop() {
        deq.pop_front();
    }

    int top() {
        deq.front();
    }

    bool isEmpty() {
        return deq.empty();
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