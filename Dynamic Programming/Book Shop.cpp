/*
Problem Name: Book Shop
Problem Link: https://cses.fi/problemset/task/1158/

DP Category: 0-1 Knapsack
Time Complexity:
Resource:

Here dp[i][j] = maximum number of pages you can buy among the first 1 to i index and  at price j
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
        int n, limit;
        cin >> n >> limit;
        vector<int> price(n+1), pages(n+1);
        vector<vector<int>> dp(n + 1, vector<int>(limit + 1, 0));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> price[i];
        for (int i = 1; i <= n; i++)
            cin >> pages[i];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= limit; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - price[i] >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i]] + pages[i]);
                }
            }
        }
        cout << dp[n][limit] << "\n";
    }
}