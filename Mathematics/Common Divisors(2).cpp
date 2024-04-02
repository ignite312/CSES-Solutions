/*
Problem Name: Common Divisors
Problem Link: https://cses.fi/problemset/task/1081/
Idea:
Complexity: O(N*log(N))
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int occurrence[N+1];
 
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
            occurrence[x]++;
        }
        for(int gcd = N; gcd >= 1; gcd--) {
            int found = 0;
            for(int j = gcd; j <= N; j+=gcd) {
                found+=occurrence[j];
            }
            if(found >= 2) {
                cout << gcd << "\n";
                return 0;
            }
        }
    }
    return 0;
}