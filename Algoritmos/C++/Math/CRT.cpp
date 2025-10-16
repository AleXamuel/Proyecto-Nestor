struct Congruence {
    long long a, m;
};

long long mod_inv(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

long long chinese_remainder_theorem(vector<Congruence> const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.m;
    }

    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.a;
        long long M_i = M / congruence.m;
        long long N_i = mod_inv(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}

//EJEMPLO DE USO
//Dados dos dias, uno en la tierra y otro en marte, busque cuando coinciden, es decir mod 356 y mod 687
//hacemos el sistema de ecuaciones de conggruencias, en este caso es 2, si no tocaria con un for,
//y en cada congruence ponemos el numero y el mod
int main() {
    int e, m, case_num = 1;
    const int n1 = 365, n2 = 687;
    while (cin >> e >> m) {
        // Queremos x ≡ -e mod 365, x ≡ -m mod 687
        vector<Congruence> congruences;
        congruences.push_back({(n1 - e) % n1, n1});
        congruences.push_back({(n2 - m) % n2, n2});
        long long x = chinese_remainder_theorem(congruences);
        cout << "Case " << case_num++ << ": " << x << endl;
    }
    return 0;
}
