/*
Problem Name: Fibonacci Numbers
Problem Link: https://cses.fi/problemset/task/1722/
Idea:
Complexity:
Resource: https://codeforces.com/blog/entry/14516
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;
map<ll, ll> dp;

// f(2 * k) = f(k) * f(k) + f(k - 1) * f(k - 1)
// f(2 * k + 1) = f(k) * f(k + 1) + f(k - 1) * f(k)
ll f(ll n) {
    if(n == 0 || n == 1)return dp[n] = 1;
    if(dp[n])return dp[n];
    ll k = n/2;
    if(n % 2 == 0)return dp[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
    return dp[n] = (f(k)*f(k+1) + f(k-1) * f(k)) % M;
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
        cout << (n == 0 ? 0 : f(n-1));
    }
    return 0;
}
