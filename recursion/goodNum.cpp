#include <iostream>
using namespace std;

long long powerCalc(long long x, long long p) {
    if (p == 0) {
        return 1;
    }

    long long halfPower = powerCalc(x, p/2);
    long long halfPowerSquared = halfPower * halfPower;

    if (p % 2 != 0) {
        halfPowerSquared *= x;
    }

    return halfPowerSquared;
}

long long goodNumCount (int n) {
    long long ob = n / 2;
    long long eb = n / 2;

    if (n % 2 != 0) {
        eb = (n+1) / 2;
    }

    return powerCalc(4, ob) * powerCalc(5, eb);
}

int main() {
    cout << goodNumCount(5);

    return 0;
}