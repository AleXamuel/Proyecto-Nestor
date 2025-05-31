int n, l;
vector<int>parent,depth;
vector<vector<int>>up;
void preprocess(int root) {
    l=ceil(log2(n));
    up.assign(n,vector<int>(l+1,root));
    for(int i=0;i<n;i++)
        up[i][0]=parent[i];

    for(int j=1;j<=l;j++)
        for(int i=0;i<n;i++)
            if(up[i][j-1]>=0)
                up[i][j]=up[up[i][j-1]][j-1];


}
int binaryLifting(int u, int x) {
    for(int i=0;i<=l;i++)
        if(x&(1<<i))
            u=up[u][i];
    return u;
}
int lca(int a, int b) {
    if(depth[a]<depth[b])
        swap(a,b);
    a=binaryLifting(a,depth[a]-depth[b]);
    if(a==b)return a;
    for(int i=l;i>=0;i--) {
        if(up[a][i]==up[b][i])
            continue;
        a=up[a][i];
        b=up[b][i];
    }
    return up[a][0];
}
int calc_depth(int u) {
    if(parent[u]==-1)return depth[u]=0;
    if(depth[u]>=0)return depth[u];
    return depth[u]=calc_depth(parent[u])+1;
}
