#include <iostream>
#include <string>
using namespace std;

int startAndEndWithSameCh (string str, int st, int end, int len) {
    if (len == 1) {
        return 1;
    } 

    if (st > end) {
        return 0;
    }

    int res = startAndEndWithSameCh(str, st, end-1, len-1) + startAndEndWithSameCh(str, st+1, end, len-1) - startAndEndWithSameCh(str, st+1, end-1, len-2);

    if (str[st] == str[end]) {
        res += 1;
    }

    return res;
}

int main () {
    string str = "abcab";
    int n = str.size();

    cout << startAndEndWithSameCh(str, 0, n-1, n);

    return 0;
}