/*
Problem Name: Range Queries and Copies
Problem Link: https://cses.fi/problemset/task/1737/
Idea:
Complexity:
Resource:
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define ll long long
#define ff first
#define ss second
#define pb push_back
 
struct psegtree {
    ll data;
    psegtree *left, *right;
 
    psegtree() {
        data = 0;
        left = NULL;
        right = NULL;
    }
 
    ll merge(ll a, ll b) {
        return a + b;
    }
 
    void build(vector<int> &a, int lx, int rx) {
        if(rx - lx == 1) {
            data = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        left = new psegtree();
        right = new psegtree();
        left->build(a, lx, m);
        right->build(a, m, rx);
        data = merge(left->data, right->data);
    }
 
    psegtree* update(int i, int val, int lx, int rx) {
        if(i < lx || rx <= i) {
            return this;
        }
        if(rx - lx == 1) {
            psegtree *ret = new psegtree();
            ret->data = val;
            return ret;
        }
        int m = (lx + rx) / 2;
        psegtree *ret = new psegtree();
        ret->left = left->update(i, val, lx, m);
        ret->right = right->update(i, val, m, rx);
        ret->data = merge(ret->left->data, ret->right->data);
        return ret;
    }
 
    ll calc(int l, int r, int lx, int rx) {
        if(rx <= l || r <= lx) {
            return 0;
        }
        if(l <= lx && rx <= r) {
            return data;
        }
        int m = (lx + rx) / 2;
        ll s1 = left->calc(l, r, lx, m);
        ll s2 = right->calc(l, r, m, rx);
        return merge(s1, s2);
    }
 
} *roots[200005];
 
void solve(){
    int n; cin >> n;
    int q; cin >> q;
    vector <int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int k = 0;
    roots[k] = new psegtree();
    roots[k++]->build(a, 0, n);
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int idx, i, val; cin >> idx >> i >> val;
            idx--, i--;
            roots[idx] = roots[idx]->update(i, val, 0, n);
        }
        else if(op == 2) {
            int idx, l, r; cin >> idx >> l >> r;
            idx--, l--;
            cout << roots[idx]->calc(l, r, 0, n) << '\n';
        }
        else {
            int idx; cin >> idx;
            idx--;
            roots[k++] = roots[idx];
        }
    }
}
 
signed main(){
    fastio; int tc = 1; //cin >> tc; 
    for(int cs = 1; cs <= tc; cs++){
        //cout << "Case " << cs << ": ";
        solve();
    }
}
// // Code from mahmudulyeamim