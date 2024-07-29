/*
Problem Name: Knight's Tour
Problem Link: https://cses.fi/problemset/task/1689/
Idea: Warnsdorf’s rule
Complexity:
Resource: Competitive Programmer's Handbook Page 189
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 8;
const int M = 8; // Possible moves
int valid_moves[N][N], ans[N][N];
bool visited[N][N];
int row_offset[M] = {-2,-2,2,2,-1,1,-1,1}; // UL, UR, DL, DR, LU, LD, RU, RD
int col_offset[M] = {-1,1,-1,1,-2,-2,2,2}; // UL, UR, DL, DR, LU, LD, RU, RD
 
bool is_valid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}
void init() {
    for(int x = 0; x < N; x++) {
        for(int y = 0; y < N; y++) {
            for(int k = 0; k < M; k++) {
                int next_x = x + row_offset[k];
                int next_y = y + col_offset[k];
                if(is_valid(next_x, next_y))
                    valid_moves[next_x][next_y]++;
            }
        }
    }
}
 
void check(int id, int x, int y, bool mark) {
    ans[x][y] = (mark) ? id : -1;
    visited[x][y] = (mark) ? true : false;
 
    for(int k = 0; k < N; k++) {
        int next_x = x + row_offset[k];
        int next_y = y + col_offset[k];
        if(is_valid(next_x, next_y) && !visited[next_x][next_y])
            mark ? valid_moves[next_x][next_y]++ : valid_moves[next_x][next_y]--;
    }
 
}
bool find_tour(int id, int x, int y) {
    check(id, x, y, true);
    if(id == 64)return true;
 
    vector<array<int, 3>> options;
    for(int k = 0; k < N; k++) {
        int next_x = x + row_offset[k];
        int next_y = y + col_offset[k];
        if(is_valid(next_x, next_y) && !visited[next_x][next_y])
            options.push_back({valid_moves[next_x][next_y], next_x, next_y});
    }
    sort(options.begin(), options.end());
    for(auto tp : options)if(find_tour(id+1, tp[1], tp[2])) {return true;}
 
    check(id, x, y, false);
    return false;
 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        find_tour(1, y, x);
 
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}