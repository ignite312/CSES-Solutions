#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
const int Mx = log2(1e9+1)+1;
int descendant[N+1][Mx+1];

int kthDescendant(int u, int k) {
    for(int i = Mx; i >= 0; i--) {
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
        for(int k = 1; k <= Mx; k++) {
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
// Main idea: kth anchestor using binary lifting
// I used here kth descendant using binary lifting
// Similar problem : https://github.com/ignite312/CpStuff/blob/main/Graph/LCA%2BKth(BinaryLifting).cpp
