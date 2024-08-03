/*
Problem Name: Counting Coprime Pairs
Problem Link: https://cses.fi/problemset/task/2417/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1000000;
vector<int> d[N+1];
ll valuesDivisibleBy[N+1], primeDivisors[N+1];

void divisors() {
    for(int i = 2; i <= N; i++) {
        if(d[i].size())continue;
        for(int j = i; j <= N; j+=i) {
            d[j].push_back(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    divisors();
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for(int i = 0; i < n; i++) {
            for(int mask = 1; mask < (1 << d[v[i]].size()); mask++) {
                int count = 0;
                int number = 1;
                for(int idx = 0; idx < d[v[i]].size(); idx++) {
                    if(mask & (1 << idx)) {
                        count++;
                        number*=d[v[i]][idx];
                    }
                }
                valuesDivisibleBy[number]++;
                primeDivisors[number] = count;
            }
        }
        ll ans = n*1LL*(n-1)/2;
        for(int i = 2; i <= N; i++) {
            if(primeDivisors[i] % 2 != 0) {
                ans-=valuesDivisibleBy[i]*(valuesDivisibleBy[i]-1)/2;
            }else {
                ans+=valuesDivisibleBy[i]*(valuesDivisibleBy[i]-1)/2;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}