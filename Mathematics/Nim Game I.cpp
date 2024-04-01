/*
Problem Name: Nim Game I
Problem Link: https://cses.fi/problemset/task/1730/
Idea:
Complexity:
Resource: https://youtu.be/2GoUYpQlAUY
Another Problem: https://lightoj.com/problem/misere-nim
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
        int state = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            state^=x;
        }
        // For non-zero XOR the first player will win
        cout << (state ? "first" : "second") << "\n";
    }
    return 0;
}