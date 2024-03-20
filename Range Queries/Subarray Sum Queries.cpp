/*
Problem Name: Subarray Sum Queries
Problem Link: https://cses.fi/problemset/task/1190/
Idea: Segment Tree
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Node array<ll, 4>
 
struct Segtree {
    // 0 base indexing
    int n;
    vector<Node> tree;
 
    Node merge(Node &x, Node &y) {
        Node z = {0, 0, 0, 0};
        z[0] = max(x[2] + y[1], max(x[0], y[0])); // z[0] = maximum subarray sum of 2 merged node
        z[1] = max(x[1], x[3] + y[1]); // z[0] = maximum prefix sum of 2 merged node
        z[2] = max(y[2], y[3] + x[2]); // z[1] = maximum suffix sum of 2 merged node
        z[3] = x[3] + y[3]; // z[3] = total sum in 2 merged node
        return z;
    }
    void build(vector<ll> &a, int node, int l, int r) {
        if(l == r) {
            tree[node][0] = tree[node][1] = tree[node][2] = max(0LL, a[l]);
            tree[node][3] = a[l];
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(a, (node << 1)+1, l, mid);
        build(a, (node << 1)+2, mid+1, r);
        tree[node] = merge(tree[(node << 1)+1], tree[(node << 1)+2]);
    }
    void update(int i, ll value, int node, int l, int r) {
        if(l == i && r == i) {
            tree[node][0] = tree[node][1] = tree[node][2] = max(0LL, value);
            tree[node][3] = value;
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
    ll query() {
        return tree[0][0];
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
    while(tt--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n+1);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        st.init(a, n);
        while(q--) {
            int idx;
            ll new_value;
            cin >> idx >> new_value;
            st.update(idx-1, new_value);
            cout << st.query() << "\n";
        }
    }
}
