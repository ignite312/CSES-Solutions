/*
Problem Name: Path Queries II
Problem Link: https://cses.fi/problemset/task/2134
Idea: Heavy Light Decomposition
Complexity: O(Nlog^2N)
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int values[N+1], subtree[N+1], parent[N+1], depth[N+1];
int heavy[N+1], head[N+1], id[N+1];
vector<int> adj[N+1];
 
// 0 Base indexing
struct Segtree {
    int size;
    vector<int> tree;

    int merge(int x, int y) {
        return max(x, y);
    }
    void build(vector<int> &a, int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = l + (r - l)/2;
        build(a, node*2+1, l, mid);
        build(a, node*2+2, mid+1, r);
        tree[node] = merge(tree[node*2+1], tree[node*2+2]);
    }
    void update(int i, int value, int node, int l, int r) {
        if(l == i && r == i) {
            tree[node] = value;
            return;
        }
        int mid = l + (r-l)/2;
        if(i <= mid)update(i, value, node*2+1, l, mid);
        else update(i, value, node*2+2, mid+1, r);
        tree[node] = merge(tree[node*2+1], tree[node*2+2]);
    }
    void update(int i, int value) {
        update(i, value, 0, 0, size-1);
    }
    int query(int i, int j, int node, int l, int r) {
        if(l > j || r < i) return INT_MIN;
        if(l >= i && r <= j)return tree[node];
        int mid = l + (r - l)/2;
        return merge(query(i, j, node*2+1, l, mid), query(i, j, node*2+2, mid+1, r));
    }
    int query(int i, int j) {
        return query(i, j, 0, 0, size-1);
    }
    int sz(int n) {
        int size = 1;
        while(size < n) size = size << 1;
        return 2*size-1;
    }
    void init(vector<int> &a, int n) {
        size = 1;
        while(size < n) size = size << 1;
        tree.resize(2*size-1);
        build(a, 0, 0, size-1);
    }
} st;
 
void dfs(int u, int p) {
  subtree[u] = 1;
  int mx = 0;
  for(auto v : adj[u]) {
    if(v == p)continue;
    parent[v] = u;
    depth[v] = depth[u]+1;
    dfs(v, u);
    subtree[v]+=subtree[u];
    if(subtree[v] > mx) {
      mx = subtree[v];
      heavy[u] = v;
    }
  }
}
int idx = 0;
void HLD(int u, int h) {
  head[u] = h;
  id[u] = idx++;
  if(heavy[u])HLD(heavy[u], h);
  for(auto v : adj[u]) {
    if(v != parent[u] && v != heavy[u]) {
      HLD(v, v);
    }
  }
}
int path(int x, int y) {
  int ans = 0;
  while(head[x] != head[y]) {
    if(depth[head[x]] > depth[head[y]]) swap(x, y);
    ans = max(ans, st.query(id[head[y]], id[y]));
    y = parent[head[y]];
  }
  if(depth[x] > depth[y])swap(x, y);
  ans = max(ans, st.query(id[x], id[y]));
  return ans;
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
        for(int i = 0; i < n; i++)cin >> values[i];
        for(int i = 0; i < n-1; i++) {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
        dfs(1, -1);
        HLD(1, 1);
        vector<int> a(n);
        for(int i = 0; i < n; i++)a[id[i+1]] = values[i];
        st.init(a, n);
        while(q--) {
          int type;
          cin >> type;
          if(type == 1) {
            int s, x;
            cin >> s >> x;
            st.update(id[s], x);
          }else {
            int a, b;
            cin >> a >> b;
            cout << path(a, b) << " ";
          }
        }
    }
    return 0;
}