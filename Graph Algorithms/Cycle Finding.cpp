/*
Problem Name: Cycle Finding
Problem Link: https://cses.fi/problemset/task/1197/
Idea: Bellman Ford Contain Negetive Cycle
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<tuple<int, int, ll>> edges;
 
void BellmanFord(int s, int n) {
    vector<ll> dist(n+1, 0);// No need to init INF here because there can be a negative cycle where you can't reach from node 1
                        // and the Graph is not necessarily connected
                        // Our concern is about to find negetive cycle not shortest distance
    vector<int> parent(n+1, -1);
    dist[s] = 0;
    int flag;
    for (int i = 0; i < n; i++) {
        flag = -1;
        for (auto[u, v, cost] : edges) {
            if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    parent[v] = u;
                    flag = v;
            }
        }
    }
    if (flag == -1)
        cout << "NO\n";
    else {
        int y = flag;
        for (int i = 0; i < n; ++i)
            y = parent[y];
 
        vector<int> path;
        for (int cur = y;; cur = parent[cur]) {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());
        cout << "YES\n";
        for (int u : path)
            cout << u << ' ';
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        ll cost;
        cin >> u >> v >> cost;
        edges.emplace_back(u, v, cost);
        // edges.emplace_back(v, u, cost); if undirected
    }
    BellmanFord(1, n);
  }
  return 0;
}