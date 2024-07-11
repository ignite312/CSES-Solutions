/*
Problem Name: Digit Queries
Problem Link: https://cses.fi/problemset/task/2431/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// O(log(power))
ll bigPow(ll base, ll power) {
    ll ans = 1;
    while (power) {
        if (power & 1) ans = (ll) ans * base;
        base = (ll) base * base;
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
        ll nth;
        cin >> nth;

        int digits = 1;
        ll base = 9;
        // Find interval
        while(nth - base*digits > 0) {
          nth-=base*digits;
          digits++;
          base*=10;
        }
        int idx = nth % digits; // index in the number that contain nth digit

        ll number = bigPow(10, digits-1) + (nth-1)/digits; // Number that contain nth digit
        if(idx != 0)number = number/bigPow(10, digits-idx);
        cout << number % 10 << "\n";
    }
    return 0;
}