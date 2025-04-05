//https://cses.fi/problemset/task/1079
#include <bits/stdc++.h>
using namespace std;
#define dll double long
#define ll long long
#define Pair pair<int,int>
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
const int INF = 1e9;
const int MAX = 1005;
const int MOD=1e9+7;
vector<ll> fact;
vector<ll> invFact;
ll modPow(ll base, ll exp, int mod) {
    ll res = 1, x = base % mod;
    while (exp > 0) {
        if (exp & 1)
            res = res * x % mod;
        x = (x * x) % mod;
        exp >>= 1;
    }
    return res;
}
void getFactorials(int n) {
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[n] = modPow(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 1; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}
ll ncr(int n, int r) {
    if (r > n || r < 0)
        return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    getFactorials(1000005);
    int ti;cin>>ti;
    while(ti--) {
        int a,b;cin>>a>>b;
        cout<<ncr(a,b)<<ln;
    }
    return 0;
}

//freopen("socdist.in", "r",stdin);
//fr    eopen("socdist.out", "w", stdout)
