#define ll unsigned long long
//for small numbers use de next code, for bigger ones where a module is necesary use the second one
ll ncr(int n, int k) {
    if (k > n || k < 0) return 0;
    if (k > n - k) k = n - k;
    ll result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}
//2
vector<ll> fact;
vector<ll> invFact;
ll modPow(ll base, ll exp, int mod) {
    ll res = 1, x = base % mod;
    while (exp > 0) {
        if (exp & 1)
            res = res * x % mod;
        x = (x * x) % mod;
        exp >>= 1;
    }
    return res;
}
void getFactorials(int n) {
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[n] = modPow(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 1; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}
ll ncr(int n, int r) {
    if (r > n || r < 0)
        return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
