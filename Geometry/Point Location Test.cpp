/*
Problem Name: Point Location Test
Problem Link: https://cses.fi/problemset/task/2189/
Idea:
Complexity:
Resource: Competitive Programmer’s Handbook - Page 268
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef complex<double> P;
#define X real()
#define Y imag()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    cin >> tt;
    while(tt--) {
        double x1, x2, x3, y1, y2, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        P a = {x1, y1};
        P b = {x2, y2};
        P c = {x3, y3};
        // Cross Product of c-a and c-b
        if((conj(c-a)*(c-b)).Y > 0)cout << "LEFT\n";
        else if((conj(c-a)*(c-b)).Y < 0)cout << "RIGHT\n";
        else cout << "TOUCH\n";
    }
    return 0;
}