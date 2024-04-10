/*
Problem Name: Stick Lengths
Problem Link: https://cses.fi/problemset/task/1074/
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
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        if(n % 2 != 0) {
            int median = v[n/2];
            ll ans = 0;
            for(int i = 0; i < n; i++) {
                ans+=abs(v[i] - median);
            }
            cout << ans << "\n";
        }else {
            int median1 = v[n/2], median2 = v[n/2-1];
            ll ans1 = 0;
            for(int i = 0; i < n; i++) {
                ans1+=abs(v[i] - median1);
            }
            ll ans2 = 0;
            for(int i = 0; i < n; i++) {
                ans2+=abs(v[i] - median2);
            }
            cout << min(ans1, ans2) << "\n";
        }
    }
    return 0;
}