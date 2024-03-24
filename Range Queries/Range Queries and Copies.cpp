/*
Problem Name: Range Queries and Copies
Problem Link: https://cses.fi/problemset/task/1737/
Idea: Persistent Segment Tree
Complexity: 
Resource: https://www.youtube.com/watch?v=mLlaIj_8lv0
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200005;

struct persistentSegtree {
    // 0 base indexing
    ll data;
    persistentSegtree *left, *right;

    ll merge(ll x, ll y) {
        return x + y;
    }
    void build(vector<ll> &a, int l, int r) {
        if(l == r) {
            data = a[l];
            return;
        }
        int mid = l + ((r - l) >> 1);
        left = new persistentSegtree();
        right = new persistentSegtree();
        left->build(a, l, mid);
        right->build(a, mid+1, r);
        data = merge(left->data, right->data);
    }
    persistentSegtree* update(int i, ll value, int l, int r) {
        if(l > i || r < i) return this;
        if(l == i && r == i) {
            persistentSegtree *rslt = new persistentSegtree();
            rslt->data = value;
            return rslt;
        }
        int mid = l + ((r-l) >> 1);
        persistentSegtree *rslt = new persistentSegtree();

        rslt->left = left->update(i, value, l, mid);
        rslt->right = right->update(i, value, mid+1, r);
        rslt->data = merge(rslt->left->data, rslt->right->data);

        return rslt;
    }
    ll query(int i, int j, int l, int r) {
        if(l > j || r < i) return 0;
        if(l >= i && r <= j)return data;
        int mid = l + ((r - l) >> 1);
        return merge(left->query(i, j, l, mid), right->query(i, j, mid+1, r));
    }
} *roots[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, q, k = 0;
        cin >> n >> q;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        roots[0] = new persistentSegtree();
        roots[k++]->build(a, 0, n-1);
        while(q--) {
            int type;
            cin >> type;
            if(type == 1) {
                int _k, i;
                ll x;
                cin >> _k >> i >> x;
                --_k;
                roots[_k] = roots[_k]->update(--i, x, 0, n-1);
            }else if(type == 2) {
                int _k, i, j;
                cin >> _k >> i >> j;
                cout << roots[--_k]->query(--i, --j, 0, n-1) << "\n";
            }else {
                int _k;
                cin >> _k;
                roots[k++] = roots[--_k];
            }
        }
    }
    return 0;
}
// Idea from Mahmudul Yeamim