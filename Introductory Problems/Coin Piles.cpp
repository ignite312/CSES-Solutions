/*
Problem Name: Coin Piles
Problem Link: https://cses.fi/problemset/task/1754/
Idea:
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
    cin >> tt;
    while(tt--) {
        ll a, b;
        cin >> a >> b;
        /*
        x+2*y = a....(i)  2*x+y = b...(ii)
                    2*(a-2*y) + y = b
                    2*a - 4*y + y = b
                    2*a - b = 3*y

                    x+2*(b-2*x) = a
                    2*b - a = 3*x
        */
        if((2*a - b) % 3 == 0 && 2*a - b >= 0 && (2*b-a) % 3 == 0 && 2*b-a >= 0)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}