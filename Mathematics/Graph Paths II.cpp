/*
Problem Name: Graph Paths II
Problem Link: https://cses.fi/problemset/task/1724/
Idea: Matrix Exponentiation
Complexity: Matrix Exponentiation
Resource:
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = LLONG_MAX;

struct Matrix {
    int n, m;
    vector<vector<ll>> a;
    Matrix(int n, int m) : n(n), m(m), a(n, vector<ll>(m, INF)) {}

    Matrix operator*(const Matrix& other) const {
        Matrix product(n, other.m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < other.m; ++j) {
                for (int k = 0; k < m; ++k) {
                    if(a[i][k] != INF && other.a[k][j] != INF)
                        product.a[i][j] = min(product.a[i][j], a[i][k] + other.a[k][j]);
                }
            }
        }
        return product;
    }
};

Matrix expo_power(Matrix a, ll k, int n) {
    Matrix product(n, n);

    bool first_phase = true;
    while (k > 0) {
        if (k % 2) {
            if(first_phase) {
                first_phase = false;
                product = a;
            }else product = product * a;
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
    while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        Matrix matrix(n, n);
        for (int i = 0; i < m; i++) {
            int u, v;
            ll wt;
            cin >> u >> v >> wt;
            --u, --v;
            matrix.a[u][v] = min(matrix.a[u][v], wt);
        }
        matrix = expo_power(matrix, k, n);
        cout << (matrix.a[0][n - 1] == INF ? -1 : matrix.a[0][n - 1]) << "\n";
    }
    return 0;
}