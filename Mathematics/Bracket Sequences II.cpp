/*
Problem Name: Bracket Sequences II
Problem Link: https://cses.fi/problemset/task/2187/
Idea:
Complexity:
Resource:
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
        int n;
        string s;
        cin >> n >> s;
        if(n % 2 != 0) {
            cout << "0\n";
            return 0;
        }
        int o = 0, c = 0, k = (int)s.length();
        for(int i = 0; i < k; i++) {
            (s[i] == '(') ? o++ : c++;
            // check closing bracket count not exceeding opening bracket
            if(c > o) {
                cout << "0\n";
                return 0;
            }
        }
        // check opening bracket not exceding n/2
        if(o > n/2) {
            cout << "0\n";
            return 0;
        }
        // remaining closing bracket
        // (n-k)_C_(r_c) - (n-k)_C_(r_c+1)
        int r_c = n/2 - c;
        int numerator = fact[n-k];
        int denominator = fact[n-k - r_c]*1LL*fact[r_c] % M;
        int ans1 = numerator*1LL*bigPow(denominator, M-2, M) % M;
 
        denominator = fact[n-k-(r_c+1)]*1LL*fact[r_c+1] % M;
        int ans2 = numerator*1LL*bigPow(denominator, M-2, M) % M;
 
        cout << (ans1 - ans2 + M) % M << "\n";
    }
    return 0;
}