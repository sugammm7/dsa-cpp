#include <iostream>
using namespace std;

int searchInRotSorArr (int *arr, int si, int ei, int target) {
    if (si > ei) {
        return -1;
    }

    int mid = si + (ei - si) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[si] <= arr[mid]) { 
        if (target >= arr[si] && target <= arr[mid-1]) {
            return searchInRotSorArr(arr, si, mid-1, target);
        } else {
            return searchInRotSorArr(arr, mid+1, ei, target);
        }
    } else {
        if (target >= arr[mid+1] && target <= arr[ei]) {
            return searchInRotSorArr(arr, mid+1, ei, target);
        } else {
            return searchInRotSorArr(arr, si, mid-1, target);
        }
    }
}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 55;

    cout << searchInRotSorArr(arr, 0, n-1, target);
    
    return 0;
}