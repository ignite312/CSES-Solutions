/*
Problem Name: Range Updates and Sums
Problem Link: https://cses.fi/problemset/task/1735/
Idea: Segment tree with Lazy
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Segtree {
    // 0 base indexing
    int n;
    vector<pair<ll, ll>> tree;
    vector<bool> mark;

    void push(int node) {
        tree[(node << 1)+1].first = tree[(node << 1)+2].first = tree[node].first/2;
        tree[(node << 1)+1].second = tree[(node << 1)+2].second = 0;
        mark[(node << 1)+1] = mark[(node << 1)+2] = true;
        mark[node] = false;
    }
    ll assign(int i, int j, ll value, int node, int l, int r) {
        if(l > j || r < i)return tree[node].first + tree[node].second*(r-l+1);
        if(l >= i && r <= j) {
            tree[node].first = (r - l + 1)*value;
            tree[node].second = 0;
            mark[node] = true;
            return tree[node].first;
        }
        if(mark[node])push(node);

        tree[(node << 1)+1].second += tree[node].second, tree[(node << 1)+2].second += tree[node].second;
        tree[node].second = 0;

        int mid = l + (r - l)/2;
        return tree[node].first = assign(i, j, value, (node << 1)+1, l, mid) + assign(i, j, value, (node << 1)+2, mid+1, r);
    }
    void assign(int i, int j, ll value) {
        assign(i, j, value, 0, 0, n-1);
    }
    void update(int i, int j, ll value, int node, int l, int r) {
        if(r < i || l > j)return;
        if(l >= i && r <= j) {
            tree[node].second += value;
            return;
        }
        if(mark[node])push(node);

        int len = min(r, j) - max(l, i) + 1;
        tree[node].first += len*value;

        int mid = l + (r - l)/2;
        update(i, j, value, (node << 1)+1, l, mid), update(i, j, value, (node << 1)+2, mid+1, r);
    }
    void update(int i, int j, ll value) {
        update(i, j, value, 0, 0, n-1);
    }
    ll query(int i, int j, int node, int l, int r) {
        if(r < i || l > j)return 0;
        if(l >= i && r <= j) {
            return tree[node].first + tree[node].second*(r - l + 1);
        }
        if(mark[node])push(node);

        tree[node].first+=tree[node].second*(r - l + 1);
        tree[(node << 1)+1].second += tree[node].second;
        tree[(node << 1)+2].second += tree[node].second;
        tree[node].second = 0;

        int mid = l + (r - l)/2;
        return query(i, j, (node << 1)+1, l, mid) + query(i, j, (node << 1)+2, mid+1, r);
    }
    ll query(int i, int j) {
        return query(i, j, 0, 0, n-1);
    }
    void init(vector<ll> &a, int _n) {
        n = _n;
        int size = 1;
        while(size < n) size = size << 1;
        tree.assign((size << 1)-1, {0, 0});
        mark.assign((size << 1)-1, false);
        for(int i = 0; i < (int)a.size(); i++) {
            update(i, i, a[i]);
        }
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
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        n = (1 << (int)ceil(log2(n)));
        st.init(a, n);
        while(q--) {
            int type, a, b;
            ll x;
            cin >> type;
            if(type == 1) {
                cin >> a >> b >> x;
                st.update(--a, --b, x);
            }else if(type == 2) {
                cin >> a >> b >> x;
                st.assign(--a, --b, x);
            }else {
                cin >> a >> b;
                cout << st.query(--a, --b) << "\n";
            }
        }
    }
    return 0;
}
