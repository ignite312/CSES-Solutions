## Big Mod 
```C++
// O(log(power))
int bigMod(ll base, ll power, const int M) {
    if(power == 0)return 1;
    int p = bigMod(base, power/2, M) % M;
    if(power % 2 == 0)return p*1LL*p % M;
    return (p*1LL*p % M) * (base % M) % M;
}
```
```C++
// O(log(power))
int bigPow(ll base, ll power, const int mod) {
    int ans = 1 % mod;
    base %= mod;
    if (base < 0) base += mod;
    while (power) {
        if (power & 1) ans = (ll) ans * base % mod;
        base = (ll) base * base % mod;
        power >>= 1;
    }
    return ans;
}
```
## Divisors
```C++
// O(sqrt(N))
int divisor(int a) {
    int ans = 0;
    for (int i = 1; i*i <= a; ++i) {
        if(a % i == 0) {
            if(a / i == i)ans++;
            else {
                ans+=2;
            }
        }
    }
    return ans;
}
```
```C++
// O(NlogN)
for(int i = 1; i <= N; i++) {
    for(int j = i; j <= N; j+=i) {
        divisor[j]++;
    }
}
```

## Geometric and Arithmetic series sum
```C++
// S_n = a(1-r^n)/(1-r)
int geometricSeriesSum(int r, int n) {
    int nu = bigPow(r, n, M) - 1; // Numerator
    int de = r - 1; // Denominator
    de = bigPow(de, M-2, M);
    return nu*1LL*de % M;
}

// S_n = n/2*(2*a + (n-1)*d)
int arithmeticSeriesSum(int n) {
    return (n*1LL*(n+1) % M)*bigPow(2, M-2, M) % M;
}
```