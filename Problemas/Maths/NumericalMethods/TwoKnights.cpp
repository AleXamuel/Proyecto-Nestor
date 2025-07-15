//https://cses.fi/problemset/task/1072/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define For(i, k, n) for (int i = k; i < n; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) v.begin(), v.end()
#define ln "\n"


vector<double> ans;

ll binpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1)
            res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

vector<double> interpolar(vector<double> x, vector<double> y, int n) {
    vector<double> res(n, 0.0);
    vector<double> temp(n, 0.0);
    For(k, 0, n-1)
        For(i, k+1, n)
            y[i] = (y[i] - y[k]) / (x[i] - x[k]);
    double last = 0;
    temp[0] = 1;
    For(k, 0, n)
        For(i, 0, n) {
            res[i] += y[k] * temp[i];
            swap(last, temp[i]);
            temp[i] -= last * x[k];
        }
    return res;
}

double eval(vector<double> pol,ll x) {
    int n = (int) pol.size();
    double ans = 0;
    For(i, 0, n)
        ans += pol[i] * pow(x, i);
    return ans;
}


void solve() {
    int n;
    cin >> n;
    cout.precision(0);
    cout << fixed;
    For(i, 1, n+1)
        cout << eval(ans, i) << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<double> y = {0, 6, 28, 96, 252, 550, 1056, 1848};
    vector<double> x = {1, 2, 3, 4, 5, 6, 7, 8};
    ans = interpolar(x, y, 8);
    int t = 1;
    while (t--)
        solve();
}

