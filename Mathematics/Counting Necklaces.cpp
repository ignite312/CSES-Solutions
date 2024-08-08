/*
Problem Name: Counting Necklaces
Problem Link: https://cses.fi/problemset/task/2209/
Idea: Burnside’s Lemma
Complexity:
Resource: https://www.geeksforgeeks.org/orbit-counting-theorem-or-burnsides-lemma/
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int bigPow(ll b, ll p, const int M) {
    int ans = 1;
    b %= M;
    if (b < 0) b += M;
    while (p) {
        if (p & 1) ans = (ll) ans * b % M;
        b = (ll) b * b % M;
        p >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;

        cin >> n >> m;
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ans = (ans + bigPow(m, __gcd(i, n), M)) % M;
        }
        n = bigPow(n, M-2, M);
        ans = (ans*n) % M;
        cout << ans << "\n";
    }
    return 0;
}