/*
Problem Name: Apartments
Problem Link: https://cses.fi/problemset/task/1084/
Idea: Lower Bound
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> desired(n);
        multiset<int> apartment;
        for(int i = 0; i < n; i++) {
            cin >> desired[i];
        }
        sort(desired.begin(), desired.end());
        for(int i = 0; i < m; i++) {
            int x;
            cin >> x;
            apartment.insert(x);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            auto it = apartment.lower_bound(desired[i] - k);
            if(it != apartment.end()) {
                if(abs(*it - desired[i]) <= k) {
                    ans++;
                    apartment.erase(it);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}