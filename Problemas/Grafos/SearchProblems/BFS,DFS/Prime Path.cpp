//https://vjudge.net/problem/SPOJ-PPATH
#include <bits/stdc++.h>
using namespace std;
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ll long long
#define ull unsigned long long
#define ln "\n"

vector<bool> isPrime;

void sieve(int n) {
    isPrime.assign(n, true);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= n; i++)
        if (isPrime[i])
            for (ll j = i * i; j <= n; j += i)
                isPrime[j] = false;
}

void solve() {
    int a, b;
    cin >> a >> b;
    unordered_map<int, int> d;
    d[a] = 0;
    queue<int> Q;
    Q.push(a);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        string s = to_string(u);
        For(j, 0, 4) {
            int cur = s[j] - '0';
            For(i, 0, 10)
                if (i != cur && !(j == 0 && i == 0)) {
                    s[j] = i + '0';
                    int num = stoi(s);
                    if (isPrime[num] && d.find(num) == d.end()) {
                        d[num] = d[u] + 1;
                        Q.push(num);
                    }
                    s[j] = cur + '0';
                }
        }
    }
    if (d.find(b) == d.end())
        cout << "Impossible";
    else
        cout << d[b];
    cout << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(10000);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
