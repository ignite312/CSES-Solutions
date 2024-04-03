## How to Check Bipartite Graph ?
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

## Cycle in Undirected Graph
```C++
void dfs(int u, int p) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (p == v) continue;
        if (!vis[v]) {
            parent[v] = u;
            dfs(v, u);
        } else {
            if (!cycle_found) en = u, st = v;
            cycle_found = true;
            return;
        }
    }
}

        // Print  Cycle
        vector<int> path;
        path.push_back(st);
        path.push_back(en);
        int j = en;
        while(parent[j] != st) {
            path.push_back(parent[j]);
            j = parent[j];
        }
        path.push_back(st);
        cout << path.size() << "\n";
        for(int i = path.size() - 1; i >= 0; i--)cout << path[i] << " ";
```