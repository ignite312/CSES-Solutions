/*
Problem Name: Towers
Problem Link: https://cses.fi/problemset/task/1073/
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
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        multiset<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++) {
          auto it = st.upper_bound(v[i]);
          if(it == st.end()) {
            ans++;
            st.insert(v[i]);
          }else {
            st.erase(it);
            st.insert(v[i]);
          }
        }
        cout << ans << "\n";
    }
    return 0;
}
