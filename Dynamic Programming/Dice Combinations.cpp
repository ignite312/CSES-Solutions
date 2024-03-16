/*
Problem Name: Dice Combinations
Problem Link: https://cses.fi/problemset/task/1633/

DP Category:
Time Complexity:
Resource:

dp[i] = Number of ways to make sum i;
*/
#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 6; j++) {
                if (i - j >= 0) {
                    dp[i] = (dp[i] + dp[i - j]) % M;
                }
            }
        }
        cout << dp[n] << '\n';
    }
}