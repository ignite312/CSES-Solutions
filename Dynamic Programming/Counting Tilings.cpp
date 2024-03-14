/*
Problem: https://cses.fi/problemset/task/2181
DP Category: Bitmask DP
Resource: 
*/
#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1000+1;
int n, m;
int dp[N+1][(1 << 10)+1];

void generateNextMasks(int curr_mask, int i, int mask, vector<int> &next_masks) {
    if(i == n) {
        next_masks.push_back(mask);
        return;
    }

    if(curr_mask & (1 << i))
        generateNextMasks(curr_mask, i+1, mask, next_masks);
    if(!(curr_mask & (1 << i)))
        generateNextMasks(curr_mask, i+1, mask + (1 << i), next_masks);
    if(i != n-1) {
        if(!(curr_mask & (1 << i)) && !(curr_mask & (1 << (i+1))))
            generateNextMasks(curr_mask, i+2, mask, next_masks);
    }
}
int f(int col, int curr_mask) {
    if(col == m+1)return (curr_mask == 0);
    if(dp[col][curr_mask] != -1)return dp[col][curr_mask];

    vector<int> next_masks;
    generateNextMasks(curr_mask, 0, 0, next_masks);
    int ans = 0;
    for(auto mask : next_masks) {
        ans = (ans + f(col+1, mask) % M ) % M;
    }
    next_masks.clear();
    return dp[col][curr_mask] = ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> m;
        memset(dp, -1, sizeof(dp));
        cout << f(1, 0) % M << "\n";
    }
    return 0;
}