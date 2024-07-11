/*
Problem Name: Dice Probability
Problem Link: https://cses.fi/problemset/task/1725/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<vector<double>> dp(n+1, vector<double>(n*6+1, 0));
        dp[0][0] = 1.0;
        for(int i = 1; i <= n; i++) {
            for(int j = n*6; j >= 1; j--) {
                for(int k = 1; k <= 6; k++) {
                    if(j-k >= 0) {
                        dp[i][j] += dp[i-1][j-k]*(1/6.0);
                    }
                }
            }
        }
        double ans = 0;
        for(int i = a; i <= b; i++) {
            ans+=dp[n][i];
        }
        cout << fixed << setprecision(6) << ans << "\n";
    }
    return 0;
}