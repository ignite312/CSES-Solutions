/*
Problem Name: Josephus Problem II
Problem Link: https://cses.fi/problemset/task/2163/
Idea:
Complexity:
Resource:
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        int st = 0, en = k % n;
        ordered_set os;
        for(int i = 1; i <= n; i++) {
            os.insert(i);
        }
        while(os.size()) {
            int val = *os.find_by_order(en);
            cout << val << " ";
            os.erase(val);
            st = en;
            if(os.size())en = (st + (k % os.size())) % os.size();
        }
    }
    return 0;
}