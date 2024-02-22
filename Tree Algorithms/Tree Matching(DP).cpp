/*
Dynamic Programming Approach
https://usaco.guide/gold/dp-trees?lang=cpp
https://youtu.be/YbFcHmpM60k?t=3930
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
vector<int> adj[N+1];
int dp[N+1][2];
 
void dfs(int u, int p) {
    for(auto v : adj[u]) {
        if(v == p)continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
    for(auto v : adj[u]) {
        if(v == p)continue;
        dp[u][1] = max(dp[u][1], dp[v][0] + 1 + dp[u][0] -
                                         max(dp[v][0], dp[v][1]));
    }
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
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, -1);
        cout << max(dp[1][0], dp[1][1]) << '\n';
    }
    return 0;
}