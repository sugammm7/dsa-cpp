#include<iostream>
#include<vector>
using namespace std;

int coinsCount (vector<int> coins, int V) {
    int n = coins.size();
    int ans = 0;

    for (int i = n-1; i >= 0 && V > 0; i--) {
        if (V >= coins[i]) {
            ans += V / coins[i];
            V = V % coins[i];
        }
    }

    return ans;
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};

    cout << coinsCount(coins, 540); //3
}