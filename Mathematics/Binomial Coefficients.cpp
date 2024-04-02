/*
Problem Name: Binomial Coefficients
Problem Link: https://cses.fi/problemset/task/1079/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 1;
const int M = 1e9 + 7;
ll fact[N+1];
 
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= N; i++) {
        fact[i] = (fact[i-1] * i) % M;
    }
    int tt;
    tt = 1;
    cin >> tt;
    while(tt--) {
        int n, r;
        cin >> n >> r;
        ll denominator = fact[r]*fact[n-r] % M;
        denominator = bigPow(denominator, M-2, M);
        cout << fact[n] * denominator % M << "\n";
    }
    return 0;
}