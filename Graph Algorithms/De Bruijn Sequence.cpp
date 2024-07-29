/*
Problem Name: De Bruijn Sequence
Problem Link: https://cses.fi/problemset/task/1692/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1 << 14];
vector<int> euler_path;
 
void dfs(int u) {
    while(!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
        dfs(v);
    }
    euler_path.push_back((u & 1));
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
        for(int u = 0; u < (1 << n-1); u++) {
            int v = (u << 1) % (1 << n-1);
            adj[u].push_back(v);
            adj[u].push_back(v | 1);
        }
        dfs(0);
        for(int i = 0; i < n-1; i++)euler_path.push_back(0);
            euler_path.pop_back();
        for(auto x : euler_path)cout << x;
    }
    return 0;
}