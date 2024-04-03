/*
Problem Name: Download Speed
Problem Link: https://cses.fi/problemset/task/1694/
Idea: Max-flow
Complexity:
Resource: https://cp-algorithms.com/graph/edmonds_karp.html
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 500;
vector<int> adj[N+1];
ll capacity[N+1][N+1];
 
ll bfs(int s, int d, int n, vector<int> &p) {
    p.assign(n+1, -1);
    p[s] = 0;
    queue<pair<int, ll>> q;
    q.push({s, LLONG_MAX});
    while(!q.empty()) {
        int u = q.front().first;
        ll f =  q.front().second;
        q.pop();
        for(auto v : adj[u]) {
            if(p[v] == -1 && capacity[u][v]) {
                p[v] = u;
                ll n_f = min(f, capacity[u][v]);
                if(v == d)return n_f;
                q.push({v, n_f});
            }
        }
    }
    return 0;
}
ll max_flow(int s, int d, int n) {
    ll mx_flow = 0;
    vector<int> p;
    ll flow;
    while(flow = bfs(s, d, n, p)) {
        mx_flow+=flow;
        int now = d;
        while(now != s) {
            int prev = p[now];
            capacity[prev][now] -= flow;
            capacity[now][prev] += flow;
            now = prev;
        }
    }
    return mx_flow;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int u, v;
            ll c;
            cin >> u >> v >> c;
            adj[u].push_back(v);
            adj[v].push_back(u);
            capacity[u][v] += c;
        }
        cout << max_flow(1, n, n) << "\n";
    }
    return 0;
}