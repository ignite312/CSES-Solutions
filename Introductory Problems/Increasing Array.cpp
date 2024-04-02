/*
Problem Name: Increasing Array
Problem Link: https://cses.fi/problemset/task/1094/
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
        ll ans = 0;
        for(int i = 1; i < n; i++) {
            if(v[i] >= v[i-1])continue;
            ans+=v[i-1]-v[i];
            v[i] += v[i-1]-v[i];
        }
        cout << ans << "\n";
    }
    return 0;
}