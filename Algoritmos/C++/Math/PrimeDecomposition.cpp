void decompose(int n) {
    for (int i = 2; (ll) i * i <= n; i++)
        while (n % i == 0) {
            n /= i;
            cout << i << " ";
        }
    if (n > 1)
        cout << n << "";
    cout << ln;
}
