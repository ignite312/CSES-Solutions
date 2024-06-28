/*
Problem Name: Nearest Smaller Values
Problem Link: https://cses.fi/problemset/task/1645/
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
        stack<pair<int, int>> st;
        st.push({0, 0});
        for(int i = 0; i < n; i++) {
          while(st.top().first >= v[i]) {
            st.pop();
          }
          cout << st.top().second << " ";
          st.push({v[i], i+1});
        }
    }
    return 0;
}
