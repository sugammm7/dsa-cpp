#include <iostream>
using namespace std;

int firstOccurance (int *arr, int n, int target, int idx) {
    if (idx == n) {
        return -1;
    }

    if (arr[idx] == target) {
        return idx;
    }

    return firstOccurance(arr, n, target, idx+1);
}

int main () {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << firstOccurance(arr, n, 6, 5);

    return 0;
}