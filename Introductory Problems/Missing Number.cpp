/*
Problem Name: Missing Number
Problem Link: https://cses.fi/problemset/task/1083/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        ll n;
        cin >> n;
        vector<int> arr(n);
        map<int, int> mp;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        for(int i = 1; i <= n;  i++) {
            if(!mp[i]) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}
