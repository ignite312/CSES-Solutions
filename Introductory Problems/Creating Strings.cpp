/*
Problem Name: Creating Strings
Problem Link: https://cses.fi/problemset/task/1622/
Idea: Next Permutation
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  while(tt--) {
    string s;
    cin >> s;
    vector<string> ans;
    sort(s.begin(), s.end());
    string temp = s;
    ans.push_back(s);
    while(1) {
        next_permutation(s.begin(), s.end());
        if(s == temp)break;
        ans.push_back(s);
    }
    cout << ans.size() << "\n";
    for(auto ele : ans)cout << ele << "\n";
  }
}