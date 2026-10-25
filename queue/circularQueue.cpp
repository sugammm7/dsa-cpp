#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int f;
    int rear;
    int capacity;
    int currSize;

public:
    Queue(int capacity) {
        arr = new int[capacity];
        f = 0, rear = -1;
        this->capacity = capacity;
        currSize = 0;
    }

    void push(int val) {
        if (currSize == capacity) {
            cout << "Queue is full";
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = val;
        currSize++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return;
        }

        f = (f + 1) % capacity;
        currSize--;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return -1;
        }

        return arr[f];
    }

    bool isEmpty() {
        return capacity == 0;
    }
};

int main() {
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.push(5);
    cout << q.front() << endl;


    return 0;
}