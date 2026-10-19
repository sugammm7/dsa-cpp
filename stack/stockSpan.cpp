#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void stockSpan (vector<int> st, vector<int> span) {
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for (int i = 1; i < st.size(); i++) {
        int curr = st[i];
        while (!s.empty() && curr >= st[s.top()]) {
            s.pop();
        }

        if (s.empty()) {
            span[i] = i + 1;
        } else {
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }

        s.push(i);
    }

    for (int i = 0; i < span.size(); i++) {
        cout << span[i] << " ";
    }
}

int main() {
    vector<int> st = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span = {0, 0, 0, 0, 0, 0, 0};

    stockSpan(st, span);

    return 0;
}