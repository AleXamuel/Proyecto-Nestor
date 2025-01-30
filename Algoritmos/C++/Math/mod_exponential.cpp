const int MOD = 1000000007;
long long modExp(long base, long exp, long mod) {
    long long res = 1,x=base%mod;
    while (exp>0) {
        if ((exp & 1)>0) res=(res*x)%mod;
        x = (x*x)%mod;
        exp >>= 1;
    }
    return res;
}
