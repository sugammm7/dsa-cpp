#include <iostream>
using namespace std;

void printArr (int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int petition (int *arr, int si, int ei) {
    int pivot = arr[ei];
    int i = si - 1;

    for (int j = si; j < ei; j++) {
        if (arr[j] <= pivot) {
            swap(arr[++i], arr[j]);
        }
    }   
    swap(arr[++i], arr[ei]);

    return i;
}

void quickSort (int *arr, int si, int ei) {
    if (si >= ei) {
        return;
    }

    int pivotIdx = petition(arr, si, ei);
    printArr(arr, 5);

    quickSort(arr, si, pivotIdx-1);
    quickSort(arr, pivotIdx+1, ei); 
}

int main() {
    int arr[] = {2, 4, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n-1);
    printArr(arr, n);

    return 0;
}