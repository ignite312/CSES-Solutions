/*
Problem Name: Array Description
Problem Link: https://cses.fi/problemset/task/1746

DP Category: 
Time Complexity:
Resource:

Here dp[i][v] = number of ways to fill the array up to index i, if x[i] = v
*/
#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	tt = 1;
    // cin >> tt;
	while(tt--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> dp(n, vector<int> (m+1, 0));
		int x;
		cin >> x;
		if(x != 0)dp[0][x] = 1;
		else {for(int i = 1; i <= m; i++)dp[0][i] = 1;}
		for(int i = 1; i < n; i++) {
			cin >> x;
			if(x != 0) {
				for(int k : {x-1, x, x+1}) {
					if(k >= 1 && k <= m) {
						dp[i][x] = (dp[i][x] + dp[i-1][k]) % M;
					}
				}
			}else {
				for(int j = 1; j <= m; j++) {
					for(int k : {j-1, j, j+1}) {
						if(k >= 1 && k <= m) {
							dp[i][j] = (dp[i][j] + dp[i-1][k]) % M;
						}
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= m; i++) {
			ans = (ans + dp[n-1][i]) % M;
		}
		cout << ans << "\n";
	}
	return 0;