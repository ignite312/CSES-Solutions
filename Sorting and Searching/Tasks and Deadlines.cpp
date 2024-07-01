/*
Problem Name: Tasks and Deadlines
Problem Link: https://cses.fi/problemset/task/1630/
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
        vector<array<ll, 2>> pr(n);
        for(int i = 0; i < n; i++) {
          cin >> pr[i][0] >> pr[i][1];
        }
        sort(pr.begin(), pr.end());
        ll st = 1;
        ll ans = 0;
        for(int i = 0; i < n; i++) {
          ans+=pr[i][1]-(st+pr[i][0]-1);
          st += pr[i][0];
        }
        cout << ans << "\n";
    }
    return 0;
}