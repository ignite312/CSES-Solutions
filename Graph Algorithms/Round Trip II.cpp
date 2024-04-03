/*
Problem Name: Round Trip II
Problem Link: https://cses.fi/problemset/task/1678/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> adj[N+1], parent(N+1);
vector<int> color(N+1);
int st, en;
 
bool dfs(int u) {
    color[u] = 1;
    for(auto v : adj[u]) {
        if(!color[v]) {
            parent[v] = u;
            if(dfs(v)) return true;
        }else if(color[v] == 1) {
            st = v, en = u;
            return true;
        }
    }
    color[u] = 2;
    return false;
}
void checkCycle(int n) {
    st = en = -1;
    for(int i = 1; i <= n; i++) {
        if(!color[i] && dfs(i)) {
            break;
        }
    }
    if(st == -1) cout << "IMPOSSIBLE\n";
    else {
        vector<int> path;
        path.push_back(st);
        for(int i = en; i != st; i = parent[i])path.push_back(i);
        path.push_back(st);
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for(auto i : path)cout << i << " ";
        cout << "\n";
    }
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
        adj[u].push_back(v);
    }
    checkCycle(n);
  }
  return 0;
}