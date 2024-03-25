/*
Problem Name: Distinct Values Queries
Problem Link: https://cses.fi/problemset/task/1734/
Idea: Segment tree
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
            tree[node] += value;
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
    int query(int i, int j, int node, int l, int r) {
        if(l > j || r < i) return 0;
        if(l >= i && r <= j)return tree[node];
        int mid = l + ((r - l) >> 1);
        return merge(query(i, j, (node << 1)+1, l, mid), query(i, j, (node << 1)+2, mid+1, r));
    }
    int query(int i, int j) {
        return query(i, j, 0, 0, n-1);
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
    // cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        map<int, int> last_seen;
        vector<vector<pair<int, int>>> queries(n+1);
        vector<int> ans(q+1), v(n, 0);
        for(int i = 1; i <= q; i++) {
            int l, r;
            cin >> l >> r;
            queries[r].push_back({l, i});
        }
        st.init(v, n);
        for(int i = 1; i <= n; i++) {
            int now = arr[i];
            if(last_seen[arr[i]]) {
                st.update(last_seen[now]-1, -1);
            }
            st.update(i-1, 1);
            last_seen[now] = i;
            for(auto seg : queries[i]) {
                ans[seg.second] = st.query(seg.first-1, i-1);
            }
        } 
        for(int i = 1; i <= q; i++) {cout << ans[i] << "\n";}
    }
    return 0;
}