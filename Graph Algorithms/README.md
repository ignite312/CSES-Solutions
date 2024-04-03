## How to Check ``Bipartite`` Graph ?
```C++
void dfs(int u) {
    vis[u] = true;
    for(auto v : adj[u]) {
        if(!vis[v]) {
            color[v] = color[u]^1;
            dfs(v);
        }else {
            if(color[u] == color[v])is_bipartite = false;
        }
    }
}
```

## ``Cycle`` in Undirected Graph
```C++
void dfs(int u, int p) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (p == v)
            continue;
        if (!vis[v]) {
            parent[v] = u;
            dfs(v, u);
        }
        else {
            if (!cycle_found)
                en = u, st = v;
            cycle_found = true;
            return;
        }
    }
}

void checkCycle(int n) {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            parent[i] = -1;
            dfs(i, -1);
        }
    }
    if (!cycle_found) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> path;
    path.push_back(st);
    path.push_back(en);
    int j = en;
    while (parent[j] != st) {
        path.push_back(parent[j]);
        j = parent[j];
    }
    path.push_back(st);
    cout << path.size() << "\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}
```
## ``Cycle`` in Directed Graph
```C++
bool dfs(int u) {
    color[u] = 1;
    for(auto v : adj[u]) {
        if(!color[v]) {
            parent[v] = u;
            if(dfs(v)) return true;
        }else if(color[v] == 1) {
            st = v, en = u;
            return true;
        }
    }
    color[u] = 2;
    return false;
}
void checkCycle(int n) {
    st = en = -1;
    for(int i = 1; i <= n; i++) {
        if(!color[i] && dfs(i)) {
            break;
        }
    }
    if(st == -1) cout << "IMPOSSIBLE\n";
    else {
        vector<int> path;
        path.push_back(st);
        for(int i = en; i != st; i = parent[i])path.push_back(i);
        path.push_back(st);
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for(auto i : path)cout << i << " ";
        cout << "\n";
    }
}
```

## Dijkstra
```C++
void dijkstra(int s) {
    set<pair<ll, int>> st;
    st.insert({0, s});
    d[s] = 0;
    while(st.size() > 0) {
        auto node = *st.begin();
        int u = node.second;
        st.erase(st.begin());
        if(vis[u])continue;
        vis[u] = true;
        for(auto child : adj[u]) {
            int v = child.first;
            ll wt = child.second;
            if(d[u] + wt  < d[v]) {
                d[v] = d[u] + wt;
                st.insert({d[v], v});
            }
        }
    }
    return;
}
```

## Bellman-Ford
```C++
void BellmanFord(int s, int n) {
    vector<ll> dist(n + 1, INF);
    dist[s] = 0;  
    for (int i = 0; i < n - 1; i++) {
        bool any = false;  
        for (auto [u, v, wt] : edges) {
            if (dist[u] < INF) {
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    any = true;
                }
            }
        }
        if(!any)break;
    }
    for(int i = 1; i <= n; i++) {cout << dist[i] << " ";}   
}
```

## Floyd-Warshall
```C++
void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }
}
void floydWarshall() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] < INF && d[k][j] < INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                } 
            }
        }
    }
}
```