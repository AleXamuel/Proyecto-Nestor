#define ll unsigned long long
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
