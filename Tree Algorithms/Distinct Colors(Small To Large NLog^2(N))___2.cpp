/*
Small To Large(DSU on Tree)
NLog^2(N)
Resource: https://github.com/ignite312/CpStuff/tree/main/Tree/Small%20to%20Large%20Merging(DSU%20on%20Tree)
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int color[N+1], distinct[N+1];
vector<int> adj[N+1];
vector<set<int>> s(N+1);
 
void dfs(int u, int p) {
  s[u] = {color[u]};
  for (auto v: adj[u]) {
    if (v == p)  continue;
    dfs(v, u);
    if (s[u].size() < s[v].size()) {
      s[u].swap(s[v]);
    }
    for (auto x: s[v]) {
      s[u].insert(x);
    }
  }
  distinct[u] = s[u].size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
          cin >> color[i];
        }
        for(int i = 0; i < n-1; i++) {
          int u, v;
          cin >> u >> v;;
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
        dfs(1, -1);
        for(int i = 1; i <= n; i++)cout << distinct[i] << " ";
    }
    return 0;
}