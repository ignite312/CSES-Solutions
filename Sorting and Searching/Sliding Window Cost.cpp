/*
Problem Name: Sliding Window Cost
Problem Link: https://cses.fi/problemset/task/1077/
Idea: Sliding Window Median
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<ll> v(n);
        multiset<ll> left, right;
        ll left_sum = 0LL, right_sum = 0LL;
        int l = k - (k+1)/2;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(i < k) {
                left.insert(v[i]);
                left_sum+=v[i];
            }
        }
        while(l--) {
            auto it = left.end();
            it--;
            right.insert(*it);
            right_sum+=*it;
            left_sum-=*it;
            left.erase(it);
        }
        for(int i = k; i < n; i++) {
            auto it = left.end();
            it--;
            cout << (*it)*(int)left.size() - left_sum + right_sum - (*it)*(int)right.size() << " ";
            it = left.find(v[i-k]);
            if(it != left.end()) {
                left_sum-=*it;
                left.erase(it);
            }
            else {
                right_sum-=v[i-k];
                right.erase(right.find(v[i-k]));
            }
            if(v[i] > *right.begin() && right.size()) {
                right.insert(v[i]);
                right_sum+=v[i];
            }
            else {
                left.insert(v[i]);
                left_sum+=v[i];
            }
 
            if(left.size() < right.size()) {
                left.insert(*right.begin());
                left_sum+=*right.begin();
                right_sum-=*right.begin();
                right.erase(right.begin());
            }
            while(left.size() - right.size() > 1) {
                auto it = left.end();
                it--;
                right.insert(*it);
                right_sum+=*it;
                left_sum-=*it;
                left.erase(it);
            }
        }
        auto it = left.end();
        it--;
        cout << (*it)*(int)left.size() - left_sum + right_sum - (*it)*(int)right.size() << " ";
    }
    return 0;
}
