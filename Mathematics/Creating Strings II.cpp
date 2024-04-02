/*
Problem Name: Creating Strings II
Problem Link: https://cses.fi/problemset/task/1715/
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
        string s;
        cin >> s;
        vector<int> hsh(26, 0);
        for(int i = 0; i < (int)s.size(); i++) {
            hsh[s[i]-'a']++;
        }
        ll denominator = 1LL;
        for(int i = 0; i < 26; i++) {
            denominator = (denominator*fact[hsh[i]]) % M;
        }
        denominator = bigPow(denominator, M-2, M);
        cout << fact[(int)s.size()] * denominator % M <<"\n";
    }
    return 0;
}
