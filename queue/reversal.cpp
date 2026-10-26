#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reversal(queue<int> &org) {
    stack<int> s;

    while (!org.empty()) {
        s.push(org.front());
        org.pop();
    }

    while (!s.empty()) {
        org.push(s.top());
        s.pop();
    }
}

int main() {
    queue<int> org;

    for (int i = 1; i <= 10; i++) {
        org.push(i);
    }

    reversal(org);

    while (!org.empty()) {
        cout << org.front() << " ";
        org.pop();
    } // 10 9 8 7 6 5 4 3 2 1 
} 