/*
Problem Name: Permutations
Problem Link: https://cses.fi/problemset/task/1070/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;

vector<string> permutation(string s) {
    sort(s.begin(), s.end());
    vector<string> ans;
    do {
        ans.push_back(s);
    }while(next_permutation(s.begin(), s.end()));
    return ans;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  // cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    vector<string> ans = permutation(s);
    cout << ans.size() << "\n";
    for(auto ele : ans)cout << ele << "\n";
  }
}