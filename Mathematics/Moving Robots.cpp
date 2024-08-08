/*
Problem Name: Moving Robots
Problem Link: https://cses.fi/problemset/task/1726/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 8;
int offset_x[] = {-1, 1, 0, 0}; // L R U D
int offset_y[] = {0, 0, 1, -1};
double dp[101][N][N];
double ans[N][N];

void init(int _k) {
    for(int k = 0; k <= _k; k++) {
        for(int x = 0; x < N; x++) {
            for(int y = 0; y < N; y++) {
                dp[k][x][y] = 0;
            }
        }
    }
}
bool inside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int _k;
        cin >> _k;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                ans[i][j] = 1.0;
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                init(_k);
                dp[0][i][j] = 1.0;
                for(int k = 0; k <= _k; k++) {
                    for(int x = 0; x < N; x++) {
                        for(int y = 0; y < N; y++) {
                            double dir_cnt = 0;
                            for(int d = 0; d < 4; d++) {
                                if(inside(x + offset_x[d], y + offset_y[d])) {
                                    dir_cnt++;
                                }
                            }
                            for(int d = 0; d < 4; d++) {
                                if(inside(x + offset_x[d], y + offset_y[d])) {
                                    dp[k+1][x + offset_x[d]][y + offset_y[d]]+=dp[k][x][y]/dir_cnt;
                                }
                            }
                        }
                    }
                }
                for(int i = 0; i < N; i++) {
                    for(int j = 0; j < N; j++) {
                        ans[i][j]*=(1-dp[_k][i][j]);
                    }
                }
            }
        }
        double EN = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                EN+=ans[i][j];
            }
        }
        cout << fixed << setprecision(6) << EN << "\n";
    }
    return 0;
}