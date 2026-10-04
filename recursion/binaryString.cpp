#include <iostream>
#include <string>
using namespace std;

void binaryStrings (int n, string ans, int lastBit) {
    if (ans.size() == n) {
        cout << ans << endl;
        return;
    }

    if (lastBit != 1) {
        binaryStrings(n, ans + '0', 0);
        binaryStrings(n, ans + '1', 1);
    } else {
        binaryStrings(n, ans + '0', 0);
    }
}

int main () {
    binaryStrings(3, "", 0);

    return 0;
}