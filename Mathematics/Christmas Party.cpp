/*
Problem Name: Christmas Party
Problem Link: https://cses.fi/problemset/task/1717/
Idea: f(n) = (f(n-1) + f(n-2))*(n-1)
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for(int i = 3; i <= n; i++) {
            dp[i] = (((dp[i-1] + dp[i-2]) % M)*1LL*(i-1)) % M;
        }
        cout << dp[n] << "\n";
    }
    return 0;
}