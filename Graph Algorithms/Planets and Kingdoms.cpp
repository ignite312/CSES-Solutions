/*
Problem Name: Planets and Kingdoms
Problem Link: https://cses.fi/problemset/task/1683/
Idea: Strongly Connected Components
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct SCC {
    // 1-base indexing
    int n;
    int idx;
    vector<vector<int>> adj, radj;
    vector<int> todo, comps, id;
    vector<bool> vis;
    void init(int _n) {
        n = _n;
        idx = 0;
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
        int i = 0;
        for(auto y : radj[x]) if (id[y] == -1) dfs2(y, v);
    }
    void gen() {
        for(int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
        reverse(todo.begin(), todo.end());
        for(auto x : todo) if (id[x] == -1) {
            dfs2(x, ++idx);
            // comps.push_back(x);
        }
    }
} scc;

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
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            scc.build(u, v);
        }
        scc.gen();
        cout << scc.idx << "\n";
        for(int i = 1; i <= n; i++) {
            cout << scc.id[i] << " ";
        }
    }
    return 0;
}