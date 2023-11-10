#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll ans = 1;
        map<int, int> check;
        int lo = 0;
        set<int> st;
        st.insert(a[0]);
        check[a[0]]++;
        for(int i = 1; i < n; i++) {
            st.insert(a[i]);
            check[a[i]]++;
            if((int)st.size() > k) {
                while(true) {
                    check[a[lo]]--;
                    if(!check[a[lo]]) {
                        st.erase(st.find(a[lo]));
                        lo++;
                        break;
                    }
                    lo++;
                }
            }
            ans+=(i-lo+1)*1LL;
        }
        cout << ans << "\n";
    }
    return 0;
}
