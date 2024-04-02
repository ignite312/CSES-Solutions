/*
Problem Name: Maximum Subarray Sum II
Problem Link: https://cses.fi/problemset/task/1644/
Idea: Prefix Sum
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
        int n, A, B;
        cin >> n >> A >> B;
        vector<ll> prefix(n+1, 0);
        for(int i = 1; i <= n; i++) {
            ll x;
            cin >> x;
            prefix[i]+=prefix[i-1] + x;
        }
        ll ans = LLONG_MIN;
        multiset<ll> pfx_check;
 
        for(int i = A; i <= n; i++) {
            pfx_check.insert(prefix[i-A]);
            if(i > B)pfx_check.erase(pfx_check.find(prefix[i-B-1]));
            ans = max(ans, prefix[i] - *pfx_check.begin());
        }
        cout << ans << "\n";
    }
    return 0;
}
