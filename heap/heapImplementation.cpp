#include<iostream>
#include<vector>
using namespace std;

class Heap {
    vector<int> vec;

    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int maxIdx = i;

        if (left < vec.size() && vec[left] > vec[maxIdx]) {
            maxIdx = left;
        }

        if (right < vec.size() && vec[right] > vec[maxIdx]) {
            maxIdx = right;
        }

        if (maxIdx != i) {
            swap(vec[i], vec[maxIdx]);
            heapify(maxIdx);
        }
    }

public:
    void push(int val) {
        vec.push_back(val);

        int child = vec.size() - 1;
        int parent = (child - 1) / 2;

        while (vec[child] > vec[parent]) {
            swap(vec[child], vec[parent]);
            child = parent;
            parent = (child - 1) / 2;

            if (parent < 0) {
                break;
            }
        }
    }

    void pop() {
        swap(vec[0], vec[vec.size() - 1]);

        vec.pop_back();

        heapify(0);
    }

    int top() {
        return vec[0];
    }

    bool empty() {
        return vec.size() == 0;
    }
};

int main() {
    Heap h;

    h.push(10);
    h.push(2);
    h.push(16);
    h.push(4);

    while (!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }

    return 0;
}