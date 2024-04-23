/*
Problem Name: Restaurant Customers
Problem Link: https://cses.fi/problemset/task/1619/
Idea: Sweep line
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        set<int> pos;
        map<int, int> st, en;
        for(int i = 0; i < n; i++) {
            int ar, lv;
            cin >> ar >> lv;
            st[ar]++;
            en[lv+1]++;
            pos.insert(ar), pos.insert(lv+1);
        } 
        int ans = 0;
        int curr = 0;
        for(auto idx : pos) {
            curr-=en[idx];
            curr+=st[idx];
            ans = max(ans, curr);
        }
        cout << ans << "\n";
    }
    return 0;
}