/*
Problem Name: Distinct Values Queries
Problem Link: https://cses.fi/problemset/task/1734/
Idea: MO's Algorithm
Complexity:O((N+Q)sqrt(N))
Resource: https://cp-algorithms.com/data_structures/sqrt_decomposition.html
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int arr[N+5], freq[N+5], distinct;
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
    for(auto ele : ans) cout << ele << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        map<int, int> compress;
        int current = 1;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            if(compress[arr[i]]) arr[i] = compress[arr[i]];
            else {
                compress[arr[i]] = current++;
                arr[i] = compress[arr[i]];
            }
        }
        vector<tuple<int, int, int>> queries;
        for(int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            queries.emplace_back(l, r, i);
        }
        solve(queries);
    }
}