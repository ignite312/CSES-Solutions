/*
Problem Name: Number Spiral
Problem Link: https://cses.fi/problemset/task/1071/
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
        ll a[2][2] = {{1,2}, {4,3}};
        ll n, m;
        cin >> n >> m;
        if(n < 3 && m < 3)cout << a[n-1][m-1] << "\n";
        else {
            if(n == m) {
                cout << (n-1)*(n-1) + n << "\n";
            }else if(n > m) {
                if(n % 2 == 0) {
                    cout << n*n - (m-1) << "\n";
                }else {
                    cout << (n-1)*(n-1) + m << "\n";
                }
            }else {
                if(m % 2 == 0) {
                    cout << (m-1)*(m-1) + n << "\n";
                }else {
                    cout << m*m - (n-1) << "\n";
                }
            }
        }
    }
    return 0;
}