/*
Problem Name: Josephus Problem I
Problem Link: https://cses.fi/problemset/task/2162/
Idea:
Complexity:
Resource:
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            q.push(i);
        }
        bool flag = false;
        while(q.size()) {
            int now = q.front();
            q.pop();
            if(flag)cout << now << " ";
            else q.push(now);
            flag = !flag;
        }
    }
    return 0;
}