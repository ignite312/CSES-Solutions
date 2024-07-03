/*
Problem Name: Nested Ranges Count
Problem Link: https://cses.fi/problemset/task/2169/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;

bool compare(array<int, 3> &a, array<int, 3> &b) {
    if(a[0]< b[0])return true;
    if(a[0] == b[0]) return (a[1] > b[1]);
    return false;
}
struct FenwickTree {
    // 0 base indexing
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<array<int, 3>> points(n);
        set<int> st;
        for(int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
            st.insert(points[i][1]);
            points[i][2] = i;
        }
        map<int, int> compress;
        int id = 0;
        for(auto x : st) {
            if(!compress[x]){compress[x] = id++;}
        }
        FenwickTree Ft(id);

        sort(points.begin(), points.end(), compare);
        vector<int> contained(n), contain(n);
        for(int i = 0; i < n; i++) {
            int _id = compress[points[i][1]];
            int cnt = Ft.sum(id-1) - Ft.sum(_id-1);
            contained[points[i][2]] = cnt;
            Ft.add(_id, 1);            
        }
        Ft = FenwickTree(id);
        for(int i = n-1; i >= 0; i--) {
            int _id = compress[points[i][1]];
            int cnt = Ft.sum(_id);
            contain[points[i][2]] = cnt;
            Ft.add(_id, 1);            
        }

        for(int i = 0; i < n; i++)cout << contain[i] << " ";
        cout << "\n";
        for(int i = 0; i < n; i++)cout << contained[i] << " ";
     }
    return 0;
}