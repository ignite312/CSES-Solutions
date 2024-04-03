/*
Problem Name: Monsters
Problem Link: https://cses.fi/problemset/task/1194/
Idea: BFS
Complexity:
Resource:
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
char Grid[N + 1][N + 1], parent[N + 1][N + 1];
int d_A[N+1][N+1], d_M[N+1][N+1];
int n, m;
 
bool inside(int i, int j, vector<vector<bool>> &vis, char ch) {
    if (i < 0 || j < 0 || i >= n || j >= m) return false;
    if (vis[i][j] || Grid[i][j] == '#' || Grid[i][j] == ch) return false;
    return true;
}
void bfs(vector<vector<bool>> &vis, char ch, queue<pair<int, int>> &q, 
    vector<vector<int>> &d) {
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        int i = now.first;
        int j = now.second;
        if (inside(i + 1, j, vis, ch)) {
            vis[i + 1][j] = true;
            q.push({i + 1, j});
            parent[i + 1][j] = 'D';
            d[i+1][j] = d[i][j] + 1;
        }
        if (inside(i, j + 1, vis, ch)) {
            q.push({i, j + 1});
            vis[i][j + 1] = true;
            parent[i][j + 1] = 'R';
            d[i][j+1] = d[i][j] + 1;
        }
        if (inside(i - 1, j, vis, ch)) {
            q.push({i - 1, j});
            vis[i - 1][j] = true;
            parent[i - 1][j] = 'U';
            d[i-1][j] = d[i][j] + 1;
        }
        if (inside(i, j - 1, vis, ch)) {
            q.push({i, j - 1});
            vis[i][j - 1] = true;
            parent[i][j - 1] = 'L';
            d[i][j-1] = d[i][j] + 1;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> Grid[i][j];
        int l, r;
        queue<pair<int, int>> q_M, q_A;
        vector<vector<bool>> vis_M(n, vector<bool> (m, false));
        vector<vector<int>> d_M(n, vector<int> (m, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (Grid[i][j] == 'A') l = i, r = j;
                if (Grid[i][j] == 'M') {
                    q_M.push({i, j});
                    vis_M[i][j] = true;
                    d_M[i][j] = 0;
                }
            }
        }
        bfs(vis_M, 'A', q_M, d_M);
        vector<vector<bool>> vis_A(n, vector<bool> (m, false));
        vector<vector<int>> d_A(n, vector<int> (m, INT_MAX));
        q_A.push({l, r});
        d_A[l][r] = 0;
        bfs(vis_A, 'M', q_A, d_A);
        bool ok = false;
        int x, y;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == n-1 || j == m-1 || i == 0 || j == 0) {
                    if(d_A[i][j] < d_M[i][j]) {
                        x = i, y = j;
                        ok = true;
                    }
                }
            }
        }
        string ans = "";
        if (!ok) {
            cout << "NO\n";
            return 0;
        }
        while (1) {
            if (l == x && r == y) break;
            ans += parent[x][y];
            if (parent[x][y] == 'L') {
                y++;
            }
            else if (parent[x][y] == 'R') {
                y--;
            }
            else if (parent[x][y] == 'U') {
                x++;
            }
            else if (parent[x][y] == 'D') {
                x--;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << "YES" << "\n" << ans.size() << "\n" << ans << "\n";
    }
}