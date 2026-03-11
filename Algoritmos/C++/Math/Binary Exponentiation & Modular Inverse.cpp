ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll inv(ll a,ll mod) { //Fermat's little theorem
    return binpow(a, mod - 2, mod);
}

//Divide when the inverse does not exist.
//Compute (a/b)MOD mod, when mod is not a prime number(you can't apply Fermat's little theorem) or when gcd(b,mod)!=1.

ll divide(ll a,ll b, ll mod) {
    return a % (b * mod) / b;
}
