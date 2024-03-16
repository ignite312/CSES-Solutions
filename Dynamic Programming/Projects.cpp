/*
Problem Name: Projects
Problem Link: https://cses.fi/problemset/task/1140/

DP Category:
Time Complexity: 
Resource:

Here Dp[i] = maximum amount of money we can earn before the day i
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<pair<pair<int, int>, int>> seg(n);
        set<int> st;
        for (int i = 0; i < n; i++) {
            int l, r, value;
            cin >> l >> r >> value;
            seg[i] = {{++r, l}, value};
            st.insert(l), st.insert(r);
        }
        map<int, int> id;
        vector<vector<pair<int, int>>> check(st.size());
        int i = 0;
        for (auto it : st) {
            id[it] = i++;
        }
        for (int i = 0; i < n; i++) {
            check[id[seg[i].first.first]].push_back({seg[i].first.second, seg[i].second});
        }
        vector<ll> dp(st.size(), 0);
        for (int i = 0; i < st.size(); i++) {
            if (i > 0) {
                dp[i] = dp[i - 1];
            }
            for (auto it : check[i]) {
                dp[i] = max(dp[i], dp[id[it.first]] + it.second);
            }
        }
        cout << dp[st.size() - 1] << "\n";
    }
}