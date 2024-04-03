/*
Problem Name: Subordinates
Problem Link: https://cses.fi/problemset/task/1674
Idea: Subtree
Complexity: 
Resource: 
Related Problem : https://codeforces.com/contest/1946/problem/C
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
vector<int> adj[N+1];
int subtree[N+1], n;
 
void dfs(int node, int parent) {
    for(auto child : adj[node]) {
        if(child == parent)continue;
        dfs(child, node);
        subtree[node] += subtree[child] + 1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        cin >> n;
        for(int i = 2; i <= n; i++) {
            int u;
            cin >> u;
            adj[u].push_back(i);
            adj[i].push_back(u);
        }
        dfs(1, -1);
        for(int i = 1; i <= n; i++)cout << subtree[i] << " ";
            cout << "\n";
    }
    return 0;
}