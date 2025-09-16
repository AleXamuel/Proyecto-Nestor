//https://open.kattis.com/problems/fendofftitan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const ll INF = 1e18;
typedef tuple<ll, ll, ll, int> State;

void solve() {
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;

    vector<vector<tuple<ll, ll, int>>> adj(n);
    vector<tuple<ll, ll, ll>> best(n, {INF, INF, INF});

    For(i, 0, m) {
        ll a, b, w, e;
        cin >> a >> b >> w >> e;
        a--, b--;
        adj[a].emplace_back(b, w, e);
        adj[b].emplace_back(a, w, e);
    }

    priority_queue<State, vector<State>, greater<State>> pq;
    best[s] = {0, 0, 0};
    pq.emplace(0, 0, 0, s);

    while (!pq.empty()) {
        auto [ti, sh, dist, u] = pq.top();
        pq.pop();

        if (make_tuple(ti, sh, dist) > best[u]) continue;

        for (auto [v, w, e] : adj[u]) {
            ll nt = ti;
            ll ns = sh;
            ll nd = dist + w;

            if (e == 1) ns++;
            else if (e == 2) nt++;

            auto nState = make_tuple(nt, ns, nd);

            if (nState < best[v]) {
                best[v] = nState;
                pq.emplace(nt, ns, nd, v);
            }
        }
    }

    auto [tiF, shF, distF] = best[t];
    if (distF >= INF) {
        cout << "IMPOSSIBLE" << ln;
    } else {
        cout << distF << " " << shF << " " << tiF << ln;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
