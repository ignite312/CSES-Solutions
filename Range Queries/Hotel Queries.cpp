/*
Problem Name: Hotel Queries
Problem Link: https://cses.fi/problemset/task/1143
Idea: Segment Tree Max
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;

struct Segtree {
    // 0 base indexing
    int n;
    vector<int> tree;
 
    int merge(int x, int y) {
        return max(x, y);
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
    void update(int i, int value, int node, int l, int r) {
        if(l == i && r == i) {
            tree[node] = value;
            return;
        }
        int mid = l + ((r-l) >> 1);
        if(i <= mid)update(i, value, (node << 1)+1, l, mid);
        else update(i, value, (node << 1)+2, mid+1, r);
        tree[node] = merge(tree[(node << 1)+1], tree[(node << 1)+2]);
    }
    void update(int i, int value) {
        update(i, value, 0, 0, n-1);
    }
    int query(int key, int node, int l, int r) {
        if(l == r && tree[node] >= key) {
            update(l, tree[node] - key);
            return l;
        }else if(l == r) {
            return -1;
        }
        int mid = l + ((r - l) >> 1);
        if(tree[(node << 1)+1] >= key)return query(key, (node << 1)+1, l, mid);
        else if(tree[(node << 1)+2] >= key)return query(key, (node << 1)+2, mid+1, r);
        return -1;
    }
    int query(int key) {
        return query(key, 0, 0, n-1);
    }
    void init(vector<int> &a, int _n) {
        n = _n;
        int size = 1;
        while(size < n) size = size << 1;
        tree.resize((size << 1)-1);
        build(a, 0, 0, n-1);
    }
} st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        st.init(a, n);
        while(q--) {
            int r;
            cin >> r;
            int idx = st.query(r);
            if(idx == -1)cout << "0 ";
            else {
                cout << idx + 1 << " ";
            }
        }
    }
    return 0;
}
