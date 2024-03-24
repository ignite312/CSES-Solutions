/*
Flattening Tree Using Segment Tree
Segment tree Resource: https://github.com/ignite312/CpStuff/tree/main/SegmentTree
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 1;
vector<int> adj[N+1];
ll values[N+1];
int st[N+1], en[N+1];
int Time = 0;
 
struct Segtree {
    int n;
    vector<ll> tree, lazy;
 
    ll merge(ll x, ll y) {
        return x + y;
    }
    void push(int node, int l, int r) {
        int a = node*2+1, b = node*2+2;
        int mid = l + (r-l)/2;
        tree[a]+=(mid-l+1)*lazy[node], tree[b]+=(r-(mid+1)+1)*lazy[node];
        lazy[a]+=lazy[node], lazy[b]+=lazy[node];
        lazy[node] = 0;
    }
    void build(vector<ll> &a, int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = l + (r - l)/2;
        build(a, node*2+1, l, mid);
        build(a, node*2+2, mid+1, r);
        tree[node] = merge(tree[node*2+1], tree[node*2+2]);
    }
    void build(vector<ll> &a) {
        build(a, 0, 0, n-1);
    }
    void update(int i, int j, ll value, int node, int l, int r) {
        if(l > j || r < i)return;
        if(l >= i && r <= j) {
            lazy[node]+=value;
            tree[node]+=(r-l+1)*value;
            return;
        }
        if(lazy[node])push(node, l, r);
        int mid = l + (r-l)/2;
        update(i, j, value, node*2+1, l, mid);
        update(i, j, value, node*2+2, mid+1, r);
        tree[node] = merge(tree[node*2+1], tree[node*2+2]);
    }
    void update(int i, int j, ll value) {
        update(i, j, value, 0, 0, n-1);
    }
    ll query(int i, int j, int node, int l, int r) {
        if(l > j || r < i)
            return 0;
        if(l >= i && r <= j)
            return tree[node];
 
        if(lazy[node]) push(node, l, r);
        int mid = l + (r - l)/2;
        return merge(query(i, j, node*2+1, l, mid), query(i, j, node*2+2, mid+1, r));
    }
    ll query(int i, int j) {
        return query(i, j, 0, 0, n-1);
    }
    int sz(int n) {
        int size = 1;
        while(size < n) size = size << 1;
        return 2*size-1;
    }
    void init(vector<ll> &a) {
        n = a.size();
        int _sz = sz(n);
        tree.resize(_sz);
        lazy.assign(_sz, 0);
        build(a, 0, 0, n-1);
    }
} St;

void dfs(int u, int p) {
    st[u] = ++Time;
    for(auto v : adj[u]) {
        if(v == p)continue;
        dfs(v, u);
    }
    en[u] = Time;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++)cin >> values[i];
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, -1);
        vector<ll> v(Time);
        for(int i = 1; i <= n; i++)v[st[i]-1] = values[i];
        St.init(v);
        while(q--) {
            int type;
            cin >> type;
            if(type == 1) {
                int s;
                ll x;
                cin >> s >> x;
                St.update(st[s]-1, st[s]-1, x - values[s]);
                values[s] = x;
            }else {
                int s;
                cin >> s;
                cout << St.query(st[s]-1, en[s]-1) << "\n";
            }
        }
    }
    return 0;
}