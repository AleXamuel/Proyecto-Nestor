//https://codeforces.com/gym/101482/attachments
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"


const int MAX = 5e5 + 1;
vector<int> adj[MAX];
char state[MAX];
int degIn[MAX];
ll bolas[MAX];


void solve() {
    ll N, n;
    cin >> N >> n;
    For(i, 0, n) {
        char dir;
        int a, b;
        cin >> dir >> a >> b;
        state[i + 1] = dir;
        adj[i + 1].push_back(a);
        adj[i + 1].push_back(b);
        degIn[a]++;
        degIn[b]++;
    }
    queue<int> Q;
    For(u, 1, n+1)
        if (degIn[u] == 0)
            Q.push(u);

    bolas[1] += N;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        ll m = bolas[u];
        if (u == 0)
            continue;
        int left = adj[u].front();
        int right = adj[u].back();
        ll ceil = (m + 1) >> 1;
        ll floor = m >> 1;
        degIn[left]--;
        if (degIn[left] == 0)
            Q.push(left);
        degIn[right]--;
        if (degIn[right] == 0)
            Q.push(right);
        if (state[u] == 'L') {
            bolas[left] += ceil;
            bolas[right] += floor;
        } else {
            bolas[right] += ceil;
            bolas[left] += floor;
        }
        if (m & 1)
            state[u] = state[u] == 'L' ? 'R' : 'L';
    }
    For(u, 1, n+1)
        cout << state[u];
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
}
