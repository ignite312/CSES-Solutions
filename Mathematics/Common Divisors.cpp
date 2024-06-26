/*
Problem Name: Common Divisors
Problem Link: https://cses.fi/problemset/task/1081/
Idea:
Complexity: O(N*Sqrt(N))
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int divisors[N+1];
 
void divisor(int a) {
    for (int i = 1; i*i <= a; ++i) {
        if(a % i == 0) {
            if(a / i == i)divisors[i]++;
            else {
                divisors[i]++;
                divisors[a/i]++;
            }
        }
    }
    return;
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
            divisor(x);
        }
        for(int i = N; i >= 1; i--) {
            if(divisors[i] >= 2) {
                cout << i << "\n";
                return 0;
            }
        }
    }
    return 0;
}