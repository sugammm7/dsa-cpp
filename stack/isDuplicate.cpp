#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isDuplicate(string str) {
    stack<char> s;

    for (char ch: str) {
        if (ch != ')') {
            s.push(ch);
        } else {
            if (s.top() == '(') {
                return true;
            }

            while (s.top() != '(') {
                s.pop();
            }
            s.pop();
        }
    }

    return false;
}

int main() {
    string str1 = "((a+b))";
    string str2 = "((a+b)+(b+c))";

    cout << isDuplicate(str1) << endl; //1
    cout << isDuplicate(str2) << endl; //0

    return 0;
}