/*
Problem Name: Finding a Centroid
Problem Link: https://cses.fi/problemset/task/2079
Idea: Subtree
Complexity: 
Resource: 
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
vector<int> adj[N];
int subtree[N], n;
int ans = -1;
 
void dfs(int u, int p) {
    subtree[u] = 1;
    bool is_centroid = true;
    for(auto v : adj[u]) {
        if(v == p)continue;
        dfs(v, u);
        subtree[u] += subtree[v];
        if(subtree[v] > n/2)is_centroid = false;
    }
    if (n - subtree[u] > n/2) is_centroid = false;
    if(is_centroid)ans = u;
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
        cout << ans << "\n";
    }
    return 0;
}