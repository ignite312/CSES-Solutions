/*
Problem Name: Coin Combinations II
Problem Link: https://cses.fi/problemset/task/1636

DP Category:
Time Complexity:
Resource:

dp[i] = Number of distinct ordered ways ways to make sum i;
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
        int n, desired_sum;
        cin >> n >> desired_sum;
        vector<int> coin(n+1);
        vector<int> dp(desired_sum + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> coin[i];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= desired_sum; j++) {
                if (j - coin[i] >= 0) {
                    dp[j] = (dp[j] + dp[j - coin[i]]) % M;
                }
            }
        }
        cout << dp[desired_sum] << '\n';
    }
}