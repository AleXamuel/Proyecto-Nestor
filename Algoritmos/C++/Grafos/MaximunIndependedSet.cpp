// this code use hopcroft-karp for a fast matching. That algorithm is also in this Git https://github.com/AleXamuel/Proyecto-Nestor/blob/main/Algoritmos/C%2B%2B/Grafos/Matching%20Hopcroft-Karp.cpp
vector<int> MIS(vector<vector<int> > &adj) {
    N = adj.size();
    vector<int> side(N, -1);
    bool is_bipartite = true;
    queue<int> q;
    G.assign(N+1,vector<int>());
    for (int st = 0; st < N; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u: adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }
    if (!is_bipartite) {
        return {0};
    }
    For(u, 0, N)
        for (auto v: adj[u]) {
            if (side[u] == 0) {
                G[u+1].pb(v+1);
            } else
                G[v+1].pb(u+1);
        }
    int mat = hopcroft_karp();
    vector<vector<int> > B(N, vector<int>());
    uset<int> st;
    For(u, 1, N+1) {
        st.insert(match[u]-1);
        if(side[u-1]==1)
            continue;
        for (int v: G[u]) {
            if (match[v] == u)
                B[v-1].pb(u-1);
            else
                B[u-1].pb(v-1);
        }
    }
    queue<int> Q;
    vector<bool> state(N, false);
    For(i, 0, N)
        if (st.find(i) == st.end() && side[i] == 0) {
            Q.push(i);
            state[i] = true;
        }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v: B[u])
            if (!state[v]) {
                state[v] = true;
                Q.push(v);
            }
    }
    st.clear();
    vector<int> ans;
    For(i, 0, N) {
        if (side[i] == 0 && !state[i])
            st.insert(i);
        else if (side[i] && state[i])
            st.insert(i);
    }
    For(i, 0, N)
        if (st.find(i) == st.end())
            ans.pb(i);
    return ans;
}
