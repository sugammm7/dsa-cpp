#include <iostream>
using namespace std;

int waysOfPairingFriends (int n) {
    if (n == 1 || n == 2) {
        return n;
    }

    // Single
    int way1 = waysOfPairingFriends(n-1);
    // Mingle
    int way2 = (n-1) * waysOfPairingFriends(n-2);

    return way1 + way2;
}

int main() {
    cout << waysOfPairingFriends(3);

    return 0;
}