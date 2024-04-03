/*
Problem Name: Flight Discount
Problem Link: https://cses.fi/problemset/task/1195/
Idea: Dijkstra
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100000;
const ll INF = LLONG_MAX;
vector<pair<int, ll>> adj[N+1], _adj[N+1];
 
vector<ll> dijkstra(int s) {
    vector<bool> vis(N+1, false);
    vector<ll> d(N+1, INF);
    set<pair<ll, int>> st;
    st.insert({0, s});
    d[s] = 0;
    while(st.size() > 0) {
        auto node = *st.begin();
        int u = node.second;
        st.erase(st.begin());
        if(vis[u])continue;
        vis[u] = true;
        for(auto child : adj[u]) {
            int v = child.first;
            ll wt = child.second;
            if(d[u] + wt  < d[v]) {
                d[v] = d[u] + wt;
                st.insert({d[v], v});
            }
        }
    }
    return d;
}
vector<ll> dijkstra2(int s) {
    vector<bool> vis(N+1, false);
    vector<ll> d(N+1, INF);
    set<pair<ll, int>> st;
    st.insert({0, s});
    d[s] = 0;
    while(st.size() > 0) {
        auto node = *st.begin();
        int u = node.second;
        st.erase(st.begin());
        if(vis[u])continue;
        vis[u] = true;
        for(auto child : _adj[u]) {
            int v = child.first;
            ll wt = child.second;
            if(d[u] + wt  < d[v]) {
                d[v] = d[u] + wt;
                st.insert({d[v], v});
            }
        }
    }
    return d;
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
        _adj[v].push_back({u, wt});
    }
    vector<ll> d_a, d_b;
    d_a = dijkstra(1); // Calculate Shortest distance from 1 to all other node
    d_b = dijkstra2(n);// Calculate Shortest distance from n to all other node
    ll mn = INF;
    for(int i = 1; i <= n; i++) {
        for(auto child : adj[i]) {
            if(d_a[i] != INF && d_b[child.first] != INF) {
                mn = min(mn, d_a[i] + d_b[child.first] + child.second/2);
            }
        }
    }
    cout << mn << "\n";
  }
  return 0;
}