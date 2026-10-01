#include<iostream>
#include<string>
using namespace std;

void printSubSets (string str, string ans) {
    if (str.size() == 0) {
        cout << ans << endl;
        return;
    }

    char ch = str[0];

    // yes
    printSubSets(str.substr(1, str.size()-1), ans+ch);
    // no
    printSubSets(str.substr(1, str.size()-1), ans);
}

int main() {
    string str = "abc";
    
    printSubSets(str, "");

    return 0;
}