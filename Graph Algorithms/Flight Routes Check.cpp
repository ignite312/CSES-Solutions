/*
Problem Name: Flight Routes Check
Problem Link: https://cses.fi/problemset/task/1682/
Idea:
Complexity:
Resource: https://usaco.guide/problems/cses-1682-flight-routes-check/solution
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 200000;
vector<int> adj[N+1], _adj[N+1];
bool visited[N+1];
 
void dfs1(int u) {
    visited[u] = true;
    for(auto v : adj[u]) {
        if(!visited[v]) {
            dfs1(v);
        }
    }
}
void dfs2(int u) {
    visited[u] = true;
    for(auto v : _adj[u]) {
        if(!visited[v]) {
            dfs2(v);
        }
    }
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
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            _adj[v].push_back(u);
        }
        dfs1(1);
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                cout << "NO\n";
                cout << "1 " << i << "\n";
                return 0;
            }
            visited[i] = false;
        }
        dfs2(1);
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                cout << "NO\n";
                cout << i << " 1" << "\n";
                return 0;
            }
            visited[i] = false;
        }
        cout << "YES\n";
    }
    return 0;
}