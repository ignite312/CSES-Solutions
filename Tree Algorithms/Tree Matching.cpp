#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
vector<int> G[N+1];
int ans;
bool visited[N+1];

void dfs(int u, int p) {
    for(auto v : G[u]) {
        if(v == p)continue;
        dfs(v, u);
        if(!visited[u] && !visited[v])ans++, visited[u] = visited[v] = true;
    }
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
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, -1);
        cout << ans << "\n";
    }
    return 0;
}
// Greedy method are used here
// Can be solved using Hopcroft–Karp algorithm
// https://en.wikipedia.org/wiki/Hopcroft–Karp_algorithm
// implementation: https://zobayer.blogspot.com/2010/05/maximum-matching.html
