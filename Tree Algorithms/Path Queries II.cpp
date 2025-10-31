/*
Problem Name: Path Queries II
Problem Link: https://cses.fi/problemset/task/2134
Idea: Heavy Light Decomposition
Complexity: O(Nlog^2N)
Resource:
*/
/*
Heavy Light Decomposition
Complexity : O(Nlog^2N)
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 200001;
int values[N], subtree[N], parent[N], depth[N];
int heavy[N], head[N], id[N];
vector<int> adj[N];
 
struct Segtree {
  // 0-based array indexing
  int n;
  vector<int> tree;
  Segtree(int n) {
    this->n = n;
    tree.assign(4 * n, 0);
  }
  void build(vector<int> &a, int idx, int l, int r) {
    if (l == r) {
      tree[idx] = a[l];
      return;
    }
    int mid = (l + r) / 2;
    build(a, idx * 2, l, mid);
    build(a, idx * 2 + 1, mid + 1, r);
    tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
  }
  void build(vector<int> &a) {
    build(a, 1, 0, n - 1);
  }
  void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
      tree[idx] = val;
      return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(idx * 2, l, mid, pos, val);
    else update(idx * 2 + 1, mid + 1, r, pos, val);
    tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
  }
  void update(int pos, int val) {
    update(1, 0, n - 1, pos, val);
  }
  int query(int idx, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return INT_MIN;
    if (ql <= l && r <= qr) return tree[idx];
    int mid = (l + r) / 2;
    return max(query(idx * 2, l, mid, ql, qr),
           query(idx * 2 + 1, mid + 1, r, ql, qr));
  }
  int query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }
};
/*
struct Segtree {
    0-base indexing
    int n;
    vector<int> t;
    Segtree(int n = 0) : n(n), t(4*n, 0) {}
    int merge(int x, int y) { return max(x, y); } // fn
    void build(vector<int> &a) {
        for (int i = 0; i < n; i++) t[n + i] = a[i];
        for (int i = n - 1; i > 0; i--) 
            t[i] = merge(t[i << 1], t[i << 1 | 1]);
    }
    void update(int p, int val) {
        for (t[p += n] = val; p > 1; p >>= 1) // increment or set
            t[p >> 1] = merge(t[p], t[p ^ 1]);
    }
    int query(int l, int r) {
        int res = INT_MIN; // identity
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res = merge(res, t[l++]);
            if (!(r & 1)) res = merge(res, t[r--]);
        }
        return res;
    }
};
*/
void dfs(int u, int p) {
  subtree[u] = 1;
  int mx = 0;
  for(auto v : adj[u]) {
    if(v == p)continue;
    parent[v] = u;
    depth[v] = depth[u]+1;
    dfs(v, u);
    subtree[u]+=subtree[v];
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
int path(int x, int y, Segtree &st) {
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
        Segtree st(n);
        st.build(a);
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
            cout << path(a, b, st) << " ";
          }
        }
    }
    return 0;
}