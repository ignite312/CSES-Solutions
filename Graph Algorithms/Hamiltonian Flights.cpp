/*
Problem Name: Hamiltonian Flights
Problem Link: https://cses.fi/problemset/task/1690/
Idea: Bitmask DP
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 20;
const int M = 1e9 + 7;
int dp[1 << N][N+1];
int n, m;
vector<int> adj[N+1];
 
int dfs(int u, int mask) {
    if(u == n) {
        if(__builtin_popcount(mask) == n)return 1;
        else return 0;
    }
    if(dp[mask][u] != -1)return dp[mask][u];
    int ways = 0;
    for(auto v : adj[u]) {
        if(!(mask & (1 << (v-1)))) {
            ways = (ways + dfs(v, mask | (1 << (v-1)))) % M;
        }
    }
    return dp[mask][u] = ways;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        memset(dp, -1, sizeof(dp));
        dfs(1, 1);
        cout << dp[1][1] << "\n";
    }
    return 0;
}
