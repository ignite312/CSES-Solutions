/*
Problem Name: Longest Palindrome
Problem Link: https://cses.fi/problemset/task/1111/
Idea: Manacher
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> manacher(string t) {
    string s;
    for(auto c: t) {
        s += string("#") + c;
    }
    s+="#";
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

// 0-base indexing
bool is_palindrome(int l, int r, vector<int> &pal) {
    l++, r++;
    int range = (r - l) + 1;
    l = (l << 1) - 1;
    r = (r << 1) - 1;
    int mid = (l + r) >> 1;
    return pal[mid] >= range; 
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pal = manacher(s);

    priority_queue<int> ans;
    for(int i = 0; i < (int)pal.size(); i++) {
        if(i % 2 == 0) {
            ans.push((pal[i]/2)*2);
        }else {
            ans.push((int)ceil(pal[i]/2.0)*2 - 1);
        }
    }
    int mx = ans.top();
    for(int i = 0; i < n-mx+1; i++) {
        if(is_palindrome(i, i+mx-1, pal)) {
            cout << s.substr(i, mx) << "\n";
            break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}