/*
Problem Name: Factory Machines
Problem Link: https://cses.fi/problemset/task/1620/
Idea: Binary Search
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool is_possible(ll mid, vector<ll> &times, ll t) {
    ll cnt = 0;
    for(int i = 0; i < (int)times.size(); i++) {
        cnt+=(mid/times[i]);
        if(cnt >= t)return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        ll t;
        cin >> n >> t;
        vector<ll> times(n);
        for(int i = 0; i < n; i++) {
            cin >> times[i];
        }
        ll lo = 1, hi = 1e18;
        ll ans = -1;
        while(lo <= hi) {
            ll mid = lo + (hi-lo)/2;
            if(is_possible(mid, times, t)) {
                ans = mid;
                hi = mid - 1;
            }else lo = mid + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}