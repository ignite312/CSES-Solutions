/*
Problem Name: Planets Queries I
Problem Link: https://cses.fi/problemset/task/1750/
Idea: kth descendant using binary lifting
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 200000;
const int LOG = 30; // LOG = ceil(log2(N))
int descendant[N+1][LOG];
 
int kthDescendant(int u, int k) {
    for(int i = LOG-1; i >= 0; i--) {
        if(k & (1 << i)) {
            u = descendant[u][i];
        }
    }
    return u;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        for(int u = 1; u <= n; u++) {
            int v;
            cin >> v;
            descendant[u][0] = v;
        }
        for(int k = 1; k < LOG; k++) {
            for(int u = 1; u <= n; u++) {
                descendant[u][k] = descendant[descendant[u][k-1]][k-1];
            }
        }
        while(q--) {
            int u, k;
            cin >> u >> k;
            cout << kthDescendant(u, k) << "\n";
        }
    }
    return 0;
}