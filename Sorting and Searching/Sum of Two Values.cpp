/*
Problem Name: Sum of Two Values
Problem Link: https://cses.fi/problemset/task/1640/
Idea:
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
        int n, x;
        cin >> n >> x;
        map<int, int> cnt;
        int ans[] = {-1, -1};
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if(cnt[x-a]) {
                ans[0] = i+1;
                ans[1] = cnt[x-a];
            }
            cnt[a] = i+1;
        }
        if(ans[0] == -1)cout << "IMPOSSIBLE\n";
        else cout << ans[0] << " " << ans[1]<< "\n";
    }
    return 0;
}