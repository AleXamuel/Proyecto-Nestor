//use MOD
int powmod(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = z * 1ll * x % mod;
        x = x * 1ll * x % mod;
        y >>= 1;
    }
    return z;
}

int n;

namespace linear_seq {
    const int N = 10010;
    ll res[N], base[N], _c[N], _md[N];

    vector<int> Md;

    void mul(ll *a, ll *b, int k) {
        For(i, 0, k+k) _c[i] = 0;
        For(i, 0, k)
            if (a[i])
                For(j, 0, k) _c[i + j] = (_c[i + j] + a[i] * b[j]) % mod;
        for (int i = k + k - 1; i >= k; i--)
            if (_c[i])
                For(j, 0, SZ(Md))
                    _c[i - k + Md[j]] =
                            (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % mod;
        For(i, 0, k) a[i] = _c[i];
    }

    int solve(ll n,VI a, VI b) {
        ll ans = 0, pnt = 0;
        int k = SZ(a);
        assert(SZ(a)==SZ(b));

        For(i, 0, k) _md[k - i - 1] = -a[i];
        _md[k] = 1;
        Md.clear();

        For(i, 0, k) if (_md[i] != 0) Md.push_back(i);
        For(i, 0, k) res[i] = base[i] = 0;
        res[0] = 1;

        while ((1LL << pnt) <= n) pnt++;
        for (int p = pnt; p >= 0; p--) {
            mul(res, res, k);
            if ((n >> p) & 1) {
                for (int i = k - 1; i >= 0; i--) res[i + 1] = res[i];
                res[0] = 0;
                For(j, 0, SZ(Md))
                    res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % mod;
            }
        }

        For(i, 0, k)
            ans = (ans + res[i] * b[i]) % mod;
        if (ans < 0) ans += mod;
        return ans;
    }

    VI BM(VI s) {
        VI C(1, 1), B(1, 1);
        int L = 0, m = 1, b = 1;

        For(n, 0, SZ(s)) {
            ll d = 0;
            For(i, 0, L + 1)
                d = (d + (ll) C[i] * s[n - i]) % mod;

            if (d == 0) ++m;
            else if (2 * L <= n) {
                VI T = C;
                ll c = mod - d * powmod(b, mod - 2) % mod;
                while (SZ(C) < SZ(B) + m) C.pb(0);
                For(i, 0, SZ(B))
                    C[i + m] = (C[i + m] + c * B[i]) % mod;
                L = n + 1 - L;
                B = T;
                b = d;
                m = 1;
            } else {
                ll c = mod - d * powmod(b, mod - 2) % mod;
                while (SZ(C) < SZ(B) + m) C.pb(0);
                For(i, 0, SZ(B))
                    C[i + m] = (C[i + m] + c * B[i]) % mod;
                ++m;
            }
        }

        return C;
    }

    int gao(VI a, ll n) {
        VI c = BM(a);
        c.erase(c.begin());
        For(i, 0, SZ(c))
            c[i] = (mod - c[i]) % mod;
        return solve(n, c, VI(a.begin(), a.begin() + c.size()));
    }
}
