/*
Problem Name: Missing Coin Sum
Problem Link: https://cses.fi/problemset/task/2183/
Idea: Greedy
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
        sort(v.begin(), v.end());
        ll sum = 0;
        for(int i = 0;  i < n; i++) {
            if(v[i] > sum+1) {
                cout << sum+1 << "\n";
                return 0;
            }
            sum+=v[i];
        }
        cout << sum + 1 << "\n";
    }
    return 0;
}