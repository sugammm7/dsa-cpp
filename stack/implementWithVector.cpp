#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
    stack => FILO (first in last out)
*/
template<class T>
class Stack {
    vector<T> vec;
public:
    void push(T val) { // O(1)
        vec.push_back(val);
    }

    void pop() { // O(1)
        if (isEmpty()) {
            cout << "The stack is empty\n";
            return;
        }
        vec.pop_back();
    }

    T top() { // O(1)
        // if (isEmpty()) {
        //     cout << "The stack is empty";
        //     return -1;
        // }
        
        int topIdx = vec.size() - 1;
        return vec[topIdx];
    }

    bool isEmpty() { // O(1)
        return vec.size() == 0;
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
