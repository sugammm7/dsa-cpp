#include <iostream>
using namespace std;

int tilingWays (int n) {
    if (n == 1 || n == 0) {
        return 1;
    }

    // vertical
    int way1 = tilingWays(n-1);
    // horizontal
    int way2 = tilingWays(n-2);

    return way1 + way2;
}

int main() {
    cout << tilingWays(5);

    return 0;
}