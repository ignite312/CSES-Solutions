/*
Problem Name: Labyrinth
Problem Link: https://cses.fi/problemset/task/1193/
Idea: BFS
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
char Grid[N+1][N+1], parent[N+1][N+1];
bool vis[N+1][N+1];
int n, m;
 
bool inside(int i, int j) {
    if(i < 0 || j < 0 || i >= n || j >= m)return false;
    if(vis[i][j] || Grid[i][j] == '#')return false;
    return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cin >> Grid[i][j];
    }
  }
  int l, r, _l, _r; //Store the position of start and end
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        if(Grid[i][j] == 'A')l = i, r = j;
        if(Grid[i][j] == 'B')_l = i, _r = j;
    }
  }
  queue<pair<int, int>> q;
  q.push({l ,r});
  vis[l][r] = true;
  bool ok = false;
  while(!q.empty()) {
    auto now = q.front();
    int i = now.first;
    int j = now.second;
    if(i == _l && j == _r) {
        ok = true;
        break;
    }
    q.pop();
    if(inside(i+1, j)) {
        vis[i+1][j] = true;
        q.push({i+1, j});
        parent[i+1][j] = 'D';
    }
    if(inside(i, j+1)) {
        q.push({i, j+1});
        vis[i][j+1] = true;
        parent[i][j+1] = 'R';
    }
    if(inside(i-1, j)) {
        q.push({i-1, j});
        vis[i-1][j] = true;
        parent[i-1][j] = 'U';
    }
    if(inside(i, j-1)) {
        q.push({i, j-1});
        vis[i][j-1] = true;
        parent[i][j-1] = 'L';
    }
  }
  string ans = "";
  if(!ok) {
    cout << "NO\n";
    return 0;
  }
  while(1) {
    if(l == _l && r == _r)break;
    ans+=parent[_l][_r];
    if(parent[_l][_r] == 'L') {
        _r++;
    }else if(parent[_l][_r] == 'R') {
        _r--;
    }
    else if(parent[_l][_r] == 'U') {
        _l++;
    }
    else if(parent[_l][_r] == 'D') {
        _l--;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << "YES" << "\n" << ans.size() << "\n" << ans << "\n";
  return 0;
}