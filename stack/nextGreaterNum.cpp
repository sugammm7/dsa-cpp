#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void nextGreaterNum (vector<int> vec, vector<int> ans) {
    int n = vec.size();
    stack<int> s;

    s.push(n-1);
    ans[n-1] = -1;

    for (int i = n-2; i >= 0; i--) {
        int curr = vec[i];
        while(!s.empty() && curr >= vec[s.top()]) {
            s.pop();
        }

        if (s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = vec[s.top()];
        }
        
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    vector<int> vec = {6, 8, 0, 1, 3};
    vector<int> ans(vec.size());

    nextGreaterNum(vec, ans);

    return 0;
}