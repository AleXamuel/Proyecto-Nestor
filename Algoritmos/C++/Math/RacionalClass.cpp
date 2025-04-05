struct Racional {
    int num, den;

    void simplificar() {
        long div = gcd(num, den);
        if (div != 1) {
            num /= div;
            den /= div;
        }
    }
    static int mcd(const int a, const int b) {
        if (a % b == 0)
            return b;
        return mcd(b, a % b);
    }
}

ostream &operator<<(ostream &os, const Racional &p) {
    return os << p.num << "/" << p.den;
}
