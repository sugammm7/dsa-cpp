#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int> &org) {
    int n = org.size();
    queue<int> first;

    for (int i = 0; i < n/2; i++) {
        first.push(org.front());
        org.pop();
    }

    while (!first.empty()) {
        org.push(first.front());
        first.pop();

        org.push(org.front());
        org.pop();
    }
}

int main() {
    queue<int> org;

    for (int i = 1; i <= 10; i++) {
        org.push(i);
    }

    interleave(org);

    while (!org.empty()) {
        cout << org.front() << " ";
        org.pop();
    } // 1 6 2 7 3 8 4 9 5 10 

    return 0;
}