// Time complexity => O(2 ^ (row + col))
// This can be optimized to O(row + col) 
// No of ways = ((row - 1 + col - 1) ! ) / ((row - 1)! * (col - 1)!)

#include <iostream>
#include <string>
using namespace std;

int gridWays (int row, int col, int i, int j, string ans) {
    if (i == row-1 && j == col-1) {
        cout << ans << endl;
        return 1;
    }

    if (i == row || j == col) {
        return 0;
    }

    int way1 = gridWays(row, col, i, j + 1, ans + "R");
    int way2 = gridWays(row, col, i + 1, j, ans + "D");

    return way1 + way2;
}

int main() {
    int row = 3, col = 3;
    string ans = "";

    cout << gridWays(row, col, 0, 0, ans);

    return 0;
}

