//return de size of the LCS
int lcs(string pat, string alph) {
    int m = pat.length();
    int n = alph.length();
    vector<vector<int>> lcs(m+1,vector<int>(n+1,0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (pat[i - 1] == alph[j - 1])
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    return lcs[m][n];
}
