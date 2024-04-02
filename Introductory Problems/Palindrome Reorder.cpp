/*
Problem Name: Palindrome Reorder
Problem Link: https://cses.fi/problemset/task/1755/
Idea:
Complexity:
Resource:
*/
#include <bits/stdc++.h>
using namespace std;
int hsh[26];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    for(int i = 0; i < (int)s.length(); i++) {
        hsh[s[i] - 'A']++;
    }
    int cnt = 0, flag = -1;
    for(int i = 0; i < 26; i++) {
        if(hsh[i] % 2 != 0) {
            cnt++;
            flag = i;
        }
    }
    if(cnt > 1)cout << "NO SOLUTION\n";
    else if(cnt == 0) {
        for(int i = 0; i < 26; i++) {
            cout << string(hsh[i]/2, (char)(i + 'A'));
        }
        for(int i = 25; i >= 0; i--) {
            cout << string(hsh[i]/2, (char)(i + 'A'));
        }
    }else {
        for(int i = 0; i < 26; i++) {
            if(i == flag)continue;
            else cout << string(hsh[i]/2, (char)(i + 'A'));
        }
        cout << string(hsh[flag], (char)(flag + 'A'));
        for(int i = 25; i >= 0; i--) {
            if(flag == i)continue;
            else cout << string(hsh[i]/2, (char)(i + 'A'));
        }
    }cout << "\n";
}