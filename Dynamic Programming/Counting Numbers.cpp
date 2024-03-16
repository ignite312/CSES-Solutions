/*
Problem Name: Counting Numbers
Problem Link: https://cses.fi/problemset/task/2220

DP Category: Digit DP
Time Complexity: 
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20][10][2][2];
 
ll f(int idx, int prev_digit, int leading_zeroes, int tight, string &number, int n) {
    if(idx == n)return 1;
    if(dp[idx][prev_digit][leading_zeroes][tight] != -1 && prev_digit != -1)return dp[idx][prev_digit][leading_zeroes][tight];
 
    int lb = 0;
    int up = (tight ? number[idx] - '0' : 9);
    ll ans = 0;
    for(int digit = lb; digit <= up; digit++) {
        if(prev_digit == digit && digit != 0)continue;
        if(prev_digit == digit && digit == 0 && !leading_zeroes)continue;
        ans = ans + f(idx+1, digit, leading_zeroes & (digit == 0), tight & (digit == up), number, n);
    }
    return dp[idx][prev_digit][leading_zeroes][tight] = ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    while(tt--) {
        string a, b;
        ll x;
        cin >> x;
        x--;
        a = to_string(x);
        cin >> b;
        int ln_a = (ll)a.length();
        int ln_b = (ll)b.length();
        memset(dp, -1, sizeof(dp));
        ll ans = f(0, -1, 1, 1, b, ln_b);
        memset(dp, -1, sizeof(dp));
        cout << ans - f(0, -1, 1, 1, a, ln_a) << "\n";
    }
    return 0;
}