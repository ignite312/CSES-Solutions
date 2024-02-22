#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 1;
vector<ll> adj[N+1];
ll subtree[N+1], n, depth[N+1];
 
void dfs(int u, int p) {
    for(auto v : adj[u]) {
        if(v == p)continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        subtree[u] += subtree[v] + 1;
    }
}

ll ans[N+5];
void find(int u, int p) {
    for(auto v : adj[u]) {
        if(v == p)continue;
        ans[v]= ans[u] - (subtree[v]+1LL) + (n*1LL - (subtree[v]+1LL));
        find(v, u); 
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
        ll total = 0LL;
        for(int i = 1; i <= n; i++) {total+=depth[i];}
        ans[1] = total;
        find(1, -1);
        for(int i = 1; i <= n; i++)cout << ans[i] << " ";
    }
    return 0;
}