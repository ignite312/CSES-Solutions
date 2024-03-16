/*
Problem Name: Grid Paths
Problem Link: https://cses.fi/problemset/task/1638

DP Category:
Time Complexity:
Resource:

dp[i][j] = Number of ways to reach (i, j)
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
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = 1; // beacuse we can reach (0, 0) in 1 way
        for (int i = 0; i < n; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < n; j++) {
                if (line[j] == '.') {
                    if (i > 0) {
                        (dp[i][j] += dp[i - 1][j]) %= M;
                    }
                    if (j > 0) {
                        (dp[i][j] += dp[i][j - 1]) %= M;
                    }
                }
                else dp[i][j] = 0;
            }
        }
        cout << dp[n - 1][n - 1] << "\n";
    }
}