/*
Problem Name: Minimal Rotation
Problem Link: https://cses.fi/problemset/task/1110/
Idea:
Complexity:
Resource: https://en.wikipedia.org/wiki/Lexicographically_minimal_string_rotation
*/
#include<bits/stdc++.h>
using namespace std;

int least_rotation(const string &s) {
    int n = s.length();
    vector<int> f(2 * n, -1);
    int k = 0;

    for (int j = 1; j < 2 * n; ++j) {
        int i = f[j - k - 1];
        while (i != -1 && s[j % n] != s[(k + i + 1) % n]) {
            if (s[j % n] < s[(k + i + 1) % n]) {
                k = j - i - 1;
            }
            i = f[i];
        }
        if (i == -1 && s[j % n] != s[(k + i + 1) % n]) {
            if (s[j % n] < s[(k + i + 1) % n]) {
                k = j;
            }
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }
    return k;
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
        int n = (int)s.size();
        int z = least_rotation(s);
        cout << s.substr(z, n-z) + s.substr(0, z) << "\n";
    }
    return 0;
}