ll modExp(ll base, ll exp, ll mod) {
    ll res = 1,x=base%mod;
    while (exp>0) {
        if ((exp & 1)>0) res=res*x%mod;
        x = x*x%mod;
        exp >>= 1;
    }
    return res;
}
