const int MOD = 1e9 + 7;
const int MAXN = 200005;
ll fact[MAXN], inv_fact[MAXN];

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }

    inv_fact[MAXN-1] = binpow(fact[MAXN-1], MOD-2);
    for (int i = MAXN-2; i >= 0; i--) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    }
}

ll comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}
