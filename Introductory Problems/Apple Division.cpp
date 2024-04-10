/*
Problem Name: Apple Division
Problem Link: https://cses.fi/problemset/task/1623/
Idea:
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
        int n;
        cin >> n;
        vector<ll> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        ll ans = LLONG_MAX;
        for(int mask = 0; mask < (1 << n); mask++) {
            ll sum1 = 0, sum2 = 0;
            for(int j = 0; j < n; j++) {
                if(mask & (1 << j)) {
                    sum1+=v[j];
                }else {
                    sum2+=v[j];
                }
            }
            ans = min(abs(sum1-sum2), ans);
        }
        cout << ans << "\n";
    }
    return 0;
}