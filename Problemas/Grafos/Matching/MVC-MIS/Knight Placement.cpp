//https://atcoder.jp/contests/abc445/tasks/abc445_g
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define dll long double
#define ll long long
#define ull unsigned long long
#define Pair pair<int,int>
#define eb emplace_back
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define ln "\n"
#define uset unordered_set
#define umap unordered_map
#define For(i, a, b) for(int i = a; i < b; i++)
#define Vvi vector<vector<int>>
#define sz(A) (int)A.size()
#define Vi vector<ll>
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
#define RAYA cerr<<"=================================="<<endl
const int MAX = 2e5 + 2, MOD = 998244353, MOD2 = 1202773163, INF = 2e9, base = 29;
int n, a, b;

int I(int i, int j) {
    return i * n + j;
}
bool check(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}
vector<vector<int> > adj,G;
int N, match[MAX], dist[MAX];
bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=N; i++) {
        if(match[i]==0) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[0] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=0) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[0]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=0) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=N; i++)
            if(match[i]==0 && dfs(i))
                matching++;
    return matching;
}

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

void solve() {
    cin >> n >> a >> b;
    vector<string> A(n);
    vector<pair<int, int> > moves = {{a, b}, {b, a}, {b, -a}, {a, -b},{-a, -b}, {-b, -a}, {-b, a}, {-a, b}};
    For(i, 0, n)
        cin >> A[i];

    umap<int, int> mp1, mp2;
    int node = 0;
    For(i, 0, n) {
        For(j, 0, n) {
            if (A[i][j] != '#') {
                mp1[I(i, j)] = node;
                mp2[node++] = I(i, j);
            }
        }
    }
    int N = node;
    adj.assign(N, vector<int>());
    For(i, 0, n) {
        For(j, 0, n) {
            if (A[i][j] == '#')continue;
            for (auto [u,v]: moves) {
                int x = u + i, y = v + j;
                if (check(x, y) && A[x][y] != '#')
                    adj[mp1[I(i, j)]].pb(mp1[I(x, y)]);
            }
        }
    }
    auto ans = MIS(adj);
    for (int &x: ans) {
        x = mp2[x];
        int j = x % n, i = x / n;
        A[i][j] = 'o';
    }
    For(i, 0, n) {
        For(j, 0, n) {
            cout << A[i][j];
        }
        cout << ln;
    }
}

signed main() {
    //freopen("feast.in", "r",stdin);
    //freopen("feast.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
