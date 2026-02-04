vector<vector<ll> > A(n + 1, vector<ll>(m + 1, 0));

For(i, 1, n + 1)
    For(j, 1, m + 1)
        cin >> A[i][j];

vector<vector<ll> > pref(n + 1, vector<ll>(m + 1, 0));
For(i, 1, n + 1)
    For(j, 1, m + 1)
        pref[i][j] = A[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];

int q;
cin >> q;

while (q--) {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;

    ll sum = pref[rx][ry]
           - pref[lx - 1][ry]
           - pref[rx][ly - 1]
           + pref[lx - 1][ly - 1];
    cout << sum << ln;
}
