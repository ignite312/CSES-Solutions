/*
Problem Name: Game Routes
Problem Link: https://cses.fi/problemset/task/1681/
Idea: DP + BFS + In-Degree
Complexity:
Resource:
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
const int M = 1e9 + 7;
vector<int> adj[N + 1];
int in[N + 1], dp[N + 1]; // Here dp[u] = total way to reach node u from 1
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            in[v]++;
        }
        dp[1] = 1;
        queue<int> q;
        for (int i = 1; i <= n; i++) if(!in[i])q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                dp[v] = (dp[v] + dp[u]) % M;
                in[v]--;
                if (!in[v]) q.push(v);
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
