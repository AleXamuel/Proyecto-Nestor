//https://codeforces.com/contest/2086/problem/C
#include <bits/stdc++.h>
using namespace std;
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ll long long
#define ull unsigned long long
#define ln "\n"

const int MAX = 1e5;

int A[MAX];

int pi[MAX];
int Size[MAX];


int Find(int u) {
    if (pi[u] == u)return u;
    return pi[u] = Find(pi[u]);
}

void Union(int u, int v) {
    int x = Find(u);
    int y = Find(v);
    if (x == y)
        return;
    if (Size[x] < Size[y]) {
        pi[x] = y;
        Size[y] += Size[x];
    } else {
        pi[y] = x;
        Size[x] += Size[y];
    }
}


void solve() {
    int n;
    cin >> n;
    For(i, 0, n) {
        cin >> A[i];
        pi[i] = i;
        Size[i] = 1;
    }
    For(i, 0, n)
        Union(A[i] - 1, i);
    int ans = 0;
    unordered_set<int> visited;
    For(i, 0, n) {
        int q;
        cin >> q;
        q--;
        int cur = Find(A[q] - 1);
        if (visited.find(cur) == visited.end()) {
            visited.insert(cur);
            ans += Size[cur];
        }
        cout << ans << " ";
    }
    cout << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
