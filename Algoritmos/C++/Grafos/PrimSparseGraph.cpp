//O(NlogM)
struct Edge {
    int w, to;

    bool operator<(const Edge& other) const {
        if(w!=other.w) return w<other.w;
        return to<other.to;
    }
};
int n;
vector<vector<Edge>> adj;
long long prim(int s) {
    set<Edge> q;
    vector<long long> d(n, INF);
    vector<bool> state(n, false);
    d[s]=0;
    q.insert({0,s});
    while(!q.empty()) {
        Edge cur = *q.begin();
        q.erase(q.begin());
        int u=cur.to;
        if(!state[u]) {
            state[u]=true;
            for(Edge e : adj[u]) {
                int v=e.to;
                int w=e.w;
                if(!state[v]) {
                    if(w<d[v]) {
                        d[v]=w;
                        q.insert({w, v});
                    }
                }
            }

        }
    }
    long long c=0;
    for(long long i:d) {
        if(i==INF) return -1;
        c+=i;
    }
    return c;
}
