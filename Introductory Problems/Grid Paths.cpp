/*
Problem Name: Grid Paths
Problem Link: https://cses.fi/problemset/task/1625/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 9; // grid size
const int K = 48; // path length
const int dir = 4; // total direction
int row_offset[dir] = {0, 0, -1, 1}; // L R U D
int col_offset[dir] = {-1, 1, 0, 0}; // L R U D
vector<int> path(K);
bool visited[N][N];

int calculate(int idx, int i, int j) {
    if(visited[i-1][j] && visited[i+1][j] &&
        !visited[i][j-1] && !visited[i][j+1]) return 0;

    if(!visited[i-1][j] && !visited[i+1][j] &&
        visited[i][j-1] && visited[i][j+1]) return 0;

    if(i == 7 && j == 1) return (idx == K) ? 1 : 0;
    if(idx == K)return 0;

    visited[i][j] = true;
    int ans = 0;
    if(path[idx] < dir) {
        int next_i = i + row_offset[path[idx]];
        int next_j = j + col_offset[path[idx]];
        if(!visited[next_i][next_j])ans += calculate(idx+1, next_i, next_j);
    }else {
        for(int p = 0; p < dir; p++) {
            int next_i = i + row_offset[p];
            int next_j = j + col_offset[p];
            if(!visited[next_i][next_j])ans+=calculate(idx+1, next_i, next_j);
        }
    }
    visited[i][j] = false;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        for(int i = 0; i < K; i++) {
            if(s[i] == 'L')path[i] = 0;
            else if(s[i] == 'R')path[i] = 1;
            else if(s[i] == 'U')path[i] = 2;
            else if(s[i] == 'D')path[i] = 3;
            else path[i] = 4;
        }
        for(int i = 0; i < N; i++) {
            visited[i][8] = visited[8][i] = visited[0][i] = visited[i][0] = true;
        }
        cout << calculate(0, 1, 1);
    }
    return 0;
}
