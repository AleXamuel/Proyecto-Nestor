vector<vector<int> > A;
vector<int> B;

int gauss(vector<int> &x) {
    int n = sz(A); // ecuaciones
    int m = sz(A[0]) - 1; // variables
    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; col++) {
        int sel = -1;
        for (int i = row; i < n; i++) {
            if (A[i][col]) {
                sel = i;
                break;
            }
        }
        if (sel == -1)
            continue;
        swap(A[sel], A[row]);
        where[col] = row;
        for (int i = 0; i < n; i++) {
            if (i != row && A[i][col]) {
                for (int j = col; j <= m; j++)
                    A[i][j] ^= A[row][j];
            }
        }
        row++;
    }
    x.assign(m, 0);
    for (int i = 0; i < m; i++) {
        if (where[i] != -1)
            x[i] = A[where[i]][m];
    }

    // verificar consistencia
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = 0; j < m; j++)
            sum ^= (A[i][j] & x[j]);

        if (sum != A[i][m])
            return 0; // sin solución
    }

    for (int i = 0; i < m; i++) {
        if (where[i] == -1)
            return 2; // múltiples soluciones
    }

    return 1; // solución única
}
