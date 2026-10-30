#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Job {
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit) {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit (vector<pair<int, int>> pairs) {
    vector<Job> jobs;

    for (int i = 0; i < pairs.size(); i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
        return a.profit > b.profit;
    }); //lambda function

    cout << "Selecting Job " << jobs[0].idx << endl;
    int profit = jobs[0].profit;
    int safeDate = 2;

    for (int i = 1; i < jobs.size(); i++) {
        if (jobs[i].deadline >= safeDate) {
            cout << "Selecting Job " << jobs[i].idx << endl;
            profit += jobs[i].profit;
            safeDate++;
        }
    }

    return profit;
}

int main() {
    vector<pair<int, int>> pairs(4, make_pair(0,0));

    pairs[0] = (make_pair(4, 20));
    pairs[1] = (make_pair(1, 10));
    pairs[2] = (make_pair(1, 40));
    pairs[3] = (make_pair(1, 30));

    cout << maxProfit(pairs);

    return 0;
}