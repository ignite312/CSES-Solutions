/*
Problem Name: Flight Routes
Problem Link: https://cses.fi/problemset/task/1196/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100000;
vector<pair<int, ll>> adj[N+1];
priority_queue<ll> d[N+1];
 
void dijkstra(int s, int k) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, s});
    d[1].push(0); // 
    while(pq.size()) {
        auto node = pq.top();
        ll d_u = node.first;
        int u = node.second;
        pq.pop();
        if(d_u > d[u].top())continue; // When we replaced some greater route with smaller one and d[u].size == k here
        for(auto child : adj[u]) {
            int v = child.first;
            ll wt = child.second;
            if(d[v].size() < k) { // Check if total found routes are less than k or not
                d[v].push(d_u + wt);
                pq.push({d_u + wt, v});
            }else if(d_u + wt < d[v].top()) { // Check new route has smaller distance than previously selected route
                d[v].pop();
                d[v].push(d_u + wt);
                pq.push({d_u + wt, v});
            }
        }
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  while(tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v;
        ll price;
        cin >> u >> v >> price;
        adj[u].push_back({v, price});
    }
    dijkstra(1, k);
    vector<ll> ans;
    while(!d[n].empty()) {
        ans.push_back(d[n].top());
        d[n].pop();
    }
    reverse(ans.begin(), ans.end());
    for(auto ele : ans)cout << ele << " ";
  }
  return 0;
}