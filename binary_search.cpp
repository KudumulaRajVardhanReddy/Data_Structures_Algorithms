#include <bits/stdc++.h>
using namespace std;

int bs_recursive(int arr[], int left, int right, int key) {
    if (left > right) return -1;
    int mid = left + (right - left)/2;

    if (arr[mid] == key) return mid;
    if (key < arr[mid]) return bs_recursive(arr, left, mid-1, key);
    return bs_recursive(arr, mid+1, right, key);
}

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid+1;
        if (arr[mid] > key) right = mid-1;
    }
}

int main() {
    int arr[] = {323, 423, 452, 454, 643};
    cout << bs_recursive(arr, 0, 4, 643) << endl;
    cout << binarySearch(arr, 0, 4, 643) << endl;

    return 0;
}
