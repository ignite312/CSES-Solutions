/*
Problem Name: Exponentiation II
Problem Link: https://cses.fi/problemset/task/1712/
Idea:
Complexity:
Resource: https://usaco.guide/problems/cses-1712-exponentiation-ii/solution
*/
#include<bits/stdc++.h>
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
        int a, b, c;
        cin >> a >> b >> c;
        ll t_ans = bigPow(b, c, M-1);
        cout << bigPow(a, t_ans, M) << "\n";
    }
    return 0;
}