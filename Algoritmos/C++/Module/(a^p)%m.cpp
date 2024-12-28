long long bigMod(long a, long p, long m) {
    long long res = 1%m,x=a%m;
    while (p>0) {
        if ((p & 1)>0) res=(res*x)%m;
        x = (x*x)%m;
        p >>= 1;
    }
    return res;
}
