vector<vector<ll>> multiply(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

vector<vector<ll>> matrix_power(vector<vector<ll>> A, long long k) {
    int n = A.size();

    // matriz identidad
    vector<vector<ll>> result(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        result[i][i] = 1;

    while (k > 0) {
        if (k & 1)
            result = multiply(result, A);
        A = multiply(A, A);
        k >>= 1;
    }

    return result;
}
