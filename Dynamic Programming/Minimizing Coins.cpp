/*
Problem: https://cses.fi/problemset/task/1634
DP Category:
Time Complexity:

Resource:
dp[i] = minimum number of coins needed to make sum i
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
        int n, desired;
        cin >> n >> desired;
        vector<int> coin(n);
        vector<int> dp(desired + 1, 1e9);
        for (int i = 0; i < n; i++)
            cin >> coin[i];
        dp[0] = 0;
        for (int i = 1; i <= desired; i++) {
            for (int j = 1; j <= n; j++) {
                if (i - coin[j - 1] >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coin[j - 1]]);
                }
            }
        }
        cout << (dp[desired] == 1e9 ? -1 : dp[desired]) << "\n";
    }
}
