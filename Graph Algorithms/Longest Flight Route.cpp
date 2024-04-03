/*
Problem Name: Longest Flight Route
Problem Link: https://cses.fi/problemset/task/1680/
Idea: BFS + In-degree
Complexity:
Resource:
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> adj[N+1];
int visited[N+1], in[N+1], parent[N+1], d[N+1];
 
void dfs(int u) {
    visited[u] = true;
    for(auto v : adj[u])if(!visited[v])dfs(v);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            in[v]++;
        }
        dfs(1);
        if(!visited[n]) cout << "IMPOSSIBLE\n";
        else {
            memset(d, -1, sizeof(d));
            d[1] = 0;
            queue<int> q;
            for(int i = 1; i <= n; i++) if(!in[i])q.push(i);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(auto v : adj[u]) {
                    if(d[u] != -1 && d[u] + 1 > d[v]) {
                        d[v] = d[u] + 1;
                        parent[v] = u;
                    }
                    in[v]--;
                    if(!in[v])q.push(v);
                }
            }
            cout << d[n] + 1 << "\n";
            vector<int> path;
            while(n != 1)path.push_back(n), n = parent[n];
            cout << "1 ";
            for(int i = (int)path.size()-1; i >= 0; i--)cout << path[i] << " ";
                cout << "\n";
        }
    }
    return 0;
}