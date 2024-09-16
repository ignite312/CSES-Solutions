/*
Problem Name: Fixed-Length Paths I
Problem Link: https://cses.fi/problemset/task/2080
Idea: Centroid decomposition
Complexity: O(Nlog(N))
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 1;
vector<int> adj[N];
int n, k;
int subtree[N], cnt[N], mx_depth;
bool visited[N];
ll ans;
 
int getSubtree(int u, int p) {
    subtree[u] = 1;
    for(auto v : adj[u]) {
        if(!visited[v] && v != p) {
            getSubtree(v, u);
            subtree[u]+=subtree[v];
        }
    }
    return subtree[u];
}
int getCentroid(int u, int p, int desired) {
    for(auto v : adj[u])
        if(!visited[v] && v != p && subtree[v] > desired)
            return getCentroid(v, u, desired);
    return u;
}
void compute(int u, int p, bool filling, int depth) {
    if(depth > k)return;
    mx_depth = max(mx_depth, depth);
    if(filling)cnt[depth]++;
    else ans+=cnt[k - depth]*1LL;
    for(auto v : adj[u])if(!visited[v] && v != p)compute(v, u, filling, depth+1);
}
void centroidDecomposition(int u) {
    int centroid = getCentroid(u, -1, getSubtree(u, -1) >> 1);
    visited[centroid] = true;
    mx_depth = 0;
    for(auto v : adj[centroid]) {
        if(!visited[v]) {
            compute(v, centroid, false, 1);
            compute(v, centroid, true, 1);
        }
    }
    for(int i = 1; i <= mx_depth; i++)cnt[i] = 0;
    for(auto v : adj[centroid])if(!visited[v])centroidDecomposition(v);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> k;
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cnt[0] = 1;
        centroidDecomposition(1);
        cout << ans << "\n";
    }
    return 0;
}