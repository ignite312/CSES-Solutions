/*
Problem Name: Forest Queries II
Problem Link: https://cses.fi/problemset/task/1739/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
 
 
struct FenwickTree2D {
    // 0 base indexing
    vector<vector<int>> bit;
    int n, m;
    FenwickTree2D(int n, int m) {
        this->n = n;
        this->m = m;
        bit.assign(n, vector<int>(m, 0));
    }
    FenwickTree2D(vector<vector<int>>& matrix) : FenwickTree2D(matrix.size(), matrix[0].size()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                add(i, j, matrix[i][j]);
            }
        }
    }
    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
                ret += bit[i][j];
            }
        }
        return ret;
    }
    int sum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
    }
    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1)) {
            for (int j = y; j < m; j = j | (j + 1)) {
                bit[i][j] += delta;
            }
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        vector<vector<char>> grid(n, vector<char>(n));
        FenwickTree2D ft(n, n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == '*')ft.add(i, j, 1);
            }
        }
        while(q--) {
            int type;
            cin >> type;
            if(type == 1) {
                int x, y;
                cin >> x >> y;
                --x, --y;
                if(grid[x][y] == '*') {
                    grid[x][y] = '.';
                    ft.add(x, y, -1);
                }
                else  {
                    grid[x][y] = '*';
                    ft.add(x, y, 1);
                }
            }else {
                int a, b, x, y;
                cin >> a >> b >> x >> y;
                cout << ft.sum(--a, --b, --x, --y) << "\n";
            }
        }
    }
    return 0;
}
