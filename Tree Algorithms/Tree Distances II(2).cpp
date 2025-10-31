/*
Problem Name: Tree Distances I
Problem Link: https://cses.fi/problemset/task/1132
Idea: Tree rerooting
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200001;
vector<int> adj[N];
ll down[N], up[N], subtree[N]; 
int n;
void dfs1(int u, int p) {
    subtree[u] = 1;
    for(auto v : adj[u]) {
        if(v == p)continue;
        dfs1(v, u);
        subtree[u]+=subtree[v];
        down[u]+=(down[v]+subtree[v]);
    }
}
void dfs2(int u, int p) {
    ll pfx_sum = 0;
    ll pfx_subtree = 0;
    for(auto v : adj[u]) {
        if(v == p) {
            continue;
        }
        up[v] += pfx_sum + pfx_subtree*2;
        pfx_sum+=down[v];
        pfx_subtree+=subtree[v];
    }
    reverse(adj[u].begin(), adj[u].end());
    ll suff_sum = 0;
    ll suff_subtree = 0;
    for(auto v : adj[u]) {
        if(v == p) {
            continue;
        }
        up[v] += suff_sum + suff_subtree*2;
        suff_sum+=down[v];
        suff_subtree+=subtree[v];
    }
    for(auto v : adj[u]) {
        if(v == p) {
            continue;
        }
        up[v] += up[u] + (n-subtree[u]+1);
        dfs2(v, u);
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  // cin >> tt;
  while(tt--) {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    for(int i = 1; i <= n; i++)cout << down[i] + up[i] << " ";
  }
  return 0;
}