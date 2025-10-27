#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 200000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        ll n;
        cin >> n;
        ll mx_p1 = INT_MIN, mx_p2 = INT_MIN;
        ll mn_p1 = INT_MAX, mn_p2 = INT_MAX;
        for(ll i = 0; i < n; i++) {
          ll x, y;
          cin >> x >> y;
          ll p1 = x + y;
          ll p2 = x - y;
          mx_p1 = max(mx_p1, p1);
          mn_p1 = min(mn_p1, p1);
          mx_p2 = max(mx_p2, p2);
          mn_p2 = min(mn_p2, p2);
          cout << max(mx_p1 - mn_p1, mx_p2 - mn_p2) << "\n";
        }
    }
    return 0;
}