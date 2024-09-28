public static int nlcs(String pat, String alph) {
    int m = pat.length();
    int n = alph.length();
    int[][] lcs = new int[m+1][n+1];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (pat.charAt(i-1) == alph.charAt(j-1))
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else
                lcs[i][j] = Math.max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    return lcs[m][n];
}
