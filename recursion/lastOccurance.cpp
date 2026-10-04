#include<iostream>
using namespace std;

int lastOccurance (int *arr, int n, int idx, int target) {
    if (idx == n) {
        return -1;
    }

    int lastOccuranceIdx = lastOccurance(arr, n, idx+1, target);

    if (lastOccuranceIdx == -1 && arr[idx] == target) {
        lastOccuranceIdx = idx;
    }

    return lastOccuranceIdx;
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(n);

    cout << lastOccurance(arr, n, 0, 1);

    return 0;
}