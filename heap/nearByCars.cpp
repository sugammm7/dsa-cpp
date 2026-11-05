#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Car {
public:
    int idx;
    int distance;

    Car(int idx, int distance) {
        this->idx = idx;
        this->distance = distance;
    }

    bool operator < (const Car &other) const {
        return this->distance > other.distance;
    }
};

void nearByCars (vector<pair<int, int>> pos, int k) {
    vector<Car> cars;

    for (int i = 0; i < pos.size(); i++) {
        int distance = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);

        cars.emplace_back(i, distance);
    }

    priority_queue<Car> pq(cars.begin(), cars.end());

    for (int i = 0; i < k; i++) {
        cout << "Car " << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<pair<int, int>> pos;

    pos.push_back(make_pair(3, 3));
    pos.push_back(make_pair(5, -1));
    pos.push_back(make_pair(4, 2));

    nearByCars(pos, 2);

    return 0;
}