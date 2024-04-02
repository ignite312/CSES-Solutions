/*
Problem Name: Array Division
Problem Link: https://cses.fi/problemset/task/1085/
Idea: Binary Search + Sliding Window
Complexity:
Resource: https://usaco.guide/problems/cses-1085-array-division/solution
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 1;
int a[N+1], n, k;
 
bool is_possible(ll mid) {
    int cnt = 0;
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        sum+=a[i];
        if(sum > mid) {
            if(sum-a[i] != 0 && sum - a[i] <= mid) {
                cnt++;
                sum = a[i];
            }else return false;
        }
    }
    if(sum <= mid)cnt++;
    else return false;
    if(cnt <= k)return true;
    return false;
}
ll binarySearch(ll lo, ll hi) {
    ll ans = -1;
    while(lo <= hi) {
        ll mid = lo + (hi-lo)/2;
        if(is_possible(mid)) {
            ans = mid, hi = mid - 1;
        }else lo = mid + 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << binarySearch(0LL, (ll)1e9*(ll)2e5);
    }
    return 0;
}