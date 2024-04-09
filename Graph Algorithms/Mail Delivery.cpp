/*
Problem Name: Mail Delivery
Problem Link: https://cses.fi/problemset/task/1691/
Idea: Euler Circuit in undirected graph (Hierholzer’s Algorithm)
Complexity: O(E)
Resource: https://usaco.guide/adv/eulerian-tours?lang=cpp
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<pair<int, int>> adj[N+1];
int degree[N+1];
bool visited[2*N+1]; // total edge size
vector<int> euler_path;
 
 
void dfs(int u) {
    while(!adj[u].empty()) {
        auto [v, idx] = adj[u].back();
        adj[u].pop_back();
        if(visited[idx])continue;
        visited[idx] = true;
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
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
            degree[u]++, degree[v]++;
        }
        /*
        Undirected Graphs:
        Euler Circuit: All vertices must have even degree.
        Euler Path: Exactly zero or two vertices can have odd degree.
        */
        for(int i = 1; i <= n; i++) {
            if(degree[i] % 2 != 0) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
        dfs(1);
        if(euler_path.size() !=  m+1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        for(auto x : euler_path) {cout << x << " ";}
    }
    return 0;
}
