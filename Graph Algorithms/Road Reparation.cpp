/*
Problem Name: Road Reparation
Problem Link: https://cses.fi/problemset/task/1675/
Idea: Minimum Spanning Tree - Kruskal’s Algorithm
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200000;
vector<tuple<ll, int, int>> G;
int parent[N+1], Size[N+1];
 
void make_set(int v) {
    parent[v] = v;
    Size[v] = 1;
}
int find_set(int v) {
    if (v == parent[v])return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if(Size[a] < Size[b])swap(a, b);
        parent[b] = a;
        Size[a]+=Size[b];
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        ll wt;
        cin >> u >> v >> wt;
        G.emplace_back(wt, u, v);
    }
    sort(G.begin(), G.end());
    for(int i = 1; i <= n; i++)make_set(i);
    vector<pair<int, int>> MST;
    ll ans = 0;
    for(auto[wt, u, v] : G) {
        if(find_set(u) != find_set(v)) {
            union_sets(u, v);
            ans+=wt;
            MST.emplace_back(u, v);
        }
    }
    set<int> st;
    for(int i = 1; i <= n; i++)st.insert(find_set(i));
        
    if(st.size() > 1)cout << "IMPOSSIBLE\n";
    else cout << ans << "\n";
  }
}