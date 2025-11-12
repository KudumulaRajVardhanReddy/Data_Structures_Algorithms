#include <bits/stdc++.h>
using namespace std;

/*int findLargest(int arr[], int n) {
    int max = arr[0];
    for (int i = 0; i < n-1; i++) if(max < arr[i]) max = arr[i];
    return max;
} */

/* int findSecondLargest(int arr[], int n) {         //Less Code, but less Efficient!
    set<int> s(arr, arr+n);
    return (s.size() < 2)? arr[0]:*prev(s.end(), 2);
} */

/* int findSecondLargest(int arr[], int n) {
    int secondLargest{0};
    sort(arr, arr + n);
    for (int i = n-1; i >= 0; i--) {        //Less Efficient Again!
        if (arr[i] != arr[n-1]) {
            secondLargest = arr[i]; 
            break;
        }
    }
    return secondLargest;
} */

/* int findSecondLargest(int arr[], int n) {
    int largest = findLargest(arr, n);
    int secondLargest = -1;
    for (int i = 0; i < n; i++) {
        if(secondLargest < arr[i] && arr[i] != largest) secondLargest = arr[i];
    }
    return secondLargest;
} */

pair<int, int> findLargers(int arr[], int n) { //Efficient Code
    int largest = arr[0];
    int secondLargest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (largest < arr[i]) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
        }
    }
    return {largest, secondLargest};
}

pair<int, int> findSmalls(int arr[], int n) {
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (smallest > arr[i]) {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && arr[i] < secondSmallest) {
            secondSmallest = arr[i];
        }
    }
    return {smallest, secondSmallest};
}

bool isArrSorted(int arr[], int n) {
    bool status = true;
    for (int i = 0; i < n; i++) {
        if (arr[i] >  arr[i+1]) {
            status = false;
            break;
        }
    }
    return status;
}

/* int returnUniques(int arr[], int n) {
    set s(arr, arr + n);
    return s.size();
} */      //O(nlogn)

int returnUniques(int arr[], int n) {
    int i{0};
    for (int j = 0; j < n; j++) {
        if (arr[j] != arr[i]) {
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
} //O(n)

void leftRotateArray(int arr[], int n) {
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++) { 
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }   
}
/* void leftRotateArrayByD(int arr[], int n, int D) {
    D = D % n; 
    int temp[D];

    for (int i = 0; i < D; i++)
        temp[i] = arr[i];

    for (int i = D; i < n; i++)
        arr[i - D] = arr[i];

    for (int i = 0; i < D; i++)
        arr[n - D + i] = temp[i];

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
} */ // TC = O(n), SC = O(n+D), here D is extra space

void leftRotateArrayByD(int arr[], int n, int D) {
    reverse(arr, arr + D); // O(D)
    reverse(arr + D, arr + n); //O(n-D)
    reverse(arr, arr + n); // O(n)

    for (int i=0; i < n; i++) cout << arr[i] << " ";
} // TC = O(2n) but SC = O(1), no extra space 'd' is occupied!

int zeroesCount(int arr[], int n) {
    int countZeroes{0};
    for(int i{0}; i < n; i++) {
        if (arr[i] == 0) {
            countZeroes++;
        }
    }
    return countZeroes;
}

vector<int> moveZeroesToEnd(vector<int> array, int n) {
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (array[i] == 0) {
            j = i;
            break;
        }
    }
    if (j == -1) return array;

    for (int i = j+1; i < n; i++) {
        if (array[i] != 0) {
            swap(array[i], array[j]);
            j++;
        }
    }
    return array;
}

/* vector<int> unionOfVectors(vector<int> vec1, vector<int> vec2) {
    int n1 = vec1.size();
    int n2 = vec2.size();
    set<int> s;

    for (int i = 0; i < n1; i++) {
        s.insert(vec1[i]);
    }
    for (int i = 0; i < n2; i++) {
        s.insert(vec2[i]);
    }
    vector<int> setToVec;
    for (auto x: s) setToVec.push_back(x);

    return setToVec;
} */ //Brute Force Solution!

