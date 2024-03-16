/*
Problem NameL Two Sets II
Problem Link: https://cses.fi/problemset/task/1093/

DP Category: Knapsack
Time Complexity: O(N^3)
Resource:

# Here dp[i][x] = number of ways to make sum x using subsets of the numbers 1 to i
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
        int total_sum = n * (n + 1) / 2;
        if (total_sum % 2 != 0) {
            cout << "0\n";
            return 0;
        }
        total_sum = total_sum / 2;
        vector<vector<int>> dp(n, vector<int>(total_sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i < n; i++){
            for (int j = 0; j <= total_sum; j++) {
                (dp[i][j] += dp[i - 1][j]) %= M;
                if (j - i >= 0)
                    (dp[i][j] += dp[i - 1][j - i]) %= M;
            }
        }
        cout << dp[n - 1][total_sum] << '\n';
    }
    return 0;
}