## Maximum Subarray Sum

```C++
// Empty or Non-empty Subarray
ll maxSubArraySum(vector<ll> v, ll n) {
    ll mx = 0, sum = 0;
 
    for (int i = 0; i < n; i++) {
        sum = sum + v[i];
        if(sum > mx) mx = sum;
        if(sum < 0) sum = 0;
    }
    return mx;
}
```
```C++
// Non-empty Subarray
ll maxSubArraySum(vector<ll> v, ll n) {
    ll sum = v[0], mx = v[0];
 
    for (int i = 1; i < n; i++) {
        sum = max(sum+v[i], v[i]);
        mx = max(mx, sum);
    }
    return mx;
}
```