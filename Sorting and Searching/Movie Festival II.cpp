/*
Problem Name: Movie Festival II
Problem Link: https://cses.fi/problemset/task/1632/
Idea: Greedy
Complexity:
Resource: https://usaco.guide/problems/cses-1632-movie-festival-ii/solution
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
        vector<pair<int, int>> time(n);
        for(int i = 0; i < n; i++) {
            cin >> time[i].second >> time[i].first;
        }
        sort(time.begin(), time.end());
        multiset<int> track;
        for(int i = 0; i < k; i++) track.insert(-1);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            auto it = track.upper_bound(time[i].second);
            if(it == track.begin())continue; //Everyone Busy watching Movie
            track.erase(--it);
            track.insert(time[i].first);
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}