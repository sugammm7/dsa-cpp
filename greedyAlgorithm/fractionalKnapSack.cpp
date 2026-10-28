#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<float, int> p1, pair<float, int> p2) {
    return p1 > p2;
}

int fractionalKnapSack (vector<int> value, vector<int> weight, int capacity) {
    vector<pair<float, int>> ratio(value.size(), make_pair(0.0, 0));

    for (int i = 0; i < value.size(); i++) {
        float r = value[i] / (float)weight[i];

        ratio[i] = make_pair(r, i);
    }

    sort(ratio.begin(), ratio.end(), compare);

    int ans = 0;
    for (int i = 0; i < ratio.size(); i++) {
        int idx = ratio[i].second;
        
        if (weight[idx] <= capacity) {
            ans += value[idx];
            capacity -= weight[idx];
        } else {
            ans += capacity * ratio[i].first;
            capacity = 0;
            break;
        }
    }

    return ans;
}

int main() {
    vector<int> value = {60, 120, 100};
    vector<int> weight = {10, 30, 20};
    int capacity = 50;

    cout << fractionalKnapSack(value, weight, capacity);

    return 0;
}