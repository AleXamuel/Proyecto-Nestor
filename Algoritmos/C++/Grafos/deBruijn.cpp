vector<int> deBruijn(int k, int n) {
    vector<int> result;
    vector<int> a(n * k, 0);

    function<void(int, int)> rec = [&](int t, int p) {
        if (t > n) {
            if (n % p == 0) {
                for (int i = 1; i <= p; i++) {
                    result.push_back(a[i]);
                }
            }
        } else {
            a[t] = a[t - p];
            rec(t + 1, p);
            for (a[t] = a[t - p] + 1; a[t] < k; a[t]++) {
                rec(t + 1, t);
            }
        }
    };

    rec(1, 1);
    return result;
}

//how to use it
VI cycle = deBruijn(k, n);
for (int x: cycle)
    cout << x;
For(i, 0, n - 1)
    cout << cycle[i];
