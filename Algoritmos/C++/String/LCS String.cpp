//return de LCS
string LCS(string s1, string s2) {
        int m = s1.length();
        int k = s2.length();
        vector<vector<int>> dp(m+1,vector<int>(k+1,0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= k; j++) {
                if (s1[i-1]==s2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int index = dp[m][k];
        char[] lcs = new char[index];
        string lcs(index,'#');
        int i = m, j = k;
        while (i > 0 && j > 0) {
            if (s1[i-1]==s2[j-1])  {
                lcs[--index] = s1[i-1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        return lcs;
    }
