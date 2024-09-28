int n;
vector<vector<int> > adj;
vector<bool> state;
vector<int> pi;
int cycle_start, cycle_end;

bool dfs(int u, int par) {
    state[u] = true;
    for (int v: adj[u]) {
        if (v == par) continue;
        if (state[v]) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
        pi[v] = u;
        if (dfs(v, pi[v]))
            return true;
    }
    return false;
}

vector<int> find_cycle() {
    state.assign(n, false);
    pi.assign(n, -1);
    cycle_start = -1;
    for (int u = 0; u < n; u++) {
        if (!state[u] && dfs(u, pi[u]))
            break;
    }

    if (cycle_start == -1) {
        vector<int> cycle;
        return cycle;
    }
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = pi[v])
        cycle.push_back(v);
    cycle.push_back(cycle_start);
    return cycle;
}
