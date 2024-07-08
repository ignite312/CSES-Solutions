/*
Problem Name: Collecting Numbers II
Problem Link: https://cses.fi/problemset/task/2217/
Idea:
Complexity:
Resource:
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> idx;

// Count inversions for all pairs of elements whose values differ by 1
int getInvCount(const set<int>& st) {
    int inv_count = 0;
    auto it = st.begin();
    int prev = *it;
    ++it;
    while (it != st.end()) {
        if (*it - 1 == prev && idx[*it] < idx[prev]) {
            inv_count++;
        }
        prev = *it;
        ++it;
    }
    return inv_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        int ans = 0;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            if (!idx[v[i] - 1]) {
                ans++;
            }
            idx[v[i]] = i;
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            int a = v[l];
            int b = v[r];
            
            /*
            Create a temporary set and insert all elements that
            might change the answer after swapping
            */
            set<int> st;
            st.insert(a);
            st.insert(b);
            if (a - 1 >= 1) st.insert(a - 1);
            if (a + 1 <= n) st.insert(a + 1);
            if (b - 1 >= 1) st.insert(b - 1);
            if (b + 1 <= n) st.insert(b + 1);

            /*
            Before swapping, count all the inversions already 
            added to the answer using this set of elements
            */
            int inv_count = getInvCount(st);
            ans -= inv_count; // Remove all the inversion counts using this set of elements

            // Swap two elements and also their positions
            swap(v[l], v[r]);
            swap(idx[a], idx[b]);

            // Recalculate all the newly created inversions after swapping
            st.clear();
            st.insert(a);
            st.insert(b);
            if (a - 1 >= 1) st.insert(a - 1);
            if (a + 1 <= n) st.insert(a + 1);
            if (b - 1 >= 1) st.insert(b - 1);
            if (b + 1 <= n) st.insert(b + 1);

            inv_count = getInvCount(st);
            ans += inv_count; // Add the newly created inversion counts to the answer

            cout << ans << "\n";
        }
    }
    return 0;
}