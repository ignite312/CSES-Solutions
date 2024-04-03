/*
Problem Name: Building Teams
Problem Link: https://cses.fi/problemset/task/1668/
Idea: Bipartite Graph Checking
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> adj[N+1];
bool vis[N+1], is_bipartite = true;
int color[N+1];
 
void dfs(int u) {
    vis[u] = true;
    for(auto v : adj[u]) {
        if(!vis[v]) {
            color[v] = color[u]^1;
            dfs(v);
        }else {
            if(color[u] == color[v])is_bipartite = false;
        }
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> ans;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
        color[i] = 0;
        dfs(i);
    }
  }
  if(!is_bipartite)cout << "IMPOSSIBLE\n";
  else {
    for(int i = 1; i <= n; i++) {
        if(color[i])cout << "1 ";
        else cout << 2 << " ";
    }
  }
}