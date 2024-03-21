/*
Problem Name: List Removals
Problem Link: https://cses.fi/problemset/task/1749/
Idea:
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
        return x + y;
    }
    void build(vector<int> &a, int node, int l, int r) {
        if(l == r) {
            tree[node] = 1;
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
        if(l == r) {
            return l;
        }
        int mid = l + ((r - l) >> 1);
        if(tree[(node << 1)+1] >= key)return query(key, (node << 1)+1, l, mid);
        else return query(key - tree[(node << 1)+1], (node << 1)+2, mid+1, r); // When you go to right segment subtract left segment element count
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
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        st.init(a, n);
        for(int i = 0; i < n; i++) {
            int idx;
            cin >> idx;
            idx = st.query(idx);
            cout << a[idx] << " ";
            st.update(idx, 0);
        }
    }
    return 0;
}