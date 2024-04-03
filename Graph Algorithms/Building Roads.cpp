/*
Problem Name: Building Roads
Problem Link: https://cses.fi/problemset/task/1666/
Idea: Connected Component
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> adj[N+1];
bool vis[N+1];
 
void dfs(int u) {
    vis[u] = true;
    for(auto v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
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
        dfs(i);
        ans.push_back(i);
    }
  }
  if(ans.size() == 1)cout << "0\n";
  else {
    cout << ans.size() - 1 << "\n";
    for(int i = 1; i < ans.size(); i++) {
        cout << ans[0] << " " << ans[i] << "\n";
    }
  }
  return 0;
}