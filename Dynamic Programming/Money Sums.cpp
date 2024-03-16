/*
Problem Name: Money Sums
Problem Link: https://cses.fi/problemset/task/1745

DP Category:
Time Complexity: O(n*n*1000)
Resource:

dp[i][j] = is it possible to make the sum equal to j by using coin from 1 to i
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
        int n;
        cin >> n;
        int mx_sum = n * 1000;
        vector<int> coin(n+1);
        vector<vector<bool>> dp(n + 1, vector<bool>(mx_sum + 1, false));
        for (int i = 1; i <= n; i++)
            cin >> coin[i];
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= mx_sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - coin[i] >= 0 && dp[i - 1][j - coin[i]])
                    dp[i][j] = true;
            }
        }
        vector<int> ans;
        for (int i = 1; i <= mx_sum; i++)
            if (dp[n][i])
                ans.push_back(i);
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto ele : ans)
            cout << ele << " ";
        cout << "\n";
    }
    return 0;
}
