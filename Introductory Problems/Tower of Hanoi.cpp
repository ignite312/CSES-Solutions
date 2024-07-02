/*
Problem Name: Tower of Hanoi
Problem Link: https://cses.fi/problemset/task/2165/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int n, int st, int en, int aux) {
    if(n == 0)return;

    TowerOfHanoi(n-1, st, aux, en);
    cout << st << " " << en << "\n";
    TowerOfHanoi(n-1, aux, en, st);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        cout << (1 << n) - 1 << "\n";
        TowerOfHanoi(n, 1, 3, 2);
    }
    return 0;
}