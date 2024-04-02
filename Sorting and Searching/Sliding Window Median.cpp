/*
Problem Name: Sliding Window Median
Problem Link: https://cses.fi/problemset/task/1076/
Idea: Sliding Window
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
        multiset<int> left, right;
 
        int l = k - (k+1)/2;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(i < k)left.insert(v[i]);
        }
        while(l--) {
            auto it = left.end();
            it--;
            right.insert(*it);
            left.erase(it);
        }
        for(int i = k; i < n; i++) {
            auto it = left.end();
            it--;
            cout << *it << " ";
            it = left.find(v[i-k]);
            if(it != left.end())left.erase(it);
            else right.erase(right.find(v[i-k]));
            if(v[i] > *right.begin() && right.size())right.insert(v[i]);
            else left.insert(v[i]);
 
            if(left.size() < right.size()) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            while(left.size() - right.size() > 1) {
                auto it = left.end();
                it--;
                right.insert(*it);
                left.erase(it);
            }
        }
        auto it = left.end();
        it--;
        cout << *it << "\n";
    }
    return 0;
}