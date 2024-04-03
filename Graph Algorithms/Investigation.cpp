/*
Problem Name: Investigation
Problem Link: https://cses.fi/problemset/task/1202/
Idea: Dijkstra
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100000;
const int M = 1e9 + 7;
const ll INF = LLONG_MAX;
vector<pair<int, ll>> adj[N+1];
vector<bool> vis(N+1);
vector<ll> d(N+1, INF);
int ways[N+1], mn[N+1], mx[N+1];
 
void dijkstra(int s) {
    set<pair<ll, int>> st;
    st.insert({0, s});
    d[s] = 0;
    ways[s] = 1;
    while(st.size() > 0) {
        auto node = *st.begin();
        int u = node.second;
        st.erase(st.begin());
        if(vis[u])continue;
        vis[u] = true;
        for(auto child : adj[u]) {
            int v = child.first;
            ll wt = child.second;
            if(d[u] + wt == d[v]) {
                ways[v] = (ways[u] + ways[v]) % M;
                mn[v] = min(mn[v], mn[u]+1);
                mx[v] = max(mx[v], mx[u]+1);
                // d[v] = d[u] + wt;
                st.insert({d[v], v});
            }
            if(d[u] + wt < d[v]) {
                ways[v] = ways[u];
                mn[v] = mn[u]+1;
                mx[v] = mx[u]+1;
                d[v] = d[u] + wt;
                st.insert({d[v], v});
            }
        }
    }
    return;
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
        ll wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    dijkstra(1);
    cout << d[n] << " " << ways[n] << " " << mn[n] << " " << mx[n] << "\n";
  }
}
