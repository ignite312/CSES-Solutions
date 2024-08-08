/*
Problem Name: Candy Lottery
Problem Link: https://cses.fi/problemset/task/1727/
Idea:
Complexity:
Resource: https://codeforces.com/blog/entry/62690
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
        int n, k;
        cin >> n >> k;
        double ans = 0;
        for(int i = 1; i <= k; i++) {
            // We want to find the probability that the maximum number of candies any child gets is exactly i
            double a = 1.0; // a =  the probability that all n children get a number between 1 and i
            double b = 1.0; // b =  the probability that all n children get a number between 1 and i-1
            for(int j = 1; j <= n; j++) {
                a *= (double)i/k;
                b *=(double)(i-1)/k;
            }
            ans+=(double)(a-b)*i;
        }
        cout << fixed << setprecision(6) << ans << "\n";
    }
    return 0;
}