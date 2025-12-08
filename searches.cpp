#include <iostream>
using namespace std;

void linearSearch(int arr[], int sz, int key) {
        int flag = 0, i = 0;
        for (i = 0; i < sz; i++) {
                if (arr[i] == key) {
                        flag = 1;
                        break;
                }
        }
        if (flag == 1) {
                cout << "Element is found at index : " << i << endl;
        } else {
                cout << "Element is not found." << endl;
        }
}


int linearSearchRec(int arr[], int index, int sz, int key) {
        if (index >= sz) return -1;
        if (arr[index] == key) return index;
        return linearSearchRec(arr, index+1, sz, key);
}


int binarySearch(int arr[], int sz, int key) {
        int left = 0, right = sz-1;
        while (left <= right) {
                int mid = left + (right - left)/2;
                if (arr[mid] == key) return mid;
                if (arr[mid] < key) left = mid+1;
                else right = mid-1;
        }
        return -1;
}

int binarySearchRec(int arr[], int left, int right, int key) {
        if (left > right) return -1;
        int mid = left + (right-left)/2;

        if (arr[mid] == key) return mid;
        if (arr[mid] < key) return binarySearchRec(arr, mid+1, right, key);
        return binarySearchRec(arr, left, mid-1, key);
}



int main() {
        int arr1[] = {43, 62, 82, -14, 12, 73, 24};
        int size1 = sizeof(arr1)/sizeof(arr1[0]);

        int arr2[] = {13, 29, 53, 68, 73, 80, 98, 99};
        int size2 = sizeof(arr2)/sizeof(arr2[0]);

        linearSearch(arr1, size1, -14);
        int bIndex = binarySearchRec(arr2, 0, size2, 130);

        if (bIndex != -1) cout << "Element found at index : " << bIndex << endl;
        else cout << "Element not found" << endl;

        cout << binarySearch(arr2, size2, 13) << endl;
        cout << linearSearchRec(arr1, 0, size1, 43) << endl;

        return 0;
}