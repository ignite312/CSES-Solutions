/*
Problem: https://cses.fi/problemset/task/1145/
DP Category: LIS
Resource: https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
*/
#include <bits/stdc++.h>
using namespace std;

int lis(int n, vector<int> &a) {
    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    d[0] = -INF;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j - 1] < a[i])
            d[j] = a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        if (d[i] < INF)
            ans = i;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << lis(n, a) << "\n";
    }
    return 0;
}