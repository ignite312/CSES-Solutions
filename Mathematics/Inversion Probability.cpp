/*
Problem Name: Inversion Probability
Problem Link: https://cses.fi/problemset/task/1728/
Idea:
Complexity:
Resource:
*/
#include <bits/stdc++.h>
#include <quadmath.h>

using namespace std;

void print_float128(__float128 value) {
    // Use sprintf to convert __float128 to string and print
    char buffer[128];
    sprintf(buffer, "%.6f", (double)value); // Casting to double for printing
    cout << buffer << "\n";
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
        vector<__float128> a(n);  //__float128 for high precision
        for(int i = 0; i < n; i++) {
            double temp;
            cin >> temp;
            a[i] = temp;
        }
        __float128 ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                __float128 inv_cnt = 0;
                if(a[i] >= a[j]) {
                    inv_cnt = a[j] * (a[j] - 1) / 2 + a[j] * (a[i] - a[j]);
                } else {
                    inv_cnt = a[i] * (a[i] - 1) / 2;
                }
                ans += inv_cnt / (a[i] * a[j]);
            }
        }
        print_float128(ans);
    }
    return 0;
}