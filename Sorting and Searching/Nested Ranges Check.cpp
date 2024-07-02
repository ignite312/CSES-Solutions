/*
Problem Name: Nested Ranges Check
Problem Link: https://cses.fi/problemset/task/2168/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if(a.first < b.first)return true;
    if(a.first == b.first) return (a.second > b.second);
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<pair<int, int>> points(n);
        map<pair<int, int>, int> id;
        for(int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
            id[{points[i].first, points[i].second}] = i;
        }
        sort(points.begin(), points.end(), compare);
        vector<int> contained(n), contain(n);

        int mx = 0;
        for(int i = 0; i < n; i++) {
            if(mx >= points[i].second) {
                contained[id[{points[i].first, points[i].second}]] = 1;
            }
            mx = max(mx, points[i].second);
        }

        int mn = INT_MAX;
        for(int i = n-1; i >= 0; i--) {
            if(mn <= points[i].second) {
                contain[id[{points[i].first, points[i].second}]] = 1;
            }
            mn = min(mn, points[i].second);
        }
        for(int i = 0; i < n; i++) {
            cout << contain[i] << " ";
        }
        cout << "\n";
        for(int i = 0; i < n; i++) {
            cout << contained[i] << " ";
        }
        cout << "\n";
     }
    return 0;
}