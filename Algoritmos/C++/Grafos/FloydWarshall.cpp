ll INF=18446744073709551615;
vector<vector<ll>> floydWarshall(vector<vector<ll>> madj) {
    int n = madj.size();
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (madj[i][k] < INF && madj[k][j] < INF)
                    madj[i][j] = min(madj[i][j], madj[i][k] + madj[k][j]);
    return madj;
}
