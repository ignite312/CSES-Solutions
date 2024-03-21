/*
Problem Name: Prefix Sum Queries
Problem Link: https://cses.fi/problemset/task/2166/
Idea: Segment Tree
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Node array<ll, 2>
 
struct Segtree {
    // 0 base indexing
    int n;
    vector<Node> tree;
 
    Node merge(Node x, Node y) {
        Node z = {0, 0};
        z[0] = x[0] + y[0]; // z[0] = total sum in 2 merged node
        z[1] = max(x[1], x[0] + y[1]); // z[1] = maximum prefix sum of 2 merged node
        return z;
    }
    void build(vector<ll> &a, int node, int l, int r) {
        if(l == r) {
            tree[node][0] = a[l];
            tree[node][1] = max(0LL, a[l]);
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(a, (node << 1)+1, l, mid);
        build(a, (node << 1)+2, mid+1, r);
        tree[node] = merge(tree[(node << 1)+1], tree[(node << 1)+2]);
    }
    void update(int i, ll value, int node, int l, int r) {
        if(l == i && r == i) {
            tree[node][0] = value;
            tree[node][1] = max(0LL, value);
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
    Node query(int i, int j, int node, int l, int r) {
        if(l > j || r < i) return {0, 0};
        if(l >= i && r <= j)return tree[node];
        int mid = l + ((r - l) >> 1);
        return merge(query(i, j, (node << 1)+1, l, mid), query(i, j, (node << 1)+2, mid+1, r));
    }
    ll query(int i, int j) {
        Node rslt = query(i, j, 0, 0, n-1);
        return rslt[1];
    }
    void init(vector<ll> &a, int _n) {
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
    // cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        st.init(a, n);
        while(q--) {
            int type;
            cin >> type;
            if(type == 1) {
                int i, new_value;
                cin >> i >> new_value;
                st.update(i-1, new_value);
            }else {
                int l, r;
                cin >> l >> r;
                cout << st.query(l-1, r-1) << "\n";
            }
        }
        return 0;
    }
    return 0;
}