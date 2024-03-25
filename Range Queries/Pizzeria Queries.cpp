/*
Problem Name: Pizzeria Queries
Problem Link: https://cses.fi/problemset/task/2206/
Idea: Range Minimum Query
Complexity:
Resource: https://usaco.guide/problems/cses-2206-pizzeria-queries/solution
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Node array<int, 2>

struct Segtree {
    // 0 base indexing
    int n;
    vector<Node> tree;

    Node merge(Node &x, Node &y, int l, int r) {
        int mid = l + ((r - l) >> 1);
        Node z = {0, 0};
        z[0] = min(x[0], mid - l + 1 + y[0]); // storing highest ans from left to right node
        z[1] = min(x[1]+r-(mid+1)+1, y[1]); // storing highest ans from right to left node
        return z;
    }
    void build(vector<ll> &a, int node, int l, int r) {
        if(l == r) {
            tree[node][0] = tree[node][1] = a[l];
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(a, (node << 1)+1, l, mid);
        build(a, (node << 1)+2, mid+1, r);
        tree[node] = merge(tree[(node << 1)+1], tree[(node << 1)+2], l, r);
    }
    void update(int i, ll value, int node, int l, int r) {
        if(l == i && r == i) {
            tree[node][0] = tree[node][1] = value;
            return;
        }
        int mid = l + ((r-l) >> 1);
        if(i <= mid)update(i, value, (node << 1)+1, l, mid);
        else update(i, value, (node << 1)+2, mid+1, r);
        tree[node] = merge(tree[(node << 1)+1], tree[(node << 1)+2], l, r);
    }
    void update(int i, int value) {
        update(i, value, 0, 0, n-1);
    }
    // Storing all the node for offline Query that belongs inside (i, j)
    void query(int i, int j, int node, int l, int r, vector<array<int, 3>> &ret) {
        if(l > j || r < i) return;
        if(l >= i && r <= j) {
            ret.push_back({node, l, r});
            return;
        }
        int mid = l + ((r - l) >> 1);
        query(i, j, (node << 1)+1, l, mid, ret), query(i, j, (node << 1)+2, mid+1, r, ret);
    }
    ll query(int i) {
        vector<array<int, 3>> seg;

        // Find ans for the Right side of the index i
        query(i, n-1, 0, 0, n-1, seg);
        array<int, 3> t_seg = seg[0];
        int len = t_seg[2] - t_seg[1] + 1;
        int ret = tree[t_seg[0]][0];
        for(int i = 1; i < (int)seg.size(); i++) {
            ret = min(ret, len + tree[seg[i][0]][0]);
            len+=seg[i][2] - seg[i][1] + 1;
        }
        seg.clear();

        // Find ans for the Left side of the index i
        query(0, i, 0, 0, n-1, seg);
        t_seg = seg[(int)seg.size()-1];
        len = t_seg[2] - t_seg[1] + 1;
        ret = min(ret, tree[t_seg[0]][1]);

        for(int i = (int)seg.size()-2; i >= 0; i--) {
            ret = min(len + tree[seg[i][0]][1], ret);
            len+=seg[i][2] - seg[i][1] + 1;
        }
        return ret;
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
                int i, value;
                cin >> i >> value;
                st.update(--i, value);
            }else {
                int i;
                cin >> i;
                --i;
                cout << st.query(i) << "\n";
            }
        }
    }
    return 0;
}