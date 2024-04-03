/*
Problem Name: Shortest Routes II
Problem Link: https://cses.fi/problemset/task/1672/
Idea: Floyd Warshall
Complexity: N^3
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 500;
const ll INF = LLONG_MAX;
ll d[N+1][N+1];
int n, m;
 
void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }
}
void floydWarshall() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] < INF && d[k][j] < INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                } 
            }
        }
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  while(tt--) {
    int q;
    cin >> n >> m >> q;
    init();
    for(int i = 1; i <= m; i++) {
        int u, v;
        ll wt;
        cin >> u >> v >> wt;
        --u, --v;
        d[u][v] = min(d[u][v], wt);
        d[v][u] = min(d[v][u], wt);
    }
    floydWarshall();
    while(q--) {
        int st, en;
        cin >> st >> en;
        --st, --en;
        if(d[st][en] != INF)cout << d[st][en] << "\n";
        else cout << "-1" << "\n";
    }
  }
  return 0;
}