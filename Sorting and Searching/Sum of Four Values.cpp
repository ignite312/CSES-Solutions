/*
Problem Name: Sum of Four Values
Problem Link: https://cses.fi/problemset/task/1642/
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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
          cin >> v[i];
        }
        unordered_map<int, pair<int, int>> _2sum_idx;
        for(int i = 0; i < n; i++) {
          for(int j = i+1; j < n; j++) {
            _2sum_idx[v[i]+v[j]] = {i+1, j+1};
          }
        }
        for(int i = 0; i < n; i++) {
          for(int j = i+1; j < n; j++) {
            int r_sum = k - (v[i] + v[j]);
            if(_2sum_idx.count(r_sum)) {
              if(_2sum_idx[r_sum].first > j+1) {
                cout << i + 1 << " " << j + 1 << " " << _2sum_idx[r_sum].first << " " << _2sum_idx[r_sum].second << "\n";
                return 0;
              }
            }
          }
        }
        cout << "IMPOSSIBLE\n" << "\n";
    }
    return 0;
}
