/*
Not Well Optimized
Complexity: 
Similar Problem: https://codeforces.com/contest/1822/problem/F
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
vector<int> adj[N+1];
int height[N+1], dist[N+1]; 
 
void dfs1(int u, int p) {
    for(auto v : adj[u]) {
        if(v == p)continue;
        dfs1(v, u);
        height[u] = max(height[u], height[v] + 1);
    }
}
void dfs2(int u, int p) {
    vector<int> ht;
    for(auto v : adj[u]) {
        if(v == p)continue;
        ht.push_back(height[v]);
    }
    sort(ht.rbegin(), ht.rend());
    for(auto v : adj[u]) {
        if(v == p)continue;
        if(ht.size()  >= 2) dist[v] = max(dist[u]+1, (height[v] == ht[0] ? ht[1] : ht[0]) + 2);
        else if(ht.size() == 1) dist[v] = dist[u] + 1;
        dfs2(v, u);
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  while(tt--) {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    for(int i = 1; i <= n; i++)cout << max(height[i], dist[i]) << " ";
  }
}