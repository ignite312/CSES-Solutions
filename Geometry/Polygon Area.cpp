/*
Problem Name: Polygon Area
Problem Link: https://cses.fi/problemset/task/2191/
Idea:
Complexity:
Resource: Competitive Programmer’s Handbook - Page 271
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
        int n;
        cin >> n;
        vector<array<ll, 2>> points(n);
        for(int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        ll area = 0;
        for(int i = 0; i < n-1; i++) {
            area+=(points[i][0]*points[i+1][1] - points[i+1][0]*points[i][1]);
        }
        area += (points[n - 1][0] * points[0][1] - points[0][0] * points[n - 1][1]);
        cout << abs(area) << "\n";
    }
    return 0;
}