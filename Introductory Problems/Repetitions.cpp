/*
Problem Name: Repetitions
Problem Link: https://cses.fi/problemset/task/1069/
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
    // cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        int cnt = 1, ans = INT_MIN;
        for(int i = 1; i < (int)s.length(); i++) {
            if(s[i] == s[i-1])cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        cout << max(ans, cnt) << "\n";
    }
    return 0;
}