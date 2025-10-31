/*
Problem Name: Tree Distances II
Problem Link: https://cses.fi/problemset/task/1133
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200001;
vector<ll> adj[N];
ll subtree[N], n, d[N];
 
void dfs(int u, int p) {
    subtree[u] = 1;
    for(auto v : adj[u]) {
        if(v == p)continue;
        d[v] = d[u] + 1;
        dfs(v, u);
        subtree[u] += subtree[v];
    }
}
ll ans[N];
void f(int u, int p) {
    for(auto v : adj[u]) {
        if(v == p)continue;
        ll now = ans[u] - (subtree[v]) + (n - (subtree[v]));
        ans[v] = now;
        f(v, u); 
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, -1);
        ll total = 0;
        for(int i = 1; i <= n; i++) {total+=d[i];}
        ans[1] = total;
        f(1, -1);
        for(int i = 1; i <= n; i++)cout << ans[i] << " ";
    }
    return 0;
}