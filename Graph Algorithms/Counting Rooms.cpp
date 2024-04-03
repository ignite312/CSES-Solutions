/*
Problem Name: Counting Rooms
Problem Link: https://cses.fi/problemset/task/1192/
Idea: DFS
Complexity:
Resource:
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<string> Grid(N);
bool vis[N + 1][N + 1];
int n, m;

bool inside(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    if (vis[i][j] || Grid[i][j] == '#')
        return false;
    return true;
}
void dfs(int i, int j) {
    vis[i][j] = true;
    if (inside(i + 1, j))
        dfs(i + 1, j);
    if (inside(i, j + 1))
        dfs(i, j + 1);
    if (inside(i - 1, j))
        dfs(i - 1, j);
    if (inside(i, j - 1))
        dfs(i, j - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> Grid[i];
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && Grid[i][j] != '#') {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
