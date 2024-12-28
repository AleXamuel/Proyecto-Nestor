long bigMod(long a, long p, long m) {
    long res = 1%m,x=a%m;
    while (p) {
        if (p & 1) res=(res*x)%m;
        x = (x*x)%m;
        p >>= 1;
    }
    return res;
}
