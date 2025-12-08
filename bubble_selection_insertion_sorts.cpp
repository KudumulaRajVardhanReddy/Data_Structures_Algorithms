#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    } 
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = arr[i];
        for (int j = i; j < size; j++) {
            if (arr[j] < min) swap(arr[j], min);
        }
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int curr = i, prev = i-1;
        while (prev >= 0 && arr[curr] < arr[prev]) {
            arr[prev+1] = arr[prev];
            prev--;
        }
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int arr[] = {134, 3241, 534, 342, 45434, 546}, size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, size);
    cout << endl;
    selectionSort(arr, size);
    cout << endl;
    insertionSort(arr, size);
}
