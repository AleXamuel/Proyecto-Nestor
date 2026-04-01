//https://vjudge.net/problem/UVA-11506
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pq priority_queue<int, vector<int>, greater<int>>
#define VI vector<int>
#define VVI vector<VI>
#define RAD(deg) ((deg) * PI / 180.0)
#define ones(x) __builtin_popcount(x)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define Rfor(i, a, b) for(int i = (a); i >= (b); --i)
#define all(v) (v).begin(), (v).end()
#define ln '\n'

const int MAXN = 105;
int capacity[MAXN][MAXN];
vector<int> adj[MAXN];


int bfs(int s, int t, vector<int> &parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int> > q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next: adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t, int n) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void solve() {
    int m, w;
    while (cin >> m >> w && (m != 0 || w != 0)) {
        memset(capacity, 0, sizeof(capacity));
        For(i, 0, MAXN)
            adj[i].clear();

        //no se pueden destruir el nodo 1 ni el nodo n
        capacity[0][m] = INF;
        adj[0].push_back(m);
        adj[m].push_back(0);

        capacity[m - 1][2 * m - 1] = INF;
        adj[m - 1].push_back(2 * m - 1);
        adj[2 * m - 1].push_back(m - 1);

        For(i, 0, m - 2) {
            int x, c;
            cin >> x >> c;
            x--;

            capacity[x][x + m] = c;
            adj[x].push_back(x + m);
            adj[x + m].push_back(x);
        }

        For(i, 0, w) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;

            int a_out = a + m;
            int b_out = b + m;

            capacity[a_out][b] = c;
            capacity[b_out][a] = c;

            adj[a_out].push_back(b);
            adj[b].push_back(a_out);
            adj[b_out].push_back(a);
            adj[a].push_back(b_out);
        }
        int ans = maxflow(0, 2 * m - 1, 2 * m);
        cout << ans << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

}
