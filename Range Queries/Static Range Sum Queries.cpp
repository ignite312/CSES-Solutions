/*
Problem Name: Static Range Sum Queries
Problem Link: https://cses.fi/problemset/task/1646/
Idea: Prefix Sum
Complexity: 
Resource: 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+1;
ll pfx[N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++) {
            ll x;
            cin >> x;
            pfx[i] = pfx[i-1] + x;
        }
        while(q--) {
            int l, r;
            cin >> l >> r;
            cout << pfx[r] - pfx[l-1] << "\n";
        }
    }
    return 0;
}