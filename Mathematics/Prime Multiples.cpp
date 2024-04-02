/*
Problem Name: Prime Multiples
Problem Link: https://cses.fi/problemset/task/2185/
Idea:
Complexity:
Resource: https://www.youtube.com/watch?v=2UEYCzKXh1s
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        ll n;
        int k;
        cin >> n >> k;
        vector<ll> primes(k);
        for(int i = 0; i < k; i++) {
            cin >> primes[i];
        }
        ll ans = 0LL;
        for(int r = 1; r <= k; r++) {
            for(int mask = 0; mask < (1 << k); mask++) {
                if(__builtin_popcount(mask) != r)continue;
                ll d = 1LL;
                for(ll i = 0; i < k; i++) {
                    if(mask & (1 << i)) {
                        if(d > n/primes[i]) { // Overflow checking if d*primes[i] > n 
                            d = n + 1;
                            break;
                        }else d*=primes[i];
                    }
                }
                if(r % 2 == 0)ans-=n/d;
                else ans+=n/d;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}