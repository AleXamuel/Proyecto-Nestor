vector<vector<ll>> multiply(vector<vector<ll>>& A, vector<vector<ll>>& B) {
    vector<vector<ll>> C(2, vector<ll>(2, 0));
    For(i, 0, 2)
        For(j, 0, 2)
            For(k, 0, 2)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

vector<vector<ll>> matPow(vector<vector<ll>> mat, ll n) {
    vector<vector<ll>> result = {{1, 0}, {0, 1}};

    while(n > 0) {
        if(n & 1)
            result = multiply(result, mat);
        mat = multiply(mat, mat);
        n >>= 1;
    }
    return result;
}

ll fib(ll n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    vector<vector<ll>> base = {{1, 1}, {1, 0}};
    vector<vector<ll>> ans = matPow(base, n);

    return ans[0][1];
}
