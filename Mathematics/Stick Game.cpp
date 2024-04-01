/*
Problem Name: Stick Game
Problem Link: https://cses.fi/problemset/task/1729/
Idea:
Complexity:
Resource: https://youtu.be/2GoUYpQlAUY
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
bool dp[N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> moves(k);
        for(int i = 0; i < k; i++) {
            cin >> moves[i];
        }
        for(int i = 1; i <= N; i++) {
            bool ok = false;
            for(int j = 0; j < k; j++) {
                if(i - moves[j] >= 0) {
                    if(!dp[i - moves[j]]) {
                        ok = true;
                    }
                }
                dp[i] = ok;
            }
        }
        for(int i = 1; i <= n; i++)cout << (dp[i] ? "W" : "L");
     }
    return 0;
}