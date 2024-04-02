/*
Problem Name: Distinct Numbers
Problem Link: https://cses.fi/problemset/task/1621/
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
        set<int> st;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            st.insert(x);
        }
        cout << st.size();
    }
    return 0;
}