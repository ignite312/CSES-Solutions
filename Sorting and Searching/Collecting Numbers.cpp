/*
Problem Name: Collecting Numbers
Problem Link: https://cses.fi/problemset/task/2216/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        map<int, int> idx;
        int ans = 0;
        for(int i = 0; i < n; i++) {
          int x;
          cin >> x;
          if(!idx[x-1])ans++;
          idx[x]++;
        }
        cout << ans << "\n";
    }
    return 0;
}