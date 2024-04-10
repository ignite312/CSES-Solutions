/*
Problem Name: Permutations
Problem Link: https://cses.fi/problemset/task/1070/
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
        if(n == 1)cout << "1\n";
        else if(n <= 3)cout << "NO SOLUTION\n";
        else if(n == 4)cout << "2 4 1 3\n";
        else {
            for(int i = 1; i <= n; i+=2) {
                cout << i << " ";
            }
            for(int i = 2; i <= n; i+=2) {
                cout << i << " ";
            }
        }
    }
    return 0;
}