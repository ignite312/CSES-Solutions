/*
Problem Name: Increasing Array Queries
Problem Link: https://cses.fi/problemset/task/2416/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
struct Node {
    vector<ll> v, pref;
    ll cnt;
};
struct Segtree {
    // 0 base indexing
    int n;
    vector<Node> tree;
    vector<int> _nodes;
 
    void merge(Node x, Node &y, Node &z) {
        vector<ll> l, r;
        l = x.v, r = y.v;
        int lst = l.back();
        int idx = lower_bound(r.begin(), r.end(), lst) - r.begin();
        ll cnt = x.cnt + y.cnt;
        for(int i = 0; i < idx; i++)l.push_back(lst);
        for(int i = idx; i < (int)r.size(); i++)l.push_back(r[i]);
        if(idx > 0)cnt += idx*1LL*lst - y.pref[idx-1];

        vector<ll> pref(l.size());
        pref[0] = l[0];
        for(int i = 1; i < (int)l.size(); i++) pref[i] = pref[i-1]+l[i];

        z.v = l;
        z.pref = pref;
        z.cnt = cnt;
    }
    void build(vector<ll> &a, int node, int l, int r) {
        if(l == r) {
            tree[node].v.push_back(a[l]);
            tree[node].pref.push_back(a[l]);
            tree[node].cnt = 0;
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(a, (node << 1)+1, l, mid);
        build(a, (node << 1)+2, mid+1, r);
        merge(tree[(node << 1)+1], tree[(node << 1)+2], tree[node]);
    }
    void query(int i, int j, int node, int l, int r) {
        if(l > j || r < i) return;
        if(l >= i && r <= j) {
            _nodes.push_back(node); // Storing the segment in a vector for offline Queries
            return;
        }
        int mid = l + ((r - l) >> 1);
        query(i, j, (node << 1)+1, l, mid), query(i, j, (node << 1)+2, mid+1, r);
        return;
    }
    ll query(int i, int j) {
        // This is offline query. I Collected all the segment that will make (i to j)segment and then I merged them to reduce the time complexity
        query(i, j, 0, 0, n-1);
        ll cnt = tree[_nodes[0]].cnt;
        int lst = tree[_nodes[0]].v.back();
        for(int i = 1; i < (int)_nodes.size(); i++) {
            cnt+=tree[_nodes[i]].cnt;
            int idx = lower_bound(tree[_nodes[i]].v.begin(), tree[_nodes[i]].v.end(), lst) - tree[_nodes[i]].v.begin();
            if(idx > 0)cnt += idx*1LL*lst - tree[_nodes[i]].pref[idx-1];
            if(idx != (int)tree[_nodes[i]].v.size())lst = tree[_nodes[i]].v.back();
        }
        _nodes.clear();
        return cnt;
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
        vector<ll> a(n);
        for(int i = 0; i < n; i++)cin >> a[i];
        st.init(a, n);
        while(q--) {
            int l, r;
            cin >> l >> r;
            cout << st.query(l-1, r-1) << "\n";
        }
    }
    return 0;
}