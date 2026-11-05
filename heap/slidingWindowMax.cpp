#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void slidingWindowMax (vector<int> vec, int k) {
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < k; i++) {
        pq.push(make_pair(vec[i], i));
    }

    cout << pq.top().first << " ";

    for (int i = k; i < vec.size(); i++) {
        while (!pq.empty() && pq.top().second <= i-k) {
            pq.pop();
        }

        pq.push(make_pair(vec[i], i));

        cout << pq.top().first << " ";
    }
}

int main () {
    vector<int> vec = {1, 3, -1, -3, 5, 3, 6, 7};

    slidingWindowMax(vec, 3);

    return 0;
}
