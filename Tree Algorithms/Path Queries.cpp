/*
Problem Name: Path Queries
Problem Link: https://cses.fi/problemset/task/1138
Idea: Segment tree + Prefix Sum
Complexity: 
Resource: https://usaco.guide/plat/hld?lang=cpp
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200001;
vector<int> adj[N];
ll values[N];
int st[N], en[N];
int _time = -1;

struct Segtree {
  // 0-based array indexing
  int n;
  vector<ll> tree, lazy;
  Segtree(int n) {
    this->n = n;
    tree.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
  }
  void build(vector<ll> &a, int idx, int l, int r) {
    if (l == r) {
      tree[idx] = a[l];
      return;
    }
    int mid = (l + r) / 2;
    build(a, idx * 2, l, mid);
    build(a, idx * 2 + 1, mid + 1, r);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
  }
  void build(vector<ll> &a) {
    build(a, 1, 0, n - 1);
  }
  void push(int idx, int l, int r) {
    if (lazy[idx] == 0) return;
    int mid = (l + r) / 2;
    int left = idx * 2, right = idx * 2 + 1;

    tree[left] += (mid - l + 1) * lazy[idx];
    tree[right] += (r - mid) * lazy[idx];

    lazy[left] += lazy[idx];
    lazy[right] += lazy[idx];
    lazy[idx] = 0;
  }
  void update(int idx, int l, int r, int ql, int qr, ll val) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
      tree[idx] += (r - l + 1) * val;
      lazy[idx] += val;
      return;
    }
    if (lazy[idx]) push(idx, l, r);
    int mid = (l + r) / 2;
    update(idx * 2, l, mid, ql, qr, val);
    update(idx * 2 + 1, mid + 1, r, ql, qr, val);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
  }
  void update(int l, int r, ll val) {
    update(1, 0, n - 1, l, r, val);
  }
  ll query(int idx, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) return tree[idx];
    if (lazy[idx]) push(idx, l, r);
    int mid = (l + r) / 2;
    return query(idx * 2, l, mid, ql, qr) +
    query(idx * 2 + 1, mid + 1, r, ql, qr);
  }
  ll query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }
};

void dfs(int u, int p, vector<ll> &pfx) {
  st[u] = ++_time;
  for(auto v : adj[u]) {
    if(v == p) continue;
    pfx[v] += pfx[u];
    dfs(v, u, pfx);
  }
  en[u] = _time;
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
    for(int i = 1; i <= n; i++) cin >> values[i];
    for(int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<ll> pfx(n+1, 0);
    for(int i = 1; i <= n; i++) {
        pfx[i] = values[i];
    }
    dfs(1, -1, pfx);
    vector<ll> a(n);
    for(int i = 1; i <= n; i++) {
      a[st[i]] = pfx[i];
    }
    Segtree sgt(n);
    sgt.build(a);
    while(q--) {
      int type;
      cin >> type;
      if(type == 1) {
        int s;
        ll x;
        cin >> s >> x;
        sgt.update(st[s], en[s], x - values[s]);
        values[s] = x;
      } else {
        int s;
        cin >> s;
        cout << sgt.query(st[s], st[s]) << "\n";
      }
    }
  }
  return 0;
}