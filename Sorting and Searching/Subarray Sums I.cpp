/*
Problem Name: Subarray Sums I
Problem Link: https://cses.fi/problemset/task/1660/
Idea: Sliding Window
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int ans = 0;
        ll sum = 0;
        int prev_idx = -1;
        for(int i = 0; i < n; i++) {
            sum+=v[i];
            while(sum > k) {
                sum-=v[++prev_idx];
            }
            if(sum == k) {
                ans++;
                sum-=v[++prev_idx];
            }
 
        }
        cout << ans << "\n";
    }
    return 0;
}
