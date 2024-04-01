/*
Problem Name: Stair Game
Problem Link: https://cses.fi/problemset/task/1099/
Idea: 
Complexity:
Resource: https://youtu.be/2GoUYpQlAUY
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        ll _xor = 0;
        for(int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            if(i % 2 != 0 && i != 0)_xor^=x;
        }
        cout << (_xor ? "first\n" : "second\n");
    }
    return 0;
}