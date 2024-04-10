/*
Problem Name: Two Sets
Problem Link: https://cses.fi/problemset/task/1092/
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
        int n;
        cin >> n;
        if(n % 4 == 0) {
            cout << "YES\n" << n/2 << "\n";
            for(int i = 1, j = n; i <= n/2; i+=2, j-=2) {
                cout << i << " " << j << " ";
            }
            cout << "\n" << n/2 << "\n";
            for(int i = 2, j = n-1; i <= n/2; i+=2, j-=2) {
                cout << i << " " << j << " ";
            }
        }else if(n % 4 == 3) {
            cout << "YES\n" << n/2 + 1 << "\n";
            for(int i = 1, j = n-1; i <= n/2; i+=2, j-=2) {
                cout << i << " " << j << " ";
            }
            cout << "\n" << n/2  << "\n" << n  << " ";
            for(int i = 2, j = n-2; i <= n/2; i+=2, j-=2) {
                cout << i << " " << j << " ";
            }
        }else cout << "NO\n";
    }
    return 0;
}