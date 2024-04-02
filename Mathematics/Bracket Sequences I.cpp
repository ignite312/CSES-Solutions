/*
Problem Name: Bracket Sequences I
Problem Link: https://cses.fi/problemset/task/2064/
Idea: Catalan numbers
Complexity:
Resource: https://youtu.be/oZHY0FeBFtw
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;
const int N = 1e6 + 1;
int fact[N+1];
 
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
void factorial() {
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= N; i++) {
        fact[i] = (fact[i-1] * 1LL * i) % M;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    factorial();
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int _2n;
        cin >> _2n;
        if(_2n % 2 != 0) {
            cout << "0\n";
            return 0;
        }
        // Catalan Number 1/(n+1)*(2n_C_n), n left bracket and n right bracket
        int n = _2n/2;
        int numerator = fact[_2n];
        int denominator = fact[n]*1LL*fact[_2n-n] % M;
        denominator = (denominator*1LL*(n+1)) % M;
        denominator = bigPow(denominator, M-2, M);
        cout << numerator*1LL*denominator % M << "\n";
    }
    return 0;
}
