#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValidParanthesis (string str) {
    stack<char> s;

    for (char ch: str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            if (s.empty()) {
                return false;
            }

            if (s.top() == '(' && ch == ')' || 
                s.top() == '{' && ch == '}' ||
                s.top() == '[' && ch == ']'
            ) {
                s.pop();
            }
        }
    }

    if (s.empty()) {
        return true;
    } else {
        return false;
    }
}

int main () {
    string str1 = "(){}[]";
    string str2 = "({[]})";
    string str3 = "(((()";
    string str4 = "({})))";

    cout << isValidParanthesis(str1); // 1
    cout << isValidParanthesis(str2); // 1
    cout << isValidParanthesis(str3); // 0
    cout << isValidParanthesis(str4); // 0
    return 0;
}