/*
Problem Name: Course Schedule
Problem Link: https://cses.fi/problemset/task/1679/
Idea: Topological Sort + Cycle Finding in Directed Graph
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> adj[N+1], parent(N+1);
vector<int> color(N+1), ans;
 
bool dfs(int u) {
    color[u] = 1;
    for(auto v : adj[u]) {
        if(!color[v]){if(dfs(v)) return true;}
        else if(color[v] == 1)return true;
    }
    ans.push_back(u);
    color[u] = 2;
    return false;
}
bool checkCycle(int n) {
    for(int i = 1; i <= n; i++)
        if(!color[i] && dfs(i))
            return true;
    return false;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    if(checkCycle(n))cout << "IMPOSSIBLE\n";
    else {
        for(auto ele : ans)cout << ele << " ";
            cout << "\n";
    }
  }
  return 0;
}