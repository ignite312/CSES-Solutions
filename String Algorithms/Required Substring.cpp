/*
Problem Name: Required Substring
Problem Link: https://cses.fi/problemset/task/1112/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;
int n, m;
/*
dp[i][j] = Total number of strings of length i where the suffix of length j matches
the prefix of the pattern string s.
*/
int dp[1001][101];
/*
mx_len[i][c] = the maximum length of the suffix of the string formed by 
adding the character c to the prefix of length i of the given pattern s, 
such that this suffix is also a prefix of s.
*/
int mx_len[100][26];

int bigPow(ll b, ll p, const int M) {
    int ans = 1;
    b %= M;
    if (b < 0) b += M;
    while (p) {
        if (p & 1) ans = ans * b % M;
        b = b * b % M;
        p >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int m = (int)s.size();
        for(int j = 0; j < m; j++) {
          for(int c = 0; c < 26; c++) {
            string pfx = s.substr(0, j);
            pfx+=c+'A';
            for(int k = 0; k < pfx.size(); k++) {
              if(pfx.substr(k) == s.substr(0, pfx.size()-k)) {
                mx_len[j][c] = max(mx_len[j][c], (int)pfx.size()-k);
                break;
              }
            }
          }
        }
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
          for(int j = 0; j < m; j++) {
            for(int c = 0; c < 26; c++) {
              dp[i][mx_len[j][c]] = (dp[i][mx_len[j][c]] + dp[i-1][j]) % M;
            }
          }
        }
        int ans = bigPow(26, n, M);
        for(int j = 0; j < m; j++) {
          ans = (ans  - dp[n][j] + M) % M;
        }
        cout << ans << "\n";
    }
    return 0;
}