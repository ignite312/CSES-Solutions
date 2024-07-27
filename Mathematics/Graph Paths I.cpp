/*
Problem Name: Graph Paths I
Problem Link: https://cses.fi/problemset/task/1723/
Idea: Matrix Exponentiation
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

struct Matrix {
    int n, m;
    vector<vector<int>> a;
    Matrix(int n, int m) : n(n), m(m), a(n, vector<int>(m)) {}

    Matrix operator*(const Matrix& other) const {
        Matrix product(n, other.m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    product.a[i][j] = (product.a[i][j] + (ll)a[i][k] * other.a[k][j]) % M;
                }
            }
        }
        return product;
    }
};

Matrix expo_power(Matrix a, ll k, int n) {
    Matrix product(n, n);
    for (int i = 0; i < n; i++) {
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
        int n, m, k;
        cin >> n >> m >> k;
        Matrix matrix(n, n);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            matrix.a[u][v]++;
        }
        matrix = expo_power(matrix, k, n);
        cout << matrix.a[0][n-1] << "\n";
    }
    return 0;
}
