#include <iostream>
#include <vector>
using namespace std;

int merge(int *arr, int si, int mid, int ei) {
    vector<int> temp;
    int i = si, j = mid+1;

    int count = 0;

    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            count += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    while (j <= ei) {
        temp.push_back(arr[j++]);
    }

    cout << "Merging" << endl;
    for (int idx = si, x = 0; idx <= ei; idx++) {
        arr[idx] = temp[x++];
        cout << idx << ":" << arr[idx] << " ";
    }
    cout << endl;

    return count;
}

int mergeSort(int *arr, int si, int ei) {
    int count = 0;

    if (ei > si) {
        int mid = si + (ei - si) / 2;

        count = mergeSort(arr, si, mid);
        count += mergeSort(arr, mid+1, ei);

        cout << "breaking into " << si << ", " << ei << endl;

        count += merge(arr, si, mid, ei);
    }

    return count;
}

int main() {
    int arr[] = {5, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << mergeSort(arr, 0, n-1) << endl;

    return 0;
}