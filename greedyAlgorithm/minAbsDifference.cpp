#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    vector<int> a = {4, 1, 8, 7};
    vector<int> b = {2, 3, 6, 5};

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans += abs(a[i] - b[i]);
    }

    cout << ans;

    return 0;
}