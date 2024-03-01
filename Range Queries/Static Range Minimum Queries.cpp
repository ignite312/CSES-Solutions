/*
Problem: https://cses.fi/problemset/task/1647/
Idea: Segment Tree
*/
#include<bits/stdc++.h>
using namespace std;

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
        int mid = l + ((r-l) >> 1);
        build(a, (node << 1)+1, l, mid);
        build(a, (node << 1)+2, mid+1, r);
        tree[node] = merge(tree[(node << 1)+1], tree[(node << 1)+2]);
    }
    int query(int i, int j, int node, int l, int r) {
        if(l > j || r < i) return INT_MAX;
        if(l >= i && r <= j)return tree[node];
        int mid = l + ((r-l) >> 1);
        return merge(query(i, j, (node << 1)+1, l, mid), query(i, j, (node << 1)+2, mid+1, r));
    }
    int query(int i, int j) {
        return query(i, j, 0, 0, n-1);
    }
    void init(vector<int> &a, int _n) {
        n = _n;
        int size = 1;
        while(size < n) size = size << 1;
        tree.resize(2*size-1);
        build(a, 0, 0, n-1);
    }
} st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        st.init(a, n);
        while(q--) {
            int l, r;
            cin >> l >> r;
            cout << st.query(l-1, r-1) << "\n";
        }
    }
    return 0;
}