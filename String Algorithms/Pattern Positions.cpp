/*
Problem Name: Pattern Positions
Problem Link: https://cses.fi/problemset/task/2104/
Idea: Suffix Array + Binary Search + Segment Tree
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;

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
struct Segtree {
    // 0 base indexing
    int n;
    vector<int> tree;
 
    int merge(int x, int y) {
        return min(x, y);
    }
    void build(vector<int> &a, int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(a, (node << 1)+1, l, mid);
        build(a, (node << 1)+2, mid+1, r);
        tree[node] = merge(tree[(node << 1)+1], tree[(node << 1)+2]);
    }
    int query(int i, int j, int node, int l, int r) {
        if(l > j || r < i) return INT_MAX;
        if(l >= i && r <= j)return tree[node];
        int mid = l + ((r - l) >> 1);
        return merge(query(i, j, (node << 1)+1, l, mid), query(i, j, (node << 1)+2, mid+1, r));
    }
    int query(int i, int j) {
        return query(i, j, 0, 0, n-1);
    }
    void init(vector<int> &a, int _n) {
        n = _n;
        int size = 1;
        while(size < n) size = size << 1;
        tree.resize((size << 1)-1);
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

  st.init(p, n);

  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;

    int lo = 0, hi = n - 1;
    int ans1 = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      string sub = s.substr(p[mid], min((int)t.size(), n - p[mid]));
 
      if (t == sub) {
        ans1 = mid;
        hi = mid-1;
      } else if (t > sub) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    lo = 0, hi = n-1;
    int ans2 = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      string sub = s.substr(p[mid], min((int)t.size(), n - p[mid]));
 
      if (t == sub) {
        ans2 = mid;
        lo = mid + 1;
      } else if (t > sub) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    if(ans1 == -1)cout << "-1" << "\n";
    else cout << st.query(ans1, ans2) + 1 << "\n";
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