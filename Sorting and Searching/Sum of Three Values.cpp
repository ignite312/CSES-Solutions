/*
Problem Name: Sum of Three Values
Problem Link: https://cses.fi/problemset/task/1641/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
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
        unordered_map<int, int, custom_hash> idx;
        for(int i = 0; i < n; i++) {
          cin >> v[i];
          idx[v[i]] = i+1;
        }
        for(int i = 0; i < n; i++) {
          for(int j = i+1; j < n; j++) {
            int r_sum =  k - (v[i]+v[j]);
            if(idx.count(r_sum)) {
              if(idx[r_sum] != i+1 && idx[r_sum] != j+1) {
                cout << i+1 << " " << j+1 << " " << idx[r_sum] << "\n";
                return 0;
              }
            }
          }
        }
        cout << "IMPOSSIBLE\n" << "\n";
    }
    return 0;
}