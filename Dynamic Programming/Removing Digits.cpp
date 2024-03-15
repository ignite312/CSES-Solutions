/*
Problem: https://cses.fi/problemset/task/1637
DP Category:
Time Complexity:

Resource:
dp[x] = Number of steps are required to make the number x;
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
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            string s = to_string(i);
            for(int j = 0; j < (int)s.size(); j++) {
                dp[i] = min(dp[i], dp[i - (s[j] - '0')] + 1);
            }
        }
        cout << dp[n] << "\n";
    }
}