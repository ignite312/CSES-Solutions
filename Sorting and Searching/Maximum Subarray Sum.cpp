/*
Problem Name: Maximum Subarray Sum
Problem Link: https://cses.fi/problemset/task/1643/
Idea: Kadane Algorithm
Complexity:
Resource: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
Related Problem: https://codeforces.com/contest/1946/problem/B
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
ll maxSubArraySum(vector<ll> v, ll n) {
    ll sum = v[0], mx = v[0];
 
    for (int i = 1; i < n; i++) {
        sum = max(sum+v[i], v[i]);
        mx = max(mx, sum);
    }
    return mx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << maxSubArraySum(v, n);
    }
    return 0;
}