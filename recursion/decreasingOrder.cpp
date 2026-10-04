#include <iostream>
using namespace std;

void printInDecreasingOrder(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    printInDecreasingOrder(n-1);
}

int main() {
    printInDecreasingOrder(5);

    return 0;
}