/*
Problem Name: Palindrome Queries
Problem Link: https://cses.fi/problemset/task/2420/
Idea:
Complexity:
Resource:
*/
// https://cses.fi/problemset/task/2420/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2000000;

int bigPow(ll base, ll power, const int mod) {
    int ans = 1 % mod;
    base %= mod;
    if (base < 0) base += mod;
    while (power) {
        if (power & 1) ans = (ll) ans * base % mod;
        base = (ll) base * base % mod;
        power >>= 1;
    }
    return ans;
}

const int M1 = 127657753, M2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> p_ip1[N], p_ip2[N];

void init() {
    p_ip1[0] = p_ip2[0] = {1, 1};
    for(int i = 1; i < N; i++) {
        p_ip1[i].first = p_ip1[i-1].first *1LL* p1 % M1;
        p_ip2[i].first = p_ip2[i-1].first *1LL* p2 % M2;
    }
    ip1 = bigPow(p1, M1-2, M1);
    ip2 = bigPow(p2, M2-2, M2);
    for(int i = 1; i < N; i++) {
        p_ip1[i].second = p_ip1[i-1].second *1LL* ip1 % M1;
        p_ip2[i].second = p_ip2[i-1].second *1LL* ip2 % M2;
    }
}

struct FenwickTree {
    // 0 base indexing
    vector<ll> bit;
    int n;
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

struct Hashing {
    // 0-base indexing
    int n;
    FenwickTree ft1, ft2;
    Hashing() : n(0), ft1(0), ft2(0) {}
    void build_hash(string &s, int size) {
        init();
        n = size;
        ft1 = FenwickTree(n);
        ft2 = FenwickTree(n);
        for(int i = 0; i < n; i++) {
            int hash_value = p_ip1[i].first*1LL*s[i] % M1;
            ft1.add(i, hash_value);
            hash_value = p_ip2[i].first*1LL*s[i] % M2;
            ft2.add(i, hash_value);
        } 
    }
    void update(int i, char c) {
        int hash_value = p_ip1[i].first*1LL*c % M1;
        ft1.add(i, (-ft1.sum(i, i) + hash_value + M1) % M1);
        hash_value = p_ip2[i].first*1LL*c % M2;
        ft2.add(i, (-ft2.sum(i, i) + hash_value + M2) % M2);
    }
    pair<int, int> get_hash(int l, int r) {
        pair<int, int> ans;
        ans.first = ((ft1.sum(l, r) + M1) % M1)*1LL*p_ip1[l].second % M1;
        ans.second = ((ft2.sum(l, r) + M2) % M2)*1LL*p_ip2[l].second % M2;
        return ans;
    }
    pair<int, int> get_hash() {return get_hash(0, n-1);}
} h, rh;

bool check_palindrome(int i, int j, int n) {
    // 0-base indexing
    return h.get_hash(i, j) == rh.get_hash(n - j - 1, n - i - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        string rs = s;
        reverse(rs.begin(), rs.end());
        h.build_hash(s, n);
        rh.build_hash(rs, n);
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int i;
                char ch;
                cin >> i >> ch;
                i--;
                h.update(i, ch);
                rh.update(n-i-1, ch);
            } else {
                int l, r;
                cin >> l >> r;
                l--, r--;
                cout << (check_palindrome(l, r, n) ? "YES\n" : "NO\n");
            }
        }
    }
    return 0;
}