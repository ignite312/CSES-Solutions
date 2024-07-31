/*
Problem Name: Substring Order II
Problem Link: https://cses.fi/problemset/task/2109/
Idea: Segment tree + Suffix array
Complexity:
Resource:
Prerequisite: https://github.com/ignite312/CpStuff/blob/main/Segment%20Tree/RangeUpdateReplacesAndSums(Lazy).cpp
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
struct Segtree {
    // 0-base indexing
    int n;
    vector<pair<ll, ll>> tree;
    vector<bool> mark;
 
    void push(int node) {
        tree[(node << 1) + 1].first = tree[(node << 1) + 2].first = tree[node].first / 2;
        tree[(node << 1) + 1].second = tree[(node << 1) + 2].second = 0;
        mark[(node << 1) + 1] = mark[(node << 1) + 2] = true;
        mark[node] = false;
    }
 
    ll assign(int i, int j, ll value, int node, int l, int r) {
        if (l > j || r < i) return tree[node].first + tree[node].second * (r - l + 1);
        if (l >= i && r <= j) {
            tree[node].first = (r - l + 1) * value;
            tree[node].second = 0;
            mark[node] = true;
            return tree[node].first;
        }
        if (mark[node]) push(node);
 
        tree[(node << 1) + 1].second += tree[node].second;
        tree[(node << 1) + 2].second += tree[node].second;
        tree[node].second = 0;
 
        int mid = l + (r - l) / 2;
        return tree[node].first = assign(i, j, value, (node << 1) + 1, l, mid) + assign(i, j, value, (node << 1) + 2, mid + 1, r);
    }
 
    void assign(int i, int j, ll value) {
        assign(i, j, value, 0, 0, n - 1);
    }
 
    void update(int i, int j, ll value, int node, int l, int r) {
        if (r < i || l > j) return;
        if (l >= i && r <= j) {
            tree[node].second += value;
            return;
        }
        if (mark[node]) push(node);
 
        int len = min(r, j) - max(l, i) + 1;
        tree[node].first += len * value;
 
        int mid = l + (r - l) / 2;
        update(i, j, value, (node << 1) + 1, l, mid);
        update(i, j, value, (node << 1) + 2, mid + 1, r);
    }
 
    void update(int i, int j, ll value) {
        update(i, j, value, 0, 0, n - 1);
    }
 
    ll query(int i, int j, int node, int l, int r) {
        if (r < i || l > j) return 0;
        if (l >= i && r <= j) {
            return tree[node].first + tree[node].second * (r - l + 1);
        }
        if (mark[node]) push(node);
 
        tree[node].first += tree[node].second * (r - l + 1);
        tree[(node << 1) + 1].second += tree[node].second;
        tree[(node << 1) + 2].second += tree[node].second;
        tree[node].second = 0;
 
        int mid = l + (r - l) / 2;
        return query(i, j, (node << 1) + 1, l, mid) + query(i, j, (node << 1) + 2, mid + 1, r);
    }
 
    ll query(int i, int j) {
        return query(i, j, 0, 0, n - 1);
    }
 
    void init(vector<ll> &a, int _n) {
        n = _n;
        int size = 1;
        while (size < n) size = size << 1;
        tree.assign((size << 1) - 1, {0, 0});
        mark.assign((size << 1) - 1, false);
        for (int i = 0; i < (int)a.size(); i++) {
            update(i, i, a[i]);
        }
    }
} St;
 
void radix_sort(vector<int> &sa, vector<int> &c) {
    int n = sa.size();
 
    vector<int> cnt(n);
    for (auto x : c) {
        cnt[x]++;
    }
    vector<int> sa_new(n);
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x : sa) {
        int i = c[x];
        sa_new[pos[i]] = x;
        pos[i]++;
    }
    sa = sa_new;
}
 
void SA() {
    string s;
    cin >> s;
    ll k_th;
    cin >> k_th;
    s += "$";
    int n = s.size();
    vector<int> sa(n), c(n);
 
    // k = 0
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) sa[i] = a[i].second;
    c[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first == a[i - 1].first) {
            c[sa[i]] = c[sa[i - 1]];
        } else {
            c[sa[i]] = c[sa[i - 1]] + 1;
        }
    }
 
    int k = 0;
    while ((1 << k) < n) {
        // k -> k + 1
        for (int i = 0; i < n; i++) {
            sa[i] = (sa[i] - (1 << k) + n) % n;
        }
        radix_sort(sa, c);
        vector<int> c_new(n);
        c_new[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int, int> prev = {c[sa[i - 1]], c[(sa[i - 1] + (1 << k)) % n]};
            pair<int, int> now = {c[sa[i]], c[(sa[i] + (1 << k)) % n]};
            if (prev == now) {
                c_new[sa[i]] = c_new[sa[i - 1]];
            } else {
                c_new[sa[i]] = c_new[sa[i - 1]] + 1;
            }
        }
        c = c_new;
        k++;
    }
    vector<int> lcp(n);
    k = 0;
    for (int i = 0; i < n - 1; i++) {
        int pi = c[i];
        int j = sa[pi - 1];
        while (s[i + k] == s[j + k]) k++;
        lcp[pi] = k;
        k = max(k - 1, 0);
    }
    vector<ll> sum(n, 0);
    St.init(sum, n);
    ll count = 0;
    k_th = n * 1LL * (n - 1) / 2 - k_th + 1;
 
    for (int i = n - 1; i >= 0; i--) {
        int lo = lcp[i] + 1, hi = n - sa[i] - 1;
        St.update(1, hi, 1);
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (count + St.query(mid, n - sa[i] - 1) >= k_th) {
                ans = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        if (ans != -1) {
            cout << s.substr(sa[i], ans) << "\n";
            return;
        }
        count += St.query(lcp[i] + 1, n - sa[i] - 1);
        St.assign(lcp[i] + 1, n - sa[i] - 1, 0);
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--) {
        SA();
    }
    return 0;
}