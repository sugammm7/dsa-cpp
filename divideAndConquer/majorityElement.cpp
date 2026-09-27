#include <iostream>
using namespace std;

int countElement (int *arr, int num, int si, int ei) {
    cout << "Searching " << num << " in " << si << ", " << ei << endl;

    int count = 0;

    for (int i = si; i <= ei; i++) {
        if (arr[i] == num) {
            count++;
        }
    }

    return count;
}

int majorityElement(int *arr, int si, int ei) {
    if (si == ei) {
        return arr[si];
    }

    int mid = si + (ei - si) / 2;

    int left = majorityElement(arr, si, mid);
    int right = majorityElement(arr, mid+1, ei);

    if (left == right) {
        cout << "left " << left << " = " << "right " << right << endl;
        return left;
    }

    int leftCount = countElement(arr, left, si, ei);
    int rightCount = countElement(arr, right, si, ei);

    return leftCount > rightCount ? left : right;
}

int main() {
    int arr[] = {2,2,1,1,1,2,2};
    int n = 7;

    cout << majorityElement(arr, 0, n-1);
    
    return 0;
}