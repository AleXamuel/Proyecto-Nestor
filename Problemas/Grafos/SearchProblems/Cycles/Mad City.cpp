#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <unordered_set>
#include <vector>
#define pb push_back
using namespace std;
int n;
vector<vector<int> > adj;
vector<bool> state;
vector<int> pi;
int cycle_start, cycle_end;

vector<int> bfs(const int s, vector<int> d) {
    vector<bool> st(n, false);
    queue<int> q;
    d[s] = 0;
    q.push(s);
    st[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (!st[v]) {
                q.push(v);
                st[v] = true;
                d[v] = d[u] + 1;
            }
        }
    }
    return d;
}

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

unordered_set<int> find_cycle() {
    state.assign(n, false);
    pi.assign(n, -1);
    cycle_start = -1;
    for (int u = 0; u < n; u++) {
        if (!state[u] && dfs(u, pi[u]))
            break;
    }

    if (cycle_start == -1) {
        unordered_set<int> cycle;
        return cycle;
    }
    unordered_set<int> cycle;
    cycle.insert(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = pi[v])
        cycle.insert(v);
    return cycle;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ti;
    cin >> ti;
    while (ti--) {
        int a, b;
        adj.clear();
        state.clear();
        pi.clear();
        cin >> n >> a >> b;
        adj.resize(n);
        state.resize(n);
        pi.resize(n);
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        unordered_set<int> cycle = find_cycle();
        vector<int> dm(n, 214748367);
        vector<int> dv(n, 214748367);
        a--;
        b--;
        dm=bfs(a,dm);
        dv=bfs(b,dv);
        bool flag=true;
        for (int i: cycle) {
            if (dv[i] < dm[i]) {
                cout << "YES" << endl;
                flag=false;
                break;
            }
        }
        if(flag)
            cout << "NO" << endl;
    }
    return 0;
}
