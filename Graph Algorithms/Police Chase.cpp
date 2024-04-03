/*
Problem Name: Police Chase
Problem Link: https://cses.fi/problemset/task/1695/
Idea: Max-flow min-cut
Complexity:
Resource: https://cp-algorithms.com/graph/edmonds_karp.html
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 500;
vector<int> adj[N+1];
int capacity[N+1][N+1];
 
int bfs(int s, int d, int n, vector<int> &parent) {
    parent.assign(n+1, -1);
    parent[s] = 0;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    while(!q.empty()) {
        int u = q.front().first;
        int f =  q.front().second;
        q.pop();
        for(auto v : adj[u]) {
            if(parent[v] == -1 && capacity[u][v]) {
                parent[v] = u;
                int n_f = min(f, capacity[u][v]);
                if(v == d)return n_f;
                q.push({v, n_f});
            }
        }
    }
    return 0;
}
int max_flow(int s, int d, int n) {
    int mx_flow = 0;
    vector<int> parent;
    int flow;
    while(flow = bfs(s, d, n, parent)) {
        mx_flow+=flow;
        int now = d;
        while(now != s) {
            int prev = parent[now];
            capacity[prev][now] -= flow;
            capacity[now][prev] += flow;
            now = prev;
        }
    }
    return mx_flow;
}
bool visited[N+1];
void dfs(int u) {
    visited[u] = true;
    for(auto v : adj[u])if(!visited[v] && capacity[u][v])dfs(v);
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
            adj[v].push_back(u);
            capacity[u][v] += 1;
            capacity[v][u] += 1;
        }
        cout << max_flow(1, n, n) << "\n";
        dfs(1);
        for(int u = 1; u <= n; u++) {
            if(visited[u]) {
                for(auto v : adj[u]) {
                    if(!visited[v]) {
                        cout << u << " " << v << "\n";
                    }
                }
            }
        }
    }
    return 0;
}