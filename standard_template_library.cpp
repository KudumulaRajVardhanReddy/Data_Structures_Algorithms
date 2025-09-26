#include <bits/stdc++.h>
using namespace std;

//pairs

int main() {

    pair<int, pair<int, int>> a = {3, {4, 5}};
    cout << a.first << endl;
    cout << a.second.first << endl;
    cout << a.second.second << endl;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << arr[0].second;

    cout << endl;

    /* vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector<int>::iterator it = v.end();
    cout << *((it)--) << endl;
    cout << *(it) << endl;
    cout << *(it-1) << endl; */

    //Vectors

    cout << endl;

    vector<int> v1;

    v1.push_back(34);
    v1.push_back(35);
    v1.push_back(36);
    v1.push_back(37);
    v1.push_back(38);

    for (auto i = v1.begin(); i != v1.end(); i++) {
        cout << *(i) << endl;
    }
    
    cout << endl;

    for (auto i: v1) {
        cout << i << endl;
    }

    cout << endl;

    v1.erase(v1.begin(), v1.end());
    v1.insert(v1.begin(), 2, 5);

    for(auto i: v1) cout << i << endl;

    cout << endl;

    //lists
    list<int> ls;

    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);

    for(auto i: ls) {
        cout << i << endl;
    }

    cout << endl;

    //DQ -- first copy of lists mate, at least to see.

    //Stack - LIFO

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    //for (int i=0; i<2; i++) {
        cout << s.top() << endl;
    //}

    cout << endl;

    //Queues - FIFO

    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);

    cout << q.back() << endl;
    q.back() += q.front();
    cout << q.back() << endl;

    cout << endl;

    /* Priority_Queue 
       Largest Magnitude value
       will be in the top*/

    priority_queue<int> pq;

    pq.push(134);
    pq.push(312);
    pq.push(239);
    pq.push(303);

    cout << pq.top() << endl;

    pq.pop();

    cout << pq.top() << endl;

    cout << endl;

    /*
    Set - Sorted and Unique, 
    Just like sets in math 
    but stores sorted values
    */

    set<int> st;
    st.emplace(123);
    st.emplace(413);
    st.emplace(234);
    st.emplace(345);

    auto x = st.find(234);
    cout << *(x) << endl;
    auto y = st.find(413);

    st.erase(x, y);
    cout << endl;

    for(auto i: st) {
        cout << i << endl;
    }

    cout << endl;

    /*
    Multiset is set 
    that allows copies
    to exist
    */

    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);

    for(auto i: ms) {
        cout << i << endl;
    }

    cout << endl;

    ms.erase(ms.find(2));

    for(auto i: ms) {
            cout << i << endl;
    }

    cout << endl;

    /*
    Unordered set - 
    lower bound and upper 
    bound functions it doesn't
    store values in particular value
    */

    unordered_set<int> un_set;

    map<int, int> mpp;
    mpp[1] = 2;
    mpp[2] = 3;
    mpp[3] = 4;
    mpp[4] = 5;

    for(auto i: mpp) {
        cout << i.first << " : " << i.second << endl;
    }

    cout << endl;

    mpp.insert({9, 10});
    mpp.insert({11, 43});

    for(auto i: mpp) {
            cout << i.first << " : " << i.second << endl;
    }

    cout << endl;

    //Algorithms - Just Sorting Bruhhhhhhhhhhhhh

    int array[] = {34,1,2546,64,6467,45,443, 234};
    sort(array, array+8);

    for(auto i: array) {
        cout << i << endl;
    }

    return 0;
}
