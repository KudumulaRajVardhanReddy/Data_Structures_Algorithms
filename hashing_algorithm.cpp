#include <bits/stdc++.h>
using namespace std;

int main() {
/*  
   --------- Number Hashing --------

    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) cin >> arr[i];

    //precompute
    int hash[13]{0};
    for (int i = 0; i < size; i++) hash[arr[i]] += 1;

    int query;
    cin >> query;
    while (query--) {
        int number;
        cin >> number;
        //fetch
        cout << hash[number] << endl;
    }

5
1 3 2 1 3
5
1
4
2
3
12 

    --------------- End ------------
*/

/* ------- Character hashing ------

    string str;
    cin >> str;

    int hash[256]{0};
    for (int i = 0; i < str.size(); i++) hash[str[i]] += 1;

    int query;
    cin >> query;
    while (query--) {
        char input;
        cin >> input;
        //fetch
        cout << hash[input - 'a'] << endl;
    }

abcdabehf
5
a
g
h
b
c

    --------------- End ----------------- */

    int num;
    cin >> num;

    int arr[num];
    unordered_map<int, int> mpp;
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
        mpp[arr[i]]++;
    }

    int q;
    cin >> q;
    while(q--) {
        int number;
        cin >> number;
        //fetch
        cout << mpp[number] << endl;
    }

    return 0;
}
