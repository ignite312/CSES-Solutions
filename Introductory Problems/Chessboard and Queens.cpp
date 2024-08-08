/*
Problem Name: Chessboard and Queens
Problem Link: https://cses.fi/problemset/task/1624/
Idea:
Complexity:
Resource: Competitive Programmer’s Handbook (Page: 50)
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 8;
char board[N][N];
int ans;
int column[N], diag1[15], diag2[15];

void search(int y) {
    if (y == N) {
        ans++;
        return;
    }
    for (int x = 0; x < N; x++) {
        if (board[y][x] == '.' && !column[x] && !diag1[x + y] && !diag2[x - y + N - 1]) {
            column[x] = diag1[x + y] = diag2[x - y + N - 1] = 1;
            search(y + 1);
            column[x] = diag1[x + y] = diag2[x - y + N - 1] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }
        search(0);
        cout << ans << "\n";
    }
    return 0;
}