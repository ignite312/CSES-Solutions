/*
Problem Name: High Score
Problem Link: https://cses.fi/problemset/task/1673/
Idea: Bellman Ford Contain Positive Cycle
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = LLONG_MAX;
const int N = 2500;
vector<tuple<int, int, ll>> edges;
bool mark[N+1], vis[N+1];
vector<int> adj[N+1];
vector<ll> d(N+1, -INF);
 
void BellmanFord(int s, int n) {
    d[s] = 0;
    for(int i = 0; i < n-1; i++) {
        bool any = false;
        for(auto[u, v, wt] : edges) {
            if(d[u] > -INF) {
                if(d[u] + wt > d[v]) {
                    d[v] = d[u] + wt;
                    any = true;
                }
            }
        }
        if(!any)break;
    }
    for(auto[u, v, wt] : edges)
        if(d[u] > -INF)
            if(d[u] + wt > d[v])
                mark[v] = true; // Mark all the node that are responsible for positive cycle
}
void dfs(int u) {
    vis[u] = true;
    for(auto v : adj[u])
        if(!vis[v])
            dfs(v);
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
            ll wt;
            cin >> u >> v >> wt;
            adj[u].push_back(v);
            edges.emplace_back(u, v, wt);
        }
        BellmanFord(1, n);
        for(int i = 1; i <= n; i++) {
            if(mark[i]) {
                for(int i = 0; i <= n; i++)vis[i] = false;
                // Run a dfs from the node that are responsible for positive cycle
                // If we can reach node n from this that will make arbitrarily large score
                dfs(i); 
                if(vis[n]) {
                    cout << "-1";
                    return 0;
                }
            }
        }
        cout << d[n] << "\n";
    }
    return 0;
}
