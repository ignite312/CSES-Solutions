/*
Problem Name: Message Route
Problem Link: https://cses.fi/problemset/task/1667/
Idea: BFS
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> adj[N+1];
int parent[N+1];
bool vis[N+1];
 
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
  queue<int> q;
  q.push(1);
  vis[1] = true;
  bool ok = false;
  while(!q.empty()) {
    int u = q.front();
    if(u == n)ok = true;
    q.pop();
    for(auto v : adj[u]) {
        if(!vis[v]) {
            vis[v] = true;
            q.push(v);
            parent[v] = u;
        }
    }
  }
  if(!ok) {
    cout << "IMPOSSIBLE" << "\n";
    return 0;
  }
  vector<int> ans;
  ans.push_back(n);
  while(1) {
    if(n == 1)break;
    ans.push_back(parent[n]);
    n = parent[n];
  }
  cout << ans.size() << "\n";
  for(int i = ans.size() - 1;  i >= 0; i--) {
    cout << ans[i] << " ";
  }
  return 0;
}