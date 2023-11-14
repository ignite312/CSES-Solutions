#include<bits/stdc++.h>
using namespace std;
const int N = 1500+1;
vector<int> adj[N+1];
int capacity[N+1][N+1];
 
int bfs(int s, int d, int n, vector<int> &parent) {
    parent.assign(n+1, -1);
    parent[s] = 0;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    while(!q.empty()) {
        int u = q.front().first;
        int f =  q.front().second;
        q.pop();
        for(auto v : adj[u]) {
            if(parent[v] == -1 && capacity[u][v]) {
                parent[v] = u;
                int n_f = min(f, capacity[u][v]);
                if(v == d)return n_f;
                q.push({v, n_f});
            }
        }
    }
    return 0;
}
int max_flow(int s, int d, int n) {
    int mx_flow = 0;
    vector<int> parent;
    int flow;
    while(flow = bfs(s, d, n, parent)) {
        mx_flow+=flow;
        int now = d;
        while(now != s) {
            int prev = parent[now];
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
        int n, m, k;
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++) {
            adj[0].push_back(i);
            adj[i].push_back(0);
            capacity[0][i] = 1;
        }
        for(int i = n+1; i <= n+m; i++) {
            adj[n+m+1].push_back(i);
            adj[i].push_back(n+m+1);
            capacity[i][n+m+1] = 1;
        }
        for(int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;
            if(capacity[u][v + n]) continue;
            adj[u].push_back(v+n);
            adj[v+n].push_back(u);
            capacity[u][v+n] = 1;
        }
        cout << max_flow(0, n+m+1, n+m+1) << "\n";
        for(int u = 1; u <= n; u++) {
            for(auto v : adj[u]) {
                if(v != 0 && !capacity[u][v]) {
                    cout << u << " " << v - n << "\n";
                }
            }
        }
    }
    return 0;
}
/*Max-Flow*/
