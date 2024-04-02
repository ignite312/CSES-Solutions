/*
Problem Name: Exponentiation
Problem Link: https://cses.fi/problemset/task/1095/
Idea:
Complexity:
Resource:
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;
 

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
    int tt;
    tt = 1;
    cin >> tt;
    while(tt--) {
        ll a, b;
        cin >> a >> b;
        cout << bigPow(a, b, M) << "\n";
    }
    return 0;
}