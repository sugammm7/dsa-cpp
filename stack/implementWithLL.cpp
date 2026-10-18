#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>
class Node {
public:
    T data;
    Node *next;

    Node(T val) {
        this->data = val;
        next = NULL;
    }
};

template<class T>
class Stack {
    Node<T> *head;
public:
    Stack () {
        head = NULL;
    }

    void push(T val) { 
        Node<T> *newNode = new Node<T>(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void pop() { 
        if (isEmpty()) {
            cout << "The stack is empty\n";
            return;
        }
        Node<T> *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    T top() {
        // if (isEmpty()) {
        //     cout << "The stack is empty";
        //     return -1;
        // }
        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main () {
    Stack<string> s;

    s.push("Hello");
    s.push("World");
    s.push("Hi"); 

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
