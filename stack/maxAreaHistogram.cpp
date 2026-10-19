#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int maxArea (vector<int> height) {
    stack<int> s;
    int n = height.size();

    vector<int> shl(n);
    shl[0] = -1;
    s.push(0);

    for (int i = 1; i < height.size(); i++) {
        int curr = height[i];

        while (!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }

        if (s.empty()) {
            shl[i] = -1;
        } else {
            shl[i] = s.top();
        }

        s.push(i);
    }

    while (!s.empty()) {
        s.pop();
    } 

    vector<int> shr(n);
    shr[n-1] = n;
    s.push(n-1);

    for (int i = n-2; i >= 0; i--) {
        int curr = height[i];

        while (!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }

        if (s.empty()) {
            shr[i] = n;
        } else {
            shr[i] = s.top();
        }

        s.push(i);
    }

    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++) {
        int currArea = (shr[i] - shl[i] - 1) * height[i];
        maxArea = max(maxArea, currArea);
    }

    return maxArea;
}

int main() {
    vector<int> height = {2, 1, 5, 6, 2, 3};

    cout << maxArea(height);

    return 0;
}