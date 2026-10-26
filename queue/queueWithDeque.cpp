#include<iostream>
#include<deque>
using namespace std;

class Queue {
    deque<int> deq;
public:
    void push(int val) {
        deq.push_back(val);
    }

    void pop() {
        deq.pop_front();
    }

    int front() {
        deq.front();
    }

    bool isEmpty() {
        return deq.empty();
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