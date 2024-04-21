/*
Problem Name: Coin Collector
Problem Link: https://cses.fi/problemset/task/1686/
Idea: Strongly Connected Componenet
Complexity:
Resource: https://usaco.guide/problems/cses-1686-coin-collector/solution
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct SCC {
    // 1-base indexing
    int n;
    vector<vector<int>> adj, radj;
    vector<int> todo, comps, id;
    vector<bool> vis;
    void init(int _n) {
        n = _n;
        adj.resize(n+1), radj.resize(n+1), id.assign(n+1, -1), vis.resize(n+1);
    }
    void build(int x, int y) { adj[x].push_back(y), radj[y].push_back(x); }
    void dfs(int x) {
        vis[x] = 1;
        for(auto y : adj[x]) if (!vis[y]) dfs(y);
        todo.push_back(x);
    }
    void dfs2(int x, int v) {
        id[x] = v;
        for(auto y : radj[x]) if (id[y] == -1) dfs2(y, v);
    }
    void gen() {
        for(int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
        reverse(todo.begin(), todo.end());
        for(auto x : todo) if (id[x] == -1) {
            dfs2(x, x);
            comps.push_back(x);
        }
    }
} scc;

const int N = 100000;
ll group[N+1], dp[N+1];
vector<int> revgraph[N+1];

ll solve(int u) {
    if(dp[u])return dp[u];

    dp[u] = group[u];
    for(auto v : revgraph[u]) {
        dp[u] = max(dp[u], group[u] + solve(v));
    }
    return dp[u];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        scc.init(n);
        vector<ll> coins(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> coins[i];
        }
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            scc.build(u, v);
        }
        scc.gen();
        for(int i = 1; i <= n; i++) {group[scc.id[i]]+=coins[i];}
        for(int u = 1; u <= n; u++) {
            for(auto v : scc.adj[u]) {
                if(scc.id[u] != scc.id[v]) {
                    revgraph[scc.id[u]].push_back(scc.id[v]);
                }
            }
        }
        ll ans = 0;
        for(auto x : scc.comps) {
            ans = max(ans, solve(x));
        }
        cout << ans << "\n";
    }
    return 0;
}