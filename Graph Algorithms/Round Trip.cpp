/*
Problem Name: Round Trip
Problem Link: https://cses.fi/problemset/task/1669/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> adj[N + 1];
bool vis[N + 1], cycle_found;
int parent[N + 1], en, st;
 
void dfs(int u, int p) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (p == v) continue;
        if (!vis[v]) {
            parent[v] = u;
            dfs(v, u);
        } else {
            if (!cycle_found) en = u, st = v;
            cycle_found = true;
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) {
            if (!vis[i]) {
                parent[i] = -1;
                dfs(i, -1);
            }
        }
        if(!cycle_found) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        vector<int> path;
        path.push_back(st);
        path.push_back(en);
        int j = en;
        while(parent[j] != st) {
            path.push_back(parent[j]);
            j = parent[j];
        }
        path.push_back(st);
        cout << path.size() << "\n";
        for(int i = path.size() - 1; i >= 0; i--)cout << path[i] << " ";
    }
    return 0;
}