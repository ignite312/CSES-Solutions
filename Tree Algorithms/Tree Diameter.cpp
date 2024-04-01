/*
Complexity: 
https://codeforces.com/contest/1881/problem/F
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
vector<int> adj[N+1];
int depth[N+1];
 
void dfs(int u, int p) {
    for(auto v : adj[u]) {
        if(v == p)continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  // cin >> tt;
  tt = 1;
  while(tt--) {
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    int mx_node = -1, dept_now = -1;
    for(int i = 1; i <= n; i++) {
        if(depth[i] > dept_now) {
            mx_node = i;
            dept_now = depth[i];
        }
        depth[i] = 0;
    }
    dfs(mx_node, -1);
    mx_node = -1, dept_now = -1;
    for(int i = 1; i <= n; i++) {
        if(depth[i] > dept_now) {
            mx_node = i;
            dept_now = depth[i];
        }
    }
    cout << dept_now << "\n";
  }
}