vector<int> unionOfVectors(vector<int> vec1, vector<int> vec2) {

    vector<int> resVec;
    int i = 0, j = 0;
    int n1 = vec1.size(), n2 = vec2.size();

    while (i < n1 && j < n2) {
        if (vec1[i] == vec2[j]) {
            if (resVec.empty() || resVec.back() != vec1[i])
                resVec.push_back(vec1[i]);
            i++;
            j++;
        }
        else if (vec1[i] < vec2[j]) {
            if (resVec.empty() || resVec.back() != vec1[i])
                resVec.push_back(vec1[i]);
            i++;
        }
        else {
            if (resVec.empty() || resVec.back() != vec2[j])
                resVec.push_back(vec2[j]);
            j++;
        }
    }

    while (i < n1) {
        if (resVec.empty() || resVec.back() != vec1[i])
            resVec.push_back(vec1[i]);
        i++;
    }

    while (j < n2) {
        if (resVec.empty() || resVec.back() != vec2[j])
            resVec.push_back(vec2[j]);
        j++;
    }
    return resVec;
}
// TC - O(n1 + n2), SC - O(n1 + n2), only if you remove first
// 2 sorting functions, as this union method only works
// for sorted arrays, even for intersection method
//arrays must be sorted

vector<int> intersectionOfVectors(vector<int> vec1, vector<int> vec2) {
    vector<int> resVec;

    int i = 0, j = 0;
    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] == vec2[j]) {
            if (resVec.empty() || resVec.back() != vec1[i])
                resVec.push_back(vec1[i]);
            i++;
            j++;
        } else if (vec1[i] < vec2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return resVec;
}

/* int findMissingNumber(int arr[], int N) {
    for (int i = 1; i <= N; i++) {
        int flag = 0;
        for (int j = 0; j < N-1; j++) {
            if (arr[j] == i) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) return i;
    }
    return -1;
} */ //TC = O(N2)

/*int findMissingNumber(int arr[], int N) { //Hashing Way! TC = O(2N)
    int hash[N+1] = {0};
    for (int i = 0; i < N+1; i++) {
        hash[arr[i]] = 1;
    }
    for (int i = 1; i < N+1; i++) {
        if (hash[i] == 0) return i;
    }
    return -1;
} // TC - O(N), SC - O(N)
*/

/* int findMissingNumber(int arr[], int N) {
    int sum = N*(N+1)/2, s = 0;
    for(int i=0; i < N-1; i++) s += arr[i];

    return sum-s;
} //TC - O(N), SC - O(1)
*/

int findMissingNumber(int arr[], int N) { //XOR way
    int XOR1 = 0, XOR2 = 0;
    for (int i = 0; i < N-1; i++) {
        XOR2 ^= arr[i];
        XOR1 ^= (i+1);
    }
    XOR1 ^= N;

    return XOR1^XOR2;
} //TC - O(N), SC - O(1), slightly better for large cases, assume N
//10 power 5, sum method overflows as we are using int, but with XOR,
//XOR of any number will never be that large.

int maxConsecutivOnes(int arr[], int n) {
    int count = 0, maxCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            count++;
            maxCount = max(count, maxCount);
        }
        else count = 0;
    }
    return maxCount;
}

/* int findNonRepeatingNumber(int arr[], int n) {
    unordered_map<long long, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] == 1)
            return arr[i];
    }
    return -1;
} //TC - O(N), SC - O(N/2 + 1)
*/

//optimal solutions
int findNonRepeatingNumber(int arr[], int n) { //XOR Method
    int XOR = 0;
    for (int i = 0; i < n; i++) XOR ^= arr[i];
    return XOR;
}

int main() {
    int arr[] = {1, 2, 6, 7, 7, 5};
    int arrr[] = {1, 3, 4, 5};
    int ar[] = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    int ar1[] = {1, 1, 2, 3, 3, 4, 4};
    vector<int> vec1 = {1, 3, 4, 5, 6, 9};
    vector<int> vec2 = {2, 3, 5, 7, 8, 10};

    cout << findLargers(arr, 6).first << endl;
    cout << findLargers(arr, 6).second << endl;
    cout << findSmalls(arr, 6).first << endl;
    cout << findSmalls(arr, 6).second << endl;
    cout << boolalpha << isArrSorted(arr, 6) << endl;
    cout << returnUniques(arr, 6) << endl;
    leftRotateArray(arr, 6);
    cout << endl;
    leftRotateArrayByD(arr, 6, 2);
    cout << endl;
    for (auto x: moveZeroesToEnd(vec1, 6)) cout << x << " ";
    cout << endl;
    for (auto x: unionOfVectors(vec1, vec2)) cout << x << " ";
    cout << endl;
    for (auto x: intersectionOfVectors(vec1, vec2)) cout << x << " ";
    cout << endl;
    cout << findMissingNumber(arrr, 5) << endl;
    cout << maxConsecutivOnes(ar, 9) << endl;
    cout << findNonRepeatingNumber(ar1, 7) << endl;
    return 0;
}