# Segment tree Template
- ***0-based indexing***
## Static Update
```
struct Segtree {
    // 0 base indexing
    int size;
    vector<int> tree;
 
    int merge(int x, int y) {
        return max(x, y);
    }
    void build(vector<int> &a, int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = l + (r - l)/2;
        build(a, node*2+1, l, mid);
        build(a, node*2+2, mid+1, r);
        tree[node] = merge(tree[node*2+1], tree[node*2+2]);
    }
    void update(int i, int value, int node, int l, int r) {
        if(l == i && r == i) {
            tree[node] = value;
            return;
        }
        int mid = l + (r-l)/2;
        if(i <= mid)update(i, value, node*2+1, l, mid);
        else update(i, value, node*2+2, mid+1, r);
        tree[node] = merge(tree[node*2+1], tree[node*2+2]);
    }
    void update(int i, int value) {
        update(i, value, 0, 0, size-1);
    }
    int query(int i, int j, int node, int l, int r) {
        if(l > j || r < i) return INT_MIN;
        if(l >= i && r <= j)return tree[node];
        int mid = l + (r - l)/2;
        return merge(query(i, j, node*2+1, l, mid), query(i, j, node*2+2, mid+1, r));
    }
    int query(int i, int j) {
        return query(i, j, 0, 0, size-1);
    }
    void init(vector<int> &a, int n) {
        size = 1;
        while(size < n) size = size << 1;
        tree.resize(2*size-1);
        build(a, 0, 0, size-1);
    }
} st;
```
## Dynamic Update
```
struct Segtree {
    // 0 base indexing
    int size;
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
        build(a, 0, 0, size-1);
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
        update(i, j, value, 0, 0, size-1);
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
        return query(i, j, 0, 0, size-1);
    }
    void init(vector<ll> &a, int n) {
        size = 1;
        while(size < n) size = size << 1;
        tree.resize(2*size-1);
        lazy.assign(2*size-1, 0);
        build(a, 0, 0, size-1);
    }
} st;
```