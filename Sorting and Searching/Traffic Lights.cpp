/*
Name: Traffic Lights
Link: https://cses.fi/problemset/task/1163/
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
        int x, n;
        cin >> x >> n;
        vector<int> v(n);
        set<int> st = {0, x};
        multiset<int> seg = {x};
        for(int i = 0; i < n; i++) {
            int p;
            cin >> p;
            auto it = st.upper_bound(p);
            int right = *it;
            it--;
            int left = *it;
            seg.erase(seg.find(right-left));
            seg.insert(right-p);
            seg.insert(p-left);
            st.insert(p);
            it = seg.end();
            it--;
            cout << *it << " ";
        }
    }
    return 0;
}