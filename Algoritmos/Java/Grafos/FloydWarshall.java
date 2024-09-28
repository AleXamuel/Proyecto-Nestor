static void floydWarshall(int[][] res) {
    int N=res.length;
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (res[i][k] < Integer.MAX_VALUE && res[k][j] < Integer.MAX_VALUE)
                    res[i][j] = Math.min(res[i][j], res[i][k] + res[k][j]);

}
