/*
Problem: https://cses.fi/problemset/task/1635
DP Category:
Time Complexity:

Resource:
dp[i] = Number of distinct ways to make sum i;
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
        vector<int> coin(n);
        vector<int> dp(desired_sum + 1, 0);
        for (int i = 0; i < n; i++)
            cin >> coin[i];
        dp[0] = 1;
        for (int i = 1; i <= desired_sum; i++) {
            for (int j = 1; j <= n; j++) {
                if (i - coin[j - 1] >= 0) {
                    dp[i] = (dp[i] + dp[i - coin[j - 1]]) % M;
                }
            }
        }
        cout << dp[desired_sum] << '\n';
    }
}