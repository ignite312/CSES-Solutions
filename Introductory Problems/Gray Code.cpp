/*
Problem Name: Gray Code
Problem Link: https://cses.fi/problemset/task/2205/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
 
vector<string> generateGrayCode(int n) {
    if(n == 1) {
        return {"0", "1"};
    }
    vector<string> prevGC = generateGrayCode(n-1);
    vector<string> r_pGC = prevGC;
    reverse(r_pGC.begin(), r_pGC.end());
 
    int sz = prevGC.size();
    for(int i = 0; i < sz; i++) {
        prevGC[i] = "0" + prevGC[i];
        r_pGC[i] = "1" + r_pGC[i];
        prevGC.push_back(r_pGC[i]);
    }
    return prevGC;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<string> grayCodes = generateGrayCode(n);
        for(int i = 0; i < (int)grayCodes.size(); i++) {
            cout << grayCodes[i] << "\n";
        }
    }
    return 0;
}