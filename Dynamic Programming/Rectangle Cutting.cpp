/*
Problem Name: Rectangle Cutting
Problem Link: https://cses.fi/problemset/task/1744/

DP Category: 
Time Complexity: O(a*b)
Resource: 
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 500+1;
int dp[N+1][N+1];
 
int calculate(int a, int b) {
	if(a == b)return 0;
	if(dp[a][b] != -1)return dp[a][b];
	int ans = INT_MAX;
	for(int i = 1; i < a; i++) {
		int t_ans = calculate(i, b) + calculate(a-i, b) + 1;
		ans = min(ans, t_ans);
	}
	for(int i = 1; i < b; i++) {
		int t_ans = calculate(a, i) + calculate(a, b - i) + 1;
		ans = min(ans, t_ans);
	}
	return dp[a][b] = ans;
}
/*
// Iterative
int f(int a, int b) {
	vector<vector<int>> dp(a+1, vector<int>(b+1, 0));
	for(int i = 1; i <= a; i++) {
		for(int j = 1; j <= b; j++) {
			if(i == j) dp[i][j] = 0;
			else {
				dp[i][j] = INT_MAX;
				for(int k = 1; k < i; k++) {
					dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1); 
				}
				for(int k = 1; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1); 
				}
			}
		}
	}
	return dp[a][b];
}
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int a, b;
        cin >> a >> b;
        memset(dp, -1, sizeof(dp));
        cout << calculate(a, b) << "\n";
    }
	return 0;
}