#include<iostream>
using namespace std;

class Stack {
    int *arr;
    int topIdx;
public:
    Stack () {
        arr = new int[100];
        topIdx = -1;
    }

    void push(int val) { 
        if (isFull()) {
            cout << "Stack overflow";
            return;
        }

        arr[++topIdx] = val;
    }

    void pop() { 
        if (isEmpty()) {
            cout << "The stack is empty\n";
            return;
        }

        arr[topIdx--];         
    }

    int top() { // O(1)
        if (isEmpty()) {
            cout << "The stack is empty";
            return -1;
        }

        return arr[topIdx];
    }

    bool isEmpty() { 
        return topIdx < 0;
    }

    bool isFull() {
        return topIdx == 99;
    }

    ~Stack () {
        if (arr != NULL) {
            delete[] arr;
            arr = NULL;
        }
    }
};

int main () {
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
