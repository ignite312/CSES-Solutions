/*
Problem Name: Subarray Sums I
Problem Link: https://cses.fi/problemset/task/1660/
Idea: Pefix Sum
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
        ll ans = 0;
        ll pref_sum = 0;
        map<ll, int> check;
        check[0] = 1;
        for(int i = 0; i < n; i++) {
            pref_sum+=v[i];
            ans+=check[pref_sum-k];
            check[pref_sum]++;
        }
        cout << ans << "\n";
    }
    return 0;
}