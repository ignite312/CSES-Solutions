/*
Problem Name: Distance Queries
Problem Link: https://cses.fi/problemset/task/1135
Idea: Lowest Common Ancestor using Binary Lifting
Complexity: 
Resource: https://www.youtube.com/watch?v=dOAxrhAUIhA
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
const int LOG = 18; // LOG = ceil(log2(N))
vector<int> adj[N+1];
int up[N+1][LOG], depth[N+1]; // up[v][j] is the 2^j-th Anchestor of node v
 
void ancestor(int u, int p) {
    for(auto v : adj[u]) {
        if(v == p)continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for(int j = 1; j < LOG; j++)up[v][j] = up[up[v][j-1]][j-1];
        ancestor(v, u);
    }
}
int get_lca(int a, int b) {
    if(depth[a] < depth[b])swap(a, b);
    int k = depth[a] - depth[b];
    for(int i = LOG-1; i >= 0; i--)
        if(k & (1 << i))
            a = up[a][i];
 
    if(a == b)
        return a;
 
    for(int i = LOG-1; i >= 0; i--) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ancestor(1, -1);
        while(q--) {
            int a, b;
            cin >> a >> b;
            int lca = get_lca(a, b);
            cout << depth[a] + depth[b] - 2*depth[lca] << "\n";
        }
    }
    return 0;
}