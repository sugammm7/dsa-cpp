#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Soldier{
public:
    int idx;
    int count;

    Soldier(int idx, int count) {
        this->idx = idx;
        this->count = count;
    }

    bool operator < (const Soldier &other) const {
        if (this->count == other.count) {
            return this->idx > other.idx;
        }
        return this->count > other.count;
    }
};

void weakestSoldier (vector<vector<int>> mat, int k) {
    priority_queue<Soldier> pq;

    for (int i = 0; i < mat.size(); i++) {
        int count = 0;
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1) {
                count++;
            }
        }
        pq.push(Soldier(i, count));
    }

    for (int i = 0; i < k; i++) {
        cout << "S" << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0}
    };

    weakestSoldier(mat, 3); // S0 S3 S1

    return 0;
}