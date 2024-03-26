/*
Problem Name: Salary Queries
Problem Link: https://cses.fi/problemset/task/1144/
Idea:
Complexity:
Resource:
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 10000000;
const int _size = 33554431;
map<int, int> freq;
int buckets[N];

struct Segtree {
    // 0 base indexing
    vector<int> tree;

    void build() {
        int extra = ((_size + 1) >> 1) - N; // Total extra bucket in leaf
        int _N = N;                     // Total Bucket
        for (int i = _size - 1; i >= 0; i--) {
            if (extra) { // Fill the extra bucket in the leaf node with 0
                tree[i] = 0;
                extra--;
            }
            else if (_N) {
                tree[i] = buckets[_N - 1]; // Fill all the N bucket in the leaf node with their count
                _N--;
            }
            else
                tree[i] = tree[(i << 1) + 1] + tree[(i << 1) + 2]; // Calculate sum for non-leaf node
        }
    }
    void update(int idx, int value) {
        idx = (_size >> 1) + idx;
        tree[idx] = value;
        while (((idx - 1) >> 1) >= 0) {
            idx = (idx - 1) >> 1;
            tree[idx] = tree[(idx << 1) + 1] + tree[(idx << 1) + 2];
            if (!idx)
                break;
        }
    }
    int sum(int i, int j, int node, int l, int r) {
        if (r < i || l > j)
            return 0;
        if (l >= i && r <= j)
            return tree[node];
        int mid = l + ((r - l) >> 1);
        return sum(i, j, (node << 1) + 1, l, mid) + sum(i, j, (node << 1) + 2, mid + 1, r);
    }
    void init() {
        tree.resize(_size);
        build();
    }
} st;
int bucketNumber(int x) {
    if (x % 100 == 0) {x--;}
    return x / 100;
}
int partialSum(int lo, int hi) {
    int res = 0;
    auto it = freq.lower_bound(lo);
    while (it != freq.end() && it->first <= hi) {res += it->second, it++;}
    return res;
}

/*
int calculateSize(int N) { // calculate 33554431 passing 10000000
    int size = 1;
    while (size < N)size = size << 1;
    return 2 * size - 1;
}
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int idx = bucketNumber(a[i]);
            buckets[idx]++;
            freq[a[i]]++;
        }
        st.init();
        while (q--) {
            char type;
            int i, j;
            cin >> type >> i >> j;
            if (type == '!') {
                i--;
                int past_sal = a[i];
                a[i] = j;
                int past = bucketNumber(past_sal); // past bucket
                int now = bucketNumber(j); // new bucket
                buckets[past]--;
                buckets[now]++;
                freq[past_sal]--, freq[j]++;
                st.update(past, buckets[past]);
                st.update(now, buckets[now]);
            }else {
                int left = bucketNumber(i);
                int right = bucketNumber(j);

                int ans = st.sum(left + 1, right - 1, 0, 0, ((_size + 1) >> 1) - 1); // 0 to Total (leaf_node_count - 1)
                ans += partialSum(i, min((left + 1) * 100, j));
                if (left != right)
                    ans += partialSum(right * 100 + 1, j);
                cout << ans << '\n';
            }
        }
    }
    return 0;
}