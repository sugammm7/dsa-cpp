#include <iostream>
using namespace std;

long long powerCal (long long n, long long p) {
    if (p == 0) {
        return 1;
    }

    if (p < 0) {
        n = 1 / n;
        p = -p;
    }

    long long halfPower = powerCal(n, p/2);
    long long halfPowerSquared = halfPower * halfPower;

    if (p % 2 != 0) {
        halfPowerSquared *= n;
    }

    return halfPowerSquared;
}

int main () {
    cout << powerCal(3, 3);

    return 0;
}