/*
Problem Name: Counting Towers
Problem Link: https://cses.fi/problemset/task/2413/

DP Category:
Time Complexity:
Resource: https://www.youtube.com/watch?v=MxhA0bY31wM
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--) {
        vector<vector<ll>> dp(N + 1, vector<ll>(8, 0));
        for (int i = 0; i < 8; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < 8; j++) {
                if (j == 0 || j == 1 || j == 4 || j == 5 || j == 6) {
                    dp[i][j] = (dp[i - 1][0] + dp[i - 1][2] + dp[i - 1][4] +
                                dp[i - 1][5] + dp[i - 1][6]) % M;
                }
                else {
                    dp[i][j] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][7]) % M;
                }
            }
        }
        int q;
        cin >> q;
        while (q--) {
            int n;
            cin >> n;
            cout << (dp[n - 1][3] + dp[n - 1][1]) % M << "\n";
        }
    }
    return 0;
}