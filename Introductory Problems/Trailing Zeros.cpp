/*
Problem Name: Trailing Zeros
Problem Link: https://cses.fi/problemset/task/1618/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;

int trailingZeros(int n) {
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;
    return count;
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
        cout << trailingZeros(n) << "\n";
    }
    return 0;
}