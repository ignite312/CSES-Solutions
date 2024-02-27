/*
Small To Large(DSU on Tree)
NLog(N)
Resource: https://github.com/ignite312/CpStuff/tree/main/Tree/Small%20to%20Large%20Merging(DSU%20on%20Tree)
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int color[N+1];
vector<int> adj[N+1];
 
int idx = 0, euler[N+1], pos[N+1], sz[N+1], H_C[N+1];
 
void dfs(int u, int p) {
    pos[u] = idx;
    euler[idx++] = u;
    H_C[u] = -1, sz[u] = 1;
    for(auto v: adj[u]) {
        if(v == p)continue;
        dfs(v, u);
        sz[u]+=sz[v];
        if(H_C[u] == -1 || sz[v] > sz[H_C[u]]) {
            H_C[u] = v;
        }
    }
}
 
int freq[N+1], cur_distinct = 0, distinct[N+1];
void add(int u) {
    freq[color[u]]++;
    if(freq[color[u]] == 1)cur_distinct++;
}
 
void remove(int u) {
    freq[color[u]]--;
    if(freq[color[u]] == 0)cur_distinct--;
}
 
void dsu(int u, int p, int keep) {
    for(auto v : adj[u]) {
        if(v == p || v == H_C[u]) continue;
        dsu(v, u, 0);
    }
    if(H_C[u] != -1) {
        dsu(H_C[u], u, 1);
    }
 
    for(auto v : adj[u]) {
        if(v == p || v == H_C[u]) continue;
        for(int i = pos[v]; i < pos[v] + sz[v]; i++) {
            add(euler[i]);
        }
    }
    add(u);
    distinct[u] = cur_distinct;
 
    if(!keep) {
        for(int i = pos[u]; i < pos[u] + sz[u]; i++) {
            remove(euler[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        map<int, int> compress;
        int id = 1;
        for(int i = 1; i <= n; i++) {
            cin >> color[i];
            if(compress[color[i]]) color[i] = compress[color[i]];
            else {
                compress[color[i]] = id++;
                color[i] = compress[color[i]];
            }
        }
        for(int i = 0; i < n-1; i++) {
          int u, v;
          cin >> u >> v;;
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
        dfs(1, -1);
        dsu(1, -1, 1);
        for(int i = 1; i <= n; i++)cout << distinct[i] << " ";
    }
    return 0;
}