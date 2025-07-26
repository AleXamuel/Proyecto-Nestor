int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
    return x;
}
 
int mul(int x, int y) {
    return x * 1LL * y % MOD;
}
 
int binpow(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}
 
int divide(int x, int y) {
    return mul(x, binpow(y, MOD - 2));
}
