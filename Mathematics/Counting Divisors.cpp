/*
Problem Name: Counting Divisors
Problem Link: https://cses.fi/problemset/task/1713/
Idea:
Complexity: O(sqrt(n))
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
 
int divisor(int a) {
    int ans = 0;
    for (int i = 1; i*i <= a; ++i) {
        if(a % i == 0) {
            if(a / i == i)ans++;
            else {
                ans+=2;
            }
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cout << divisor(x) << "\n";
        }
    }
    return 0;
}