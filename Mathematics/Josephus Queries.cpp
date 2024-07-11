/*
Problem Name: Josephus Queries
Problem Link: https://cses.fi/problemset/task/2164/
Idea:
Complexity:
Resource: https://www.geeksforgeeks.org/cses-solutions-josephus-queries/
*/
#include<bits/stdc++.h>
using namespace std;

int calculateKth(int n, int kth) {
  if(n == 1) {
    return 1;
  }
  if(kth <= (n+1)/2) {
    if(kth*2 > n)return 1;
    else return kth*2;
  }
  int t_kth = calculateKth(n/2, kth-(n+1)/2);
  if(n % 2 == 0)return t_kth*2 - 1;
  return t_kth*2 + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    cin >> tt;
    while(tt--) {
        int n, kth;
        cin >> n >> kth;
        cout << calculateKth(n, kth) << "\n";
    }
    return 0;
}