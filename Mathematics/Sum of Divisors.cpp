/*
Problem Name: Sum of Divisors
Problem Link: https://cses.fi/problemset/task/1082/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
#define ll long long
 
 
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
    // cin >> tt;
    while(tt--) {
        ll n;
        cin >> n;
        ll ans = 0;
        for(ll i = 1; i*i <= n; i++) {
            ans = (ans + ((n/i) * i) % M) % M;
        }
        ll lo = sqrt(n);
        // 1  2 3 4 5 6 7 8 9 10  11  12 13 14 15
        // 15 7 5 3 3 2 2 1 1  1  1   1  1  1  1
        // Illustrate this example for better understanding
        for(int i = lo; i >= 1; i--) {
            ll hi = n/i;
            ll sum = ((hi % M) * ((hi+1) % M) % M) * bigPow(2, M-2, M);
            sum = sum % M;
            sum = sum - (((lo % M) * ((lo+1) % M) % M) * bigPow(2, M-2, M)) % M;
            sum = (sum + M) % M;
            sum = sum*i % M;
            ans = (ans + sum) % M;
            lo = hi;
        }
        cout << ans << "\n";
    }
    return 0;
}