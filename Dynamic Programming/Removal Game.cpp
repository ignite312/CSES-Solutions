/*
Problem Name: Removal Game
Problem Link: https://cses.fi/problemset/task/1097

DP Category:
Time Complexity: O(N^2)
Resource:

# Here dp[l][r] =  score_player1 - score_player2. That means Score difference between player1 and player2 if the game played in the interval l to r.
and the player1 start the game.
# Here dp[l][r] =  score_player2 - score_player1. That means Score difference between player2 and player1 if the game played in the interval l to r.
and the player2 start the game.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<vector<ll>> dp(n, vector<ll>(n, 0));
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l; r < n; r++) {
                if (l == r) {
                    dp[l][r] = a[l];
                }
                else {
                    dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
                }
            }
        }
        cout << (dp[0][n - 1] + sum) / 2 << "\n";
    }
    return 0;
}