/*
Problem Name: Room Allocation
Problem Link: https://cses.fi/problemset/task/1164/
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
        map<int, vector<pair<int, int>> >values;
        set<int> st;
        for(int i = 0; i < n; i++) {
          int a, d;
          cin >> a >> d;
          values[a].push_back({d, i});
          st.insert(a);
        }
        int room_no = 0;
        multiset<pair<int, int>> ms;
        vector<int> empty;
        vector<int> ans(n);
        for(auto x : st) {
          while((*ms.begin()).first < x && ms.size()) {
            empty.push_back((*ms.begin()).second);
            ms.erase(ms.begin());
          }
          while(values[x].size()) {
            if(empty.size()) {
              ans[values[x].back().second] = empty.back();
              ms.insert({values[x].back().first, empty.back()});
              empty.pop_back();
            }else {
              ms.insert({values[x].back().first, ++room_no});
              ans[values[x].back().second] = room_no;
            }
            values[x].pop_back();
          }
        }
        cout << room_no << "\n";
        for(auto x : ans) {
          cout << x << " ";
        }cout << "\n";
    }
    return 0;
}