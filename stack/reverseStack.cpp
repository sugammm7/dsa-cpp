#include<iostream>
#include<stack>
using namespace std;

void pushAtBottom (stack<int> &s, int val) {
    if (s.empty()) {
        s.push(val);
        return;
    }

    int top = s.top();
    s.pop();

    pushAtBottom(s, val);

    s.push(top);
}

void reverseStack (stack<int> &s) {
    if (s.empty()) {
        return;
    }

    int top = s.top();
    s.pop();

    reverseStack(s);

    pushAtBottom(s, top);
}

void printStack (stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    printStack(s); // 1 2 3
    cout << endl;

    reverseStack(s);

    printStack(s); // 3 2 1

    return 0;
}