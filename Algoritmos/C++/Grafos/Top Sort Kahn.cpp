vector<vector<int>> adj;
vector<int> in_deg;
int n;
vector<int> kahn() {
    queue<int>q;
    for(int u =0;u<n;u++)
        if(!in_deg[u])
            q.push(u);
    int index=0;
    vector<int> topSort(n);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        topSort[index++]=u;
        for(int v:adj[u]) {
            in_deg[v]--;
            if(!in_deg[v])
                q.push(v);
        }
    }
    if(index!=n)
        return {};
    return topSort;

}
