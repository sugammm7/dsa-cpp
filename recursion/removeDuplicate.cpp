// TC => O(n^2) n calls * O(n) for passing whole string
// SC => O(n^2) 

#include <iostream>
#include <string>
using namespace std;

void removeDuplicate (string str, int *count, string ans, int idx) {
    if (idx == str.size()) {
        cout << ans;
        return;
    }

    if (count[str[idx] - 'a'] == 0) {
        count[str[idx] - 'a'] = 1;
        removeDuplicate(str, count, ans + str[idx], idx+1);
    } else {
        removeDuplicate(str, count, ans, idx+1);
    }
}

int main () {
    string str = "aappnacolllege";
    string ans = "";
    int count[26] = {0};

    removeDuplicate(str, count, ans, 0);

    return 0;
}