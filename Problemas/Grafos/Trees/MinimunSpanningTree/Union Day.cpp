//https://codeforces.com/gym/100238/attachments
using namespace std;
#include <bits/stdc++.h>
#define all(A) A.begin(), A.end()
#define For(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long

struct pt {
    int x, y;
};

const int MAXN = 5001;
int n;
double d[MAXN];
bool visited[MAXN];
pt h[MAXN];


double dist(pt a, pt b) {
    return sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
}

double prim() {
    d[0] = 0;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++)
            if (!visited[j] && (u == -1 || d[j] < d[u]))
                u = j;

        if (u == -1)
            break;
        visited[u] = true;
        ans += d[u];
        for (int v = 0; v < n; v++)
            if (!visited[v]) {
                double w = dist(h[u], h[v]);
                if (w < d[v])
                    d[v] = w;
            }
    }
    return ans;
}


void solve() {
    cin >> n;
    For(i, 0, n) {
        pt a;
        cin >> a.x >> a.y;
        h[i] = a;
        d[i] = DBL_MAX;
        visited[i] = false;
    }
    cout.precision(6);
    cout << fixed;
    cout << prim() << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("unionday.in", "r", stdin);
    freopen("unionday.out", "w", stdout);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
