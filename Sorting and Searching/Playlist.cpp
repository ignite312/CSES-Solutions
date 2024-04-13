/*
Problem Name: Playlist
Problem Link: https://cses.fi/problemset/task/1141/
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
        int n;
        cin >> n;
        int ans = -1;
        set<int> st;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            int sz = (int)st.size();
            st.insert(x);
            if((int)st.size() > sz) {
                ans = max(ans, sz+1);
            }else {
                while(q.front() != x) {
                    st.erase(q.front());
                    q.pop();
                }
                q.pop();
            }
            q.push(x);
        }
        cout << ans << "\n";
    }
    return 0;
}