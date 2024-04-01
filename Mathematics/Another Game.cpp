/*
Problem Name: Another Game
Problem Link: https://cses.fi/problemset/task/2208/
Idea:
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
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        string ans = "second";
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            // first player will gift even state for every pile to the second player because all even pile is a losing state
            if(x & 1)ans = "first";
        }
        cout << ans << "\n";
    }
    return 0;
}