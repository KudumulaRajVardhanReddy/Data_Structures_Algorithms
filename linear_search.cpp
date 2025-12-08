#include <bits/stdc++.h>
using namespace std;

void linearSearch(int arr[], int size, int key) {
    int flag;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            flag = 1;
            cout << "Found at index " << i << "." << endl;
            break;
        }
    }
    if (flag!=1) cout << "Not found." << endl;
}

void ls_recursive(int arr[], int init_pos, int size, int key) {
    if (init_pos >= size) {
        cout << "Not Found" << endl;
        return;
    }
    if (arr[init_pos] == key) {
        cout << "Found at " << init_pos << endl;
        return;
    }
    ls_recursive(arr, init_pos+1, size, key);
}

int main() {
    int arr[] = {124, 2421, 433, 432, 534, 655};
    linearSearch(arr, 6, 432);
    ls_recursive(arr, 0, 6, 432);

    return 0;
}
