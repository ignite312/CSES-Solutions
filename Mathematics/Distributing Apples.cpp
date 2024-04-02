/*
Problem Name: Distributing Apples
Problem Link: https://cses.fi/problemset/task/1716/
Idea:
Complexity:
Resource: https://www.youtube.com/watch?v=Jb88BpY8WpM
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 1;
const int M = 1e9 + 7;
ll fact[N+1];
 
int bigPow(ll base, ll power, const int mod) {
    int ans = 1 % mod;
    base %= mod;
    while(power) {
        if(power & 1)ans = (ll)ans * base % mod;
        base = (ll)base*base % mod;
        power >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = fact[1] = 1;
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i-1]*1LL*i % M;
    }
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        ll denominator = fact[m] * fact[n-1] % M;
        denominator = bigPow(denominator, M-2, M);
        cout << fact[m + n - 1] * denominator % M <<"\n";
    }
    return 0;
}
