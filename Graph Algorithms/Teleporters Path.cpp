/*
Problem Name: Teleporters Path
Problem Link: https://cses.fi/problemset/task/1693/
Idea: Euler Path in Directed graph (Hierholzer’s Algorithm)
Complexity: O(E)
Resource: https://usaco.guide/adv/eulerian-tours?lang=cpp
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> adj[N+1];
int in[N+1], out[N+1];
vector<int> euler_path;
 
void dfs(int u) {
    while(!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
        dfs(v);
    }
    euler_path.push_back(u);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            out[u]++, in[v]++;        
        }
        /*
        Directed Graphs:
        Euler Circuit: All vertices must have equal in-degree and out-degree.
        Euler Path: Exactly two vertices can have a difference of one between their in-degree and out-degree.
        */
        for(int i = 1; i <= n; i++) {
            if((i == 1 && out[1]-in[1] != 1) || 
                (i == n && in[n]-out[n] != 1) ||
                (i > 1 && i < n && out[i] != in[i])) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
        dfs(1);
        reverse(euler_path.begin(), euler_path.end());
        if(euler_path.size() - 1 !=  m || euler_path.back() != n) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        for(auto x : euler_path) {cout << x << " ";}
    }
    return 0;
}