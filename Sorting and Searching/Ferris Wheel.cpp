/*
Problem Name: Ferris Wheel
Problem Link: https://cses.fi/problemset/task/1090/
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
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for(int i = 0; i  < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int lo = 0, hi = n-1;
        int ans = 0;
        while(lo < hi) {
            if(v[hi] + v[lo] <= x) {
                ans++;
                lo++, hi--;
            }else {
                ans++;
                hi--;
            }
        }
        if(lo == hi)ans++;
        cout << ans << "\n";
    }
    return 0;
}