#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node (int val) {
        this->data = val;
        this->next = NULL;
    }
};

class Queue {
    Node *head;
    Node *tail;

public:
    Queue() {
        head = tail = NULL;
    }

    void push(int val) {
        Node *newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "The queue is empty";
            return;
        }

        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    int front() {
        if (isEmpty()) {
            cout << "The queue is empty";
            return -1;
        }

        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main () {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    q.pop();

    while (!q.isEmpty()) {
        cout << q.front() << " ";
        q.pop();
    } // 2 3

    return 0;
}