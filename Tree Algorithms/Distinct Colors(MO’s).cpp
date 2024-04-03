/*
Problem Name: Distinct Colors
Problem Link: https://cses.fi/problemset/task/1139
Idea: MO’s Algorithm
Complexity: 
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
vector<int> G[N+1];
int colors[N+1];
int st[N+1], en[N+1];
int Time = 0;
 
int arr[N+1], freq[N+1], distinct;
const int rootN = 555;
 
void add(int x) {
    if(!freq[x]) distinct++;
    freq[x]++;
}
void remove(int x) {
    freq[x]--;
    if(!freq[x]) distinct--;
}
void adjust(int &curr_l, int &curr_r, int L, int R) {
    while(curr_l > L) {
        curr_l--;
        add(arr[curr_l]);
    }
    while(curr_r < R) {
        curr_r++;
        add(arr[curr_r]);
    }
    while(curr_l < L) {
        remove(arr[curr_l]);
        curr_l++;
    }
    while(curr_r > R) {
        remove(arr[curr_r]);
        curr_r--;
    }
}
void solve(vector<tuple<int, int, int>> &queries) {
    sort(queries.begin(), queries.end(), [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        int blockA = get<0>(a) / rootN;
        int blockB = get<0>(b) / rootN;
        if (blockA != blockB)
            return blockA < blockB;
        return get<1>(a) < get<1>(b);
    });
 
    auto[L, R, id] = queries[0];
    int curr_l = L, curr_r = L;
    distinct = 1;
    freq[arr[curr_l]]++;
    vector<int> ans(queries.size());
    for(auto [L, R, id] : queries) {
        adjust(curr_l, curr_r, L, R);
        ans[id] = distinct;
    }
    for(auto ele : ans) cout << ele << " ";
}
void dfs(int u, int p) {
    st[u] = ++Time;
    for(auto v : G[u]) {
        if(v == p)continue;
        dfs(v, u);
    }
    en[u] = Time;
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
        map<int, int> compress;
        int current = 1;
        for(int i = 1; i <= n; i++) {
            cin >> colors[i];
            if(compress[colors[i]]) colors[i] = compress[colors[i]];
            else {
                compress[colors[i]] = current++;
                colors[i] = compress[colors[i]];
            }
        }
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, -1);
        for(int i = 1; i <= n; i++)arr[st[i]] = colors[i];
        vector<tuple<int, int, int>> queries;
        for(int i = 1; i <= n; i++)queries.emplace_back(st[i], en[i], i-1);
        solve(queries);
    }
    return 0;
}