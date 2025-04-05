vector<int> get_divisors(const int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.emplace_back(i);
            if (i != n / i)
                divisors.emplace_back(n / i);
        }
    }
    return divisors;
}
