#include<iostream>
#include<string>
using namespace std;

void permutation (string str, string ans) {
    if (str.size() == 0) {
        cout << ans << endl;
        return;
    }

    int n = str.size();

    for (int i = 0; i < n; i++) {
        string nextStr = str.substr(0, i) + str.substr(i+1, n-i-1);

        permutation(nextStr, ans + str[i]);
    } 
}

int main () {
    string str = "abc";

    permutation(str, "");

    return 0;
}