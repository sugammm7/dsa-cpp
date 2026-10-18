#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverseStr(string str) {
    string ans = "";

    stack<char> s;
    for (char ch : str) {
        s.push(ch);
    }

    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }

    return ans;
}

int main() {
    string str = "abcd";

    cout << reverseStr(str);

    return 0;
}