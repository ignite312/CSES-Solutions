/*
Problem Name: Finding a Centroid
Problem Link: https://cses.fi/problemset/task/2079
Idea: 
Complexity: 
Resource: https://usaco.guide/plat/centroid?lang=cpp
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
vector<int> adj[N];
int subtree[N], n;
 
void dfs(int u, int p) {
    subtree[u] = 1;
    for(auto v : adj[u]) {
        if(v == p)continue;
        dfs(v, u);
        subtree[u] += subtree[v];
    }
}
int getCentroid(int u, int p, int desired) {
    for(auto v : adj[u])
        if(v != p && subtree[v] > desired)
            return getCentroid(v, u, desired);
    return u;
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
        cout << getCentroid(1, -1, n/2) << "\n";
    }
    return 0;
}