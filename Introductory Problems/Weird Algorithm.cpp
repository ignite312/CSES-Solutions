/*
Problem Name: Weird Algorithm
Problem Link: https://cses.fi/problemset/task/1068/
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
    // cin >> tt;
    while(tt--) {
        ll n;
        cin >> n;
        while(1) {
            cout << n << " ";
            if(n == 1)break;
            if(n % 2 == 0)n/=2;
            else n = n*3+1;
        }
    }
    return 0;
}