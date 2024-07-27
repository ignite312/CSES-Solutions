/*
Problem Name: Distinct Routes
Problem Link: https://cses.fi/problemset/task/1711/
Idea: Max-flow
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 501;
vector<int> adj[N];
vector<bool> visited(1001);
vector<array<int, 2>> G[N];
int capacity[N][N];

int bfs(int s, int d, int n, vector<int> &p) {
    p.assign(n+1, -1);
    p[s] = 0;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    while(!q.empty()) {
        int u = q.front().first;
        int f =  q.front().second;
        q.pop();
        for(auto v : adj[u]) {
            if(p[v] == -1 && capacity[u][v]) {
                p[v] = u;
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
    vector<int> p;
    int flow;
    int ans = 0;
    while(flow = bfs(s, d, n, p)) {
        ans++;
        int v = d;
        vector<int> path;
        while(v != s) {
            path.push_back(v);
            int u = p[v];
            capacity[u][v] -= flow;
            capacity[v][u] += flow;
            v = u;
        }
    }
    return ans;
}

vector<int> path;
void dfs(int u, int n){
    path.push_back(u);
    if(u == n)return;
    for(auto p : G[u]){
        int v = p[0];
        int id = p[1];
        if(capacity[u][v] == 0 && !visited[id]){
            visited[id] = true;
            dfs(v, n);
            return;
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
            G[u].push_back({v, i});
            adj[u].push_back(v);
            adj[v].push_back(u);
            capacity[u][v] += 1;
        }

        int total = max_flow(1, n, n);
        cout << total << "\n";

        for(int k = 0; k < total; k++) {
            dfs(1, n);
            int sz = (int)path.size();
            cout << sz << "\n";
            for(int i = 0; i < sz; i++) {
                cout << path[i] << " ";
            }
            cout << "\n";
            path.clear();
        }
    }
    return 0;
}