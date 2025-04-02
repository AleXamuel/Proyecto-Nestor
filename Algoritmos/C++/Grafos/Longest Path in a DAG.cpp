vector<vector<int>> adj;
vector<int> in_deg;
int n;
int kahn() {
    queue<int>q;
    int res=-1;
    for(int u =0;u<n;u++)
        if(!in_deg[u])
            q.push(u);
    while(!q.empty()) {
        int level=q.size();
        for(int i=0;i<level;i++) {
            int u=q.front();
            q.pop();
            for(int v:adj[u]) {
                in_deg[v]--;
                if(!in_deg[v])
                    q.push(v);
            }
        }
        res++;
    }
    return res;
}
