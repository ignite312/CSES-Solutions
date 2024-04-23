/*
Problem Name: Concert Tickets
Problem Link: https://cses.fi/problemset/task/1091/
Idea: Binary Search(Lower bound)
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
        int n, m;
        cin >> n >> m;
        multiset<int> price;
        for(int i = 0; i < n; i++) {
            int p;
            cin >> p;
            price.insert(p);
        }
        for(int i = 0; i < m; i++) {
            int mx_p;
            cin >> mx_p;
            auto it = price.upper_bound(mx_p);
            if(it == price.begin())cout << "-1" << "\n";
            else {
                it--;
                cout << *it << "\n";
                price.erase(it);
            }
        }

    }
    return 0;
}