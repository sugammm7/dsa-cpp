#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge (string *arr, int si, int ei, int mid) {
    vector<string> temp;

    int i = si, j = mid+1;

    while (i <= mid && j <= ei) {
        if (arr[i] >= arr[j]) {
            temp.push_back(arr[j++]);
        } else {
            temp.push_back(arr[i++]);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    while (j <= ei) {
        temp.push_back(arr[j++]);
    }

    for (int idx = si, x = 0; idx <= ei; idx++) {
        arr[idx] = temp[x++];
    }
}

void mergeSort (string *arr, int si, int ei) {
    if (si >= ei) {
        return;
    }

    int mid = si + (ei - si) / 2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);

    merge(arr, si, ei, mid);
}

void printArr (string *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main () {
    string arr[] = {"sun", "earth", "mars", "mercury"};
    int n = 4;

    mergeSort(arr, 0, n-1);
    printArr(arr, n);

    return 0;
}