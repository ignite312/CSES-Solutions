/*
Problem: https://cses.fi/problemset/task/1653/
DP Category: Bitmask DP
Resource: https://cses.fi/book/book.pdf (Page 103-)
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
        vector<int> w(n);
        for(int i = 0; i < n; i++)cin >> w[i];
        vector<pair<int, int>> best(1 << n);
        best[0] = {1, 0};
 
        for(int mask = 1; mask < (1 << n); mask++) {
            best[mask] = {n+1, 0};
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    auto option = best[mask ^ (1 << i)];
                    if(option.second + w[i] <= x) {
                        option = {option.first, option.second + w[i]};
                    }else option = {option.first+1, w[i]};
                    best[mask] = min(best[mask], option);
                }
            }
            best[mask] = best[mask];
        }
        cout << best[(1 << n)-1].first << "\n";
    }
    return 0;
}