#include <iostream>
using namespace std;

void bs(int arr[], int sz);
void disp(int arr[], int sz);
void ss(int arr[], int sz);
int partition(int arr[], int start, int end);
void qs(int arr[], int start, int end);
void is(int arr[], int sz);
void merge(int arr[], int l, int m, int r);
void ms(int arr[], int l, int r);
void heapify(int arr[], int n, int i);
void buildHeap(int arr[], int n, int i);
void heapSortRec(int arr[], int n);
void heapSort(int arr[], int n);

void bs(int arr[], int sz) {
        bool swapped = false;
        for (int i = 0; i < sz; i++) {
                for (int j = 0; j < sz - i - 1; j++) {
                        if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
                        swapped = true;
                }
                if (!swapped) break;
        }
        disp(arr, sz);
}

void ss(int arr[], int sz) {
        for (int i = 0; i < sz - 1; i++) {
                int min = i;
                for (int j = i+1; j < sz; j++) {
                        if (arr[min] > arr[j]) min = j;
                }
                if (min != i) swap(arr[i], arr[min]);
        }
        disp(arr, sz);
}

void is(int arr[], int sz) {
        for (int i = 1; i < sz; i++) {
                int j = i;
                while (j > 0 && arr[j-1] > arr[j]) {
                        swap(arr[j-1], arr[j]);
                        j--;
                }
        }
        disp(arr, sz);
}

void merge(int arr[], int l, int m, int r) {
        int j = m+1, i = l, k = 0, temp[1000];
        while (i <= m && j <= r) {
                if (arr[i] <= arr[j]) temp[k++] = arr[i++];
                else temp[k++] = arr[j++];
        }

        while (i <= m) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];

        for (int t = 0; t < k; t++) arr[l + t] = temp[t];
}

void ms(int arr[], int l, int r) {
        if (l >= r) return;
        int m = l + (r-l)/2;
        ms(arr, l, m);
        ms(arr, m+1, r);
        merge(arr, l, m, r);
}

int partition(int arr[], int start, int end) {
        int i = start-1;
        int pivot = arr[end];
        for (int j = start; j < end; j++) if (arr[j] < pivot) swap(arr[++i], arr[j]);
        swap(arr[++i], arr[end]);
        return i;
}

void qs(int arr[], int start, int end) {
        if (start >= end) return;
        int pivot = partition(arr, start, end);
        qs(arr, start, pivot-1);
        qs(arr, pivot+1, end);
}

void heapify(int arr[], int n, int i) {
        int left = 2*i+1, right = 2*i+2, largest = i;

        if (left < n && arr[largest] < arr[left]) largest = left;
        if (right < n && arr[largest] < arr[right]) largest = right;

        if (largest != i) {
                swap(arr[i], arr[largest]);
                heapify(arr, n, largest);
        }
}

void buildHeap(int arr[], int n, int i) {
        if (i < 0) return;
        heapify(arr, n, i);
        buildHeap(arr, n, i-1);
}

void heapSortRec(int arr[], int n) {
        if (n <= 1) return;
        swap(arr[0], arr[n-1]);
        heapify(arr, n-1, 0);
        heapSortRec(arr, n-1);
}

void heapSort(int arr[], int n) {
        buildHeap(arr, n, n/2-1);
        heapSortRec(arr, n);
}

void disp(int arr[], int sz) {
        int i = 0;
        while (i < sz) {
                cout << arr[i] << " ";
                i++;
        }
        cout << endl;
}

int main() {
        int arr[] = {42, 63, 82, 28, 67, 18, 49, 28, 47};
        int sz = sizeof(arr)/sizeof(arr[0]);
        //bs(arr, sz);
        //ss(arr, sz);
        //is(arr, sz);
        //ms(arr, 0, sz-1);
        qs(arr, 0, sz-1);
        //buildHeap(arr, sz, sz/2-1);
        //heapSort(arr, sz);
        disp(arr, sz);
        return 0;
}