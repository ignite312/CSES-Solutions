/*
Problem Name: Counting Divisors
Problem Link: https://cses.fi/problemset/task/1713/
Idea:
Complexity: O(sqrt(n))
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int divisor[N+1];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j+=i) {
            divisor[j]++;
        }
    }
    int tt;
    tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        cout << divisor[n] << "\n";
    }
    return 0;
}