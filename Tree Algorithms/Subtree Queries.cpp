/*
Problem Name: Subtree Queries
Problem Link: https://cses.fi/problemset/task/1137
Idea: Flattening Tree Using Segment Tree
Complexity: 
Resource: https://github.com/ignite312/CpStuff/tree/main/SegmentTree
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200001;
vector<int> adj[N];
ll values[N];
int st[N], en[N];
int _time = -1;

void dfs(int u, int p) {
  st[u] = ++_time;
  for(auto v : adj[u]) {
    if(v == p) continue;
    dfs(v, u);
  }
  en[u] = _time;
}

struct Segtree {
  // 0-based array indexing
  int n;
  vector<ll> tree;
  Segtree(int n) {
    this->n = n;
    tree.assign(4 * n, 0);
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
  void update(int idx, int l, int r, int pos, ll val) {
    if (l == r) {
      tree[idx] += val;
      return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(idx * 2, l, mid, pos, val);
    else update(idx * 2 + 1, mid + 1, r, pos, val);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
  }
  void update(int pos, ll val) {
    update(1, 0, n - 1, pos, val);
  }
  ll query(int idx, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) return tree[idx];
    int mid = (l + r) / 2;
    return query(idx * 2, l, mid, ql, qr) +
           query(idx * 2 + 1, mid + 1, r, ql, qr);
  }
  ll query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }
};

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
    dfs(1, -1);
    vector<ll> a(n);
    for(int i = 1; i <= n; i++) {
      a[st[i]] = values[i];
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
        sgt.update(st[s], x - values[s]);
        values[s] = x;
      } else {
        int s;
        cin >> s;
        cout << sgt.query(st[s], en[s]) << "\n";
      }
    }
  }
  return 0;
}