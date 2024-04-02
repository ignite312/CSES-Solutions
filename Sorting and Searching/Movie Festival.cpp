/*
Problem Name: Movie Festival
Problem Link: https://cses.fi/problemset/task/1629/
Idea: Greedy
Complexity:
Resource: https://www.geeksforgeeks.org/cses-solutions-movie-festivals/
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
        int n;
        cin >> n;
        vector<pair<int, int>> time(n);
        for(int i = 0; i < n; i++) {
            cin >> time[i].second >> time[i].first;
        }
        sort(time.begin(), time.end());
        int ans = 1;
        int en = time[0].first;
        for(int i = 1; i < n; i++) {
            if(time[i].second >= en) {
                ans++;
                en = time[i].first;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}