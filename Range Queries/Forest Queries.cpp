/*
Problem Name: Forest Queries
Problem Link: https://cses.fi/problemset/task/1652
Idea: Prefix Sum
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> grid(n+1, vector<int> (n+1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                char ch;
                cin >> ch;
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
                if(ch == '*')grid[i][j]++;
            }
        }
        while(q--) {
            int x, y, a, b;
            cin >> x >> y >> a >> b;
            cout << grid[a][b] - grid[a][y-1] - grid[x-1][b] + grid[x-1][y-1] << "\n";
        }
    }
}
