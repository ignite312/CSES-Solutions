/*
Small To Large Technique
Complexity: 
Here, "suffix_u[i]" means the total number of paths whose length between i and infinity starts from vertex u to all of its descendants
Resource: https://github.com/ignite312/CpStuff/tree/main/Tree/Small%20to%20Large%20Merging(DSU%20on%20Tree)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 1;
vector<int> adj[N+1];
int n, k1, k2;
ll ans;
 
int getSuffixValue(deque<int> &suffix, int idx) {
    if(idx >= (int)suffix.size()) return 0;
    if(idx < 0)return suffix[0];
    return suffix[idx];
}
void merge(deque<int> &suffix_u, deque<int> &suffix_v) {
    if(suffix_u.size() < suffix_v.size())swap(suffix_u, suffix_v);
    for(int i = 0; i < (int)suffix_v.size(); i++) {
        ans+=(getSuffixValue(suffix_v, i) - getSuffixValue(suffix_v, i+1))*1LL*(getSuffixValue(suffix_u, k1 - i) - (getSuffixValue(suffix_u, k2 - i + 1)));
    }
    for(int i = 0; i < (int)suffix_v.size(); i++) suffix_u[i]+=suffix_v[i];
}
deque<int> f(int u, int p) {
    deque<int> suffix_u{1};
    for(auto v : adj[u]) {
        if(v == p)continue;
        deque<int> suffix_v = f(v, u);
        suffix_v.push_front(suffix_v.front());
        merge(suffix_u, suffix_v);
    }
    return suffix_u;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n >> k1 >> k2;
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        f(1, -1);
        cout << ans << '\n';
    }
}