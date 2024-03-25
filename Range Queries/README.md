# Segment tree Template
- 0-based indexing
## Static Update
```C++
struct Segtree {
    // 0 base indexing
    int n;
    vector<ll> tree;
 
    ll merge(ll x, ll y) {
        return x + y;
    }
    void build(vector<ll> &a, int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(a, (node << 1)+1, l, mid);
        build(a, (node << 1)+2, mid+1, r);
        tree[node] = merge(tree[(node << 1)+1], tree[(node << 1)+2]);
    }
    void update(int i, ll value, int node, int l, int r) {
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
    ll query(int i, int j, int node, int l, int r) {
        if(l > j || r < i) return 0;
        if(l >= i && r <= j)return tree[node];
        int mid = l + ((r - l) >> 1);
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
        build(a, 0, 0, n-1);
    }
} st;
```
## Dynamic Update
```C++
struct Segtree {
    // 0 base indexing
    int n;
    vector<ll> tree, lazy;
 
    ll merge(ll x, ll y) {
        return x + y;
    }
    void push(int node, int l, int r) {
        int a = (node << 1)+1, b = (node << 1)+2;
        int mid = l + ((r-l) >> 1);
        tree[a]+=(mid-l+1)*lazy[node], tree[b]+=(r-(mid+1)+1)*lazy[node];
        lazy[a]+=lazy[node], lazy[b]+=lazy[node];
        lazy[node] = 0;
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
    void update(int i, int j, ll value, int node, int l, int r) {
        if(l > j || r < i)return;
        if(l >= i && r <= j) {
            lazy[node]+=value;
            tree[node]+=(r-l+1)*value;
            return;
        }
        if(lazy[node])push(node, l, r);
        int mid = l + ((r-l) >> 1);
        update(i, j, value, (node << 1)+1, l, mid);
        update(i, j, value, (node << 1)+2, mid+1, r);
        tree[node] = merge(tree[(node << 1)+1], tree[(node << 1)+2]);
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
        lazy.assign((size << 1)-1, 0);
        build(a, 0, 0, n-1);
    }
} st;
```

## Binary Indexed Tree(1D) (Fenwick tree)
```c++
struct FenwickTree {
    // 0 base indexing
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
```

## Binary Indexed Tree(2D) (Fenwick tree)
```c++
struct FenwickTree2D {
    // 0 base indexing
    vector<vector<int>> bit;
    int n, m;
    FenwickTree2D(int n, int m) {
        this->n = n;
        this->m = m;
        bit.assign(n, vector<int>(m, 0));
    }
    FenwickTree2D(vector<vector<int>>& matrix) : FenwickTree2D(matrix.size(), matrix[0].size()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                add(i, j, matrix[i][j]);
            }
        }
    }
    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
                ret += bit[i][j];
            }
        }
        return ret;
    }
    int sum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
    }
    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1)) {
            for (int j = y; j < m; j = j | (j + 1)) {
                bit[i][j] += delta;
            }
        }
    }
};
```
