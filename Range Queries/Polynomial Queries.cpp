/*
Problem Name: Polynomial Queries
Problem Link: https://cses.fi/problemset/task/1736/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Node array<int, 2>

struct Segtree {
    // 0 base indexing
    int n;
    vector<ll> tree;
    vector<Node> lazy;
    // lazy[0] = starting number of an arithmetic series
    // lazy[1] = diiference between 2 number in that arithmetic series
 
    ll merge(ll x, ll y) {
        return x + y;
    }
    void push(int node, int l, int r) {
        int a = (node << 1)+1, b = (node << 1)+2;
        int mid = l + ((r-l) >> 1);
        ll seg_a = mid - l + 1, seg_b = r - (mid+1) + 1;

        // Left and Right subtree value update 
        tree[a] += seg_a*lazy[node][0] + (seg_a*(seg_a-1)*1LL*lazy[node][1])/2;
        tree[b] += seg_b*(lazy[node][0] + seg_a*lazy[node][1]) + (seg_b*(seg_b-1)*1LL*lazy[node][1])/2;

        // Left and Right subtree lazy value update
        lazy[a][0] += lazy[node][0], lazy[b][0] += lazy[node][0] + (mid-l+1)*lazy[node][1];
        lazy[a][1]+=lazy[node][1], lazy[b][1]+=lazy[node][1];

        // set the all value of node to 0 after propagration
        lazy[node][0] = lazy[node][1] = 0;
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
    void update(int i, int j, int node, int l, int r) {
        if(l > j || r < i)return;
        if(l >= i && r <= j) {
            ll seg = r - l + 1;
            ll value = l - i + 1;
            tree[node] += seg*value + seg*(seg-1)/2;
            lazy[node][0]+=value;
            lazy[node][1]++;
            return;
        }
        if(lazy[node][0])push(node, l, r);
        int mid = l + ((r-l) >> 1);
        update(i, j, (node << 1)+1, l, mid);
        update(i, j, (node << 1)+2, mid+1, r);
        tree[node] = merge(tree[(node << 1)+1], tree[(node << 1)+2]);
    }
    void update(int i, int j) {
        update(i, j, 0, 0, n-1);
    }
    ll query(int i, int j, int node, int l, int r) {
        if(l > j || r < i) return 0;
        if(l >= i && r <= j) return tree[node];
 
        if(lazy[node][0]) push(node, l, r);
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
        Node x = {0, 0};
        lazy.assign((size << 1)-1, x);
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
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        st.init(a, n);
        while(q--) {
            int type;
            cin >> type;
            if(type == 1) {
                int i, j;
                cin >> i >> j;
                st.update(i-1, j-1);
            }else {
                int i, j;
                cin >> i >> j;
                cout << st.query(i-1, j-1) << "\n";
            }
        }
    }
    return 0;
}