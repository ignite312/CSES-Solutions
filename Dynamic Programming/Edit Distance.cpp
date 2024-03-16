/*
Problem Name: Edit Distance
Problem Link: https://cses.fi/problemset/task/1639/

DP Category:
Time Complexity:
Resource: https://www.youtube.com/watch?v=F75bJEJfLww

dp[i][j] = number of operations needed to make the n.substr(1, i) equals to m.substr(1, j)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--) {
        string n, m;
        cin >> n >> m;
        int ln_n = (int)n.length();
        int ln_m = (int)m.length();
        vector<vector<int>> dp(ln_n + 1, vector<int>(ln_m + 1, 0));
        for (int i = 1; i <= ln_n; i++)
            dp[i][0] = i;
        for (int i = 1; i <= ln_m; i++)
            dp[0][i] = i;
        for (int i = 1; i <= ln_n; i++) {
            for (int j = 1; j <= ln_m; j++) {
                if (n[i - 1] == m[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
        cout << dp[ln_n][ln_m] << '\n';
    }
    return 0;
}