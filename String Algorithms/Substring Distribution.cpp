/*
Problem Name: Substring Distribution
Problem Link: https://cses.fi/problemset/task/2110/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
void radix_sort(vector<int> &p, vector<int> &c) {
  int n = p.size();
 
  vector<int> cnt(n);
  for (auto x : c) {
    cnt[x]++;
  }
 
  vector<int> p_new(n);
  vector<int> pos(n);
  pos[0] = 0;
  for (int i = 1; i < n; i++) {
    pos[i] = pos[i - 1] + cnt[i - 1];
  }
 
  for (auto x : p) {
    int i = c[x];
    p_new[pos[i]] = x;
    pos[i]++;
  }
  p = p_new;
}

// Dynamic Update
struct Segtree {
    // 0 base indexing
    int n;
    vector<ll> tree, lazy;
 
    ll merge(ll x, ll y) {
        return x + y;
    }
    void push(int node, int l, int r) {
        int a = (node << 1)+1, b = (node << 1)+2;
        int mid = l + ((r-l) >> 1);
        tree[a]+=(mid-l+1)*lazy[node], tree[b]+=(r-(mid+1)+1)*lazy[node];
        lazy[a]+=lazy[node], lazy[b]+=lazy[node];
        lazy[node] = 0;
    }
    void build(vector<ll> &a, int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = l + ((r-l) >> 1);
        build(a, (node << 1)+1, l, mid);
        build(a, (node << 1)+2, mid+1, r);
        tree[node] = merge(tree[(node << 1)+1], tree[(node << 1)+2]);
    }
    void build(vector<ll> &a) {
        build(a, 0, 0, n-1);
    }
    void update(int i, int j, ll value, int node, int l, int r) {
        if(l > j || r < i)return;
        if(l >= i && r <= j) {
            lazy[node]+=value;
            tree[node]+=(r-l+1)*value;
            return;
        }
        if(lazy[node])push(node, l, r);
        int mid = l + ((r-l) >> 1);
        update(i, j, value, (node << 1)+1, l, mid);
        update(i, j, value, (node << 1)+2, mid+1, r);
        tree[node] = merge(tree[(node << 1)+1], tree[(node << 1)+2]);
    }
    void update(int i, int j, ll value) {
        update(i, j, value, 0, 0, n-1);
    }
    ll query(int i, int j, int node, int l, int r) {
        if(l > j || r < i)
            return 0;
        if(l >= i && r <= j)
            return tree[node];
 
        if(lazy[node]) push(node, l, r);
        int mid = l + ((r-l) >> 1);
        return merge(query(i, j, (node << 1)+1, l, mid), query(i, j, (node << 1)+2, mid+1, r));
    }
    ll query(int i, int j) {
        return query(i, j, 0, 0, n-1);
    }
    void init(vector<ll> &a, int _n) {
        n = _n;
        int size = 1;
        while(size < n) size = size << 1;
        tree.resize((size << 1)-1);
        lazy.assign((size << 1)-1, 0);
        build(a, 0, 0, n-1);
    }
} st;
void SA() {
  string s;
  cin >> s;
  s += "$";
  int n = s.size();
  vector<int> p(n), c(n);
 
    // k = 0
  vector<pair<char, int>> a(n);
  for (int i = 0; i < n; i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) p[i] = a[i].second;
    c[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    if (a[i].first == a[i - 1].first) {
      c[p[i]] = c[p[i - 1]];
    } else {
      c[p[i]] = c[p[i - 1]] + 1;
    }
  }
 
  int k = 0;
  while ((1 << k) < n) {
        // k -> k + 1
    for (int i = 0; i < n; i++) {
      p[i] = (p[i] - (1 << k) + n) % n;
    }
    radix_sort(p, c);
    vector<int> c_new(n);
    c_new[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << k)) % n]};
      pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
      if (prev == now) {
        c_new[p[i]] = c_new[p[i - 1]];
      } else {
        c_new[p[i]] = c_new[p[i - 1]] + 1;
      }
    }
    c = c_new;
    k++;
  }
  vector<int> lcp(n);
  k = 0;
  for(int i = 0; i < n-1; i++) {
    int pi = c[i];
    int j = p[pi-1];
    while(s[i+k] == s[j+k])k++;
    lcp[pi] = k;
    k = max(k-1, 0);
  }

  vector<ll> v(n, 0);
  st.init(v, n);
  
  for(int i = 0; i < n; i++) {
    if(lcp[i] <= n-p[i]-2)st.update(lcp[i], n-p[i]-2, 1);
  }
  for(int i = 1; i <= n-1; i++) {
    cout << st.query(i-1, i-1) << " ";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
    // cin >> tt;
  while(tt--) {
    SA();
  }
  return 0;
}