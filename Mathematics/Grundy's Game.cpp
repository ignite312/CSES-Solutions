/*
Problem Name: Grundy's Game
Problem Link: https://cses.fi/problemset/task/2207/
Idea:
Complexity:
Resource: https://youtu.be/2GoUYpQlAUY
*/
#include<bits/stdc++.h>
using namespace std;

int mex(const vector<int>& _mex) {
    set<int> st(_mex.begin(), _mex.end());
    for (int i = 0; ; i++)if(!st.count(i)) return i;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> dp(2000, 0);
    for(int i = 3; i < 2000; i++) {
        vector<int> _mex;
        for(int j = 1; i - j > j; j++) {
            _mex.push_back(dp[j] ^ dp[i-j]);
        }
        dp[i] = mex(_mex);
    }
    int tt;
    tt = 1;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        if(n >= 2000) {
            cout << "first\n";
            continue;
        }
        cout << (dp[n] > 0 ? "first" : "second") << "\n";
    }
    return 0;
}
