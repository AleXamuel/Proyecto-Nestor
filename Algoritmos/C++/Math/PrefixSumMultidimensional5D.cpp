int n1, n2, n3, n4, n5;
cin >> n1 >> n2 >> n3 >> n4 >> n5;

vector<vector<vector<vector<vector<ll> > > > > A(
    n1 + 1, vector<vector<vector<vector<ll> > > >(
        n2 + 1, vector<vector<vector<ll> > >(
            n3 + 1, vector<vector<ll> >(
                n4 + 1, vector<ll>(n5 + 1, 0)))));

for (int i1 = 1; i1 <= n1; i1++)
    for (int i2 = 1; i2 <= n2; i2++)
        for (int i3 = 1; i3 <= n3; i3++)
            for (int i4 = 1; i4 <= n4; i4++)
                for (int i5 = 1; i5 <= n5; i5++)
                    cin >> A[i1][i2][i3][i4][i5];

vector<vector<vector<vector<vector<ll> > > > > pref = A;

for (int i1 = 1; i1 <= n1; i1++)
    for (int i2 = 1; i2 <= n2; i2++)
        for (int i3 = 1; i3 <= n3; i3++)
            for (int i4 = 1; i4 <= n4; i4++)
                for (int i5 = 1; i5 <= n5; i5++)
                    pref[i1][i2][i3][i4][i5] += pref[i1 - 1][i2][i3][i4][i5];

for (int i1 = 1; i1 <= n1; i1++)
    for (int i2 = 1; i2 <= n2; i2++)
        for (int i3 = 1; i3 <= n3; i3++)
            for (int i4 = 1; i4 <= n4; i4++)
                for (int i5 = 1; i5 <= n5; i5++)
                    pref[i1][i2][i3][i4][i5] += pref[i1][i2 - 1][i3][i4][i5];

for (int i1 = 1; i1 <= n1; i1++)
    for (int i2 = 1; i2 <= n2; i2++)
        for (int i3 = 1; i3 <= n3; i3++)
            for (int i4 = 1; i4 <= n4; i4++)
                for (int i5 = 1; i5 <= n5; i5++)
                    pref[i1][i2][i3][i4][i5] += pref[i1][i2][i3 - 1][i4][i5];

for (int i1 = 1; i1 <= n1; i1++)
    for (int i2 = 1; i2 <= n2; i2++)
        for (int i3 = 1; i3 <= n3; i3++)
            for (int i4 = 1; i4 <= n4; i4++)
                for (int i5 = 1; i5 <= n5; i5++)
                    pref[i1][i2][i3][i4][i5] += pref[i1][i2][i3][i4 - 1][i5];

for (int i1 = 1; i1 <= n1; i1++)
    for (int i2 = 1; i2 <= n2; i2++)
        for (int i3 = 1; i3 <= n3; i3++)
            for (int i4 = 1; i4 <= n4; i4++)
                for (int i5 = 1; i5 <= n5; i5++)
                    pref[i1][i2][i3][i4][i5] += pref[i1][i2][i3][i4][i5 - 1];

int q;
cin >> q;

while (q--) {
    int l1, l2, l3, l4, l5, r1, r2, r3, r4, r5;
    cin >> l1 >> l2 >> l3 >> l4 >> l5 >> r1 >> r2 >> r3 >> r4 >> r5;
    l1--, l2--, l3--, l4--, l5--;

    ll sum = 0;

    for (int mask = 0; mask < (1 << 5); mask++) {
        int cnt = 0;

        int i1 = (mask & (1 << 0)) ? l1 : r1;
        int i2 = (mask & (1 << 1)) ? l2 : r2;
        int i3 = (mask & (1 << 2)) ? l3 : r3;
        int i4 = (mask & (1 << 3)) ? l4 : r4;
        int i5 = (mask & (1 << 4)) ? l5 : r5;

        if (mask & (1 << 0))
            cnt++;
        if (mask & (1 << 1))
            cnt++;
        if (mask & (1 << 2))
            cnt++;
        if (mask & (1 << 3))
            cnt++;
        if (mask & (1 << 4))
            cnt++;

        if (cnt % 2 == 0)
            sum += pref[i1][i2][i3][i4][i5];
        else
            sum -= pref[i1][i2][i3][i4][i5];
    }
    cout << sum << ln;
}
