/*
Problem Name: Throwing Dice
Problem Link: https://cses.fi/problemset/task/1096/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

struct Matrix {
    int a[6][6] = {0};
    Matrix operator *(const Matrix& other) {
        Matrix product;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 6; k++) {
                    product.a[i][k] = (product.a[i][k] + (ll) a[i][j] * other.a[j][k]) % M;
                }
            }
        }
        return product;
    }
};
Matrix expo_power(Matrix a, ll k) {
    Matrix product;
    for (int i = 0; i < 6; i++) {
        product.a[i][i] = 1;
    }
    while (k > 0) {
        if (k % 2) {
            product = product * a;
        }
        a = a * a;
        k /= 2;
    }
    return product;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        ll k;
        cin >> k;
        Matrix m;
        for(int i = 0; i < 6; i++) {
          if(i != 0)m.a[i][i-1] = 1;
          m.a[0][i] = 1;
        }

        Matrix ans = expo_power(m, k);
        vector<int> f = {16, 8, 4, 2, 1, 1}; // f[5]....f[0];
        int ways = 0;
        for(int i = 0; i < 6; i++) {
          ways = (ways + (f[i]*1LL*ans.a[5][i]) % M) % M;
        }
        cout << ways << "\n";
    }
    return 0;
}