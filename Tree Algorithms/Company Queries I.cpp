/*
Kth Ancestor using Binary Lifting
Resource: https://www.youtube.com/watch?v=oib-XsjFa-M
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
const int LOG = 18; //LOG = ceil(log2(N))
vector<int> adj[N+1];
int up[N+1][LOG];
 
void ancestor(int u) {
    for(auto v : adj[u]) {
        up[v][0] = u;
        for(int j = 1; j < LOG; j++)up[v][j] = up[up[v][j-1]][j-1];
        ancestor(v);
    }
}
int getKthAncestor(int a, int k) {
    for(int i = LOG - 1; i >= 0; i--)
        if(k & (1 << i))
            a = up[a][i];
    return a;
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
        for(int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
        ancestor(1);
        while(q--) {
            int x, k;
            cin >> x >> k;
            int boss = getKthAncestor(x, k);
            cout << (boss ? boss : -1) << "\n";
        }
    }
    return 0;
}