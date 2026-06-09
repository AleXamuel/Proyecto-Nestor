struct ST {
    int n, K;
    vector<vector<int>> st;
    vector<int> lg;
 
    ST(const vector<int>& a) {
        n = a.size();
        lg.resize(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;
 
        K = lg[n] + 1;
        st.assign(K, vector<int>(n));
        for (int i = 0; i < n; i++)
            st[0][i] = a[i];
        for (int k = 1; k < K; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                    st[k][i] = max(
                    st[k - 1][i],
                    st[k - 1][i + (1 << (k - 1))]
                );
            }
        }
    }
    int query(int l, int r) {
        if(l>r)
            return 0;
        int k = lg[r - l + 1];
        return max(
            st[k][l],
            st[k][r - (1 << k) + 1]
        );
    }
};
