#include<iostream>
using namespace std;

bool isArrSorted (int *arr, int idx, int n) {
    if (idx == n-1) {
        return true;
    }

    if (arr[idx] > arr[idx+1]) {
        return false;
    }

    return isArrSorted(arr, idx+1, n);
}

int main() {
    int arr[] = {1, 2, 3, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << isArrSorted(arr, 0, n);

    return 0;
}