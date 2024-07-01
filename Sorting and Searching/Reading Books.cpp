/*
Problem Name: Reading Books
Problem Link: https://cses.fi/problemset/task/1631/
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
        int n;
        cin >> n;
        vector<ll> v(n+1), prefix(n+1, 0);
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for(int i = 1; i <= n; i++) {
          prefix[i] = prefix[i-1]+v[i];
        }
        if(v[n] > prefix[n-1]) {
          cout << prefix[n] + v[n] - prefix[n-1];
        }else cout << prefix[n] << "\n";
    }
    return 0;
}
