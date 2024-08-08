/*
Problem Name: Counting Grids
Problem Link: https://cses.fi/problemset/task/2210/
Idea:
Complexity:
Resource: https://www.youtube.com/watch?v=D0d9bYZ_qDY
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
        ll n;

        cin >> n;
        ll n_0 = n*n;
        ll n_90 = 1, n_180 = 1;
        if (n > 1 && n % 2 != 0) {
            n_90 = (n+3)*(n-1)/4 - (n-1)/2 + 1;
            n_180 = (n+3)*(n-1)/2 - (n-1) + 1;
        }
        else if(n % 2 == 0) {
            n_90 = n*(n+2)/4 - n/2;
            n_180 = n*(n+2)/2 - n;
        }
        int ans = 0;
        ans = (ans + bigPow(2, n_0, M)) % M; //0 deg
        ans = (ans + bigPow(2, n_90, M)) % M; //90 deg
        ans = (ans + bigPow(2, n_180, M)) % M; //180 deg
        ans = (ans + bigPow(2, n_90, M)) % M; //270 deg
        ans = ans *1LL* bigPow(4, M-2, M) % M;
        cout << ans << "\n";
    }
    return 0;
}