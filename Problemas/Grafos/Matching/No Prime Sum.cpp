//Minimun vertex cover problem
//https://vjudge.net/problem/CSAcademy-no-prime-sum
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
vector<pair<int, int> > moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int MAX = 2e5 + 2, MOD = 998244353, MOD2 = 1202773163, INF = 2e18, base = 29;
vector<bool> primos;
vector<vector<int> > adj;
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to: adj[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (ll) i * i <= n)
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    }
    primos=is_prime;
}

void solve() {
    sieve(MAX);
    int n;
    cin >> n;
    vector<int> A(n);
    auto& p=adj;
    For(i, 0, n)
        cin >> A[i];
    mt.assign(n, -1);
    adj.assign(n, vector<int>());
    For(i, 0, n)
        For(j, 0, n) {
            if (i == j)
                continue;
            if(primos[A[i]+A[j]]&&(A[j]&1)) {
                adj[i].pb(j);
            }
        }
    For(i,0,n)
        if(A[i]%2==0) {
            used.assign(n,false);
            try_kuhn(i);
        }
    //For(i,0,n)
    //    cout<<mt[i]<<" ";
    vector<vector<int>>B(n,vector<int>());
    uset<int>st,M;
    For(u,0,n) {
        st.insert(mt[u]);
        for(int v:adj[u]) {
            if(mt[v]==u)
                B[v].pb(u);
            else
                B[u].pb(v);
        }
    }
    queue<int>Q;
    vector<bool>state(n,false);
    For(i,0,n)
        if(A[i]%2==0&&st.find(i)==st.end()) {
            Q.push(i);
            state[i]=true;
        }
    while(!Q.empty()) {
        int u=Q.front();
        Q.pop();
        for(int v:B[u])
            if(!state[v]) {
                state[v]=true;
                Q.push(v);
            }
    }
    For(i,0,n) {
        if(A[i]&1) {
            if(state[i])
                M.insert(A[i]);
        }
        else if(!state[i])
            M.insert(A[i]);
    }

    cout<<M.size()<<ln;
    for(int i:M)
        cout<<i<<" ";
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
