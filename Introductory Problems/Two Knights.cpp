/*
Problem Name: Two Knights
Problem Link: https://cses.fi/problemset/task/1072/
Idea:
Complexity:
Resource:
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
        ll _n;
        cin >> _n;
        for(ll n = 1; n <= _n; n++) {
            if(n < 3)cout << n*n*(n*n-1)/2 << "\n";
            else cout << n*n*(n*n-1)/2 - (n-3+1)*(n-2+1)*2*2 << "\n";
        }
    }
    return 0;
}
