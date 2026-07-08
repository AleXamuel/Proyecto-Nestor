int n, l;
vector<int> parent, depth,d;
vector<vector<int> > up,table;
vector<vector<Pair> > adj;

void preprocess(int root) {
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1, root));
    table.assign(n, vector<int>(l + 1, -1e9));
    for (int i = 0; i < n; i++) {
        up[i][0] = parent[i];
        table[i][0]=d[i];
    }

    for (int j = 1; j <= l; j++)
        for (int i = 0; i < n; i++)
            if (up[i][j - 1] >= 0) {
                up[i][j] = up[up[i][j - 1]][j - 1];
                table[i][j]=max(table[i][j-1],table[up[i][j-1]][j-1]);
            }
}

int binaryLifting(int u, int x) {
    for (int i = 0; i <= l; i++)
        if (x & (1 << i))
            u = up[u][i];
    return u;
}

int lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);
    a = binaryLifting(a, depth[a] - depth[b]);
    if (a == b)return a;
    for (int i = l; i >= 0; i--) {
        if (up[a][i] == up[b][i])
            continue;
        a = up[a][i];
        b = up[b][i];
    }
    return up[a][0];
}
int help(int u, int x) {
    int ans=-1e9;
    for (int i = 0; i <= l; i++)
        if (x & (1 << i)) {
            ans=max(ans,table[u][i]);
            u = up[u][i];
        }
    return ans;
}

int getAns(int a, int b) {
    int l=lca(a,b);
    return max(help(a,depth[a]-depth[l]),help(b,depth[b]-depth[l]));
}
