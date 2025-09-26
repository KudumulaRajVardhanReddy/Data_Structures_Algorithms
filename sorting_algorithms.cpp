#include <bits/stdc++.h>
using namespace std;

/* Selection sort : Push min elements
    to initial indices of array.
*/

void selection_sort(int arr[], int size) {
    for (int i = 0; i <= size - 2; i++) {
        int min = i;
        for (int j = i; j <= size - 1; j++) if (arr[j] < arr[min]) min = j;
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    for (int i = 0; i < size; i++) cout << arr[i] << endl;
}

/* Bubble sort : Push max elements
    to last indices of array.
*/

void bubble_sort(int arr[], int size) {
    for (int i = size - 1; i >= 1; i--) {
        for (int j = 0; j <= i-1; j++)  {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++) cout << arr[i] << endl;
}

/* Insertion sort : While iteration, take an element
    kindly place it in the correct order.
*/

void insertion_sort(int arr[], int size) {
    for (int i = 0; i <= size - 1; i++) {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
    for (int i = 0; i < size; i++) cout << arr[i] << endl;
}

int main() {

    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) cin >> arr[i];

    selection_sort(arr, size);
    cout << endl;
    bubble_sort(arr, size);
    cout << endl;
    insertion_sort(arr, size);
    cout << endl;

    return 0;
}
 