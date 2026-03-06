//https://codeforces.com/gym/101666/problem/E
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
const int MAX = 2e5 + 2, MOD = 998244353, MOD2 = 1202773163, INF = 2e9, base = 29;
int n, a, b;
struct T {
    int x,y;

};
istream& operator>>(istream& in, T& p) {
    in >> p.x >> p.y;
    return in;
}
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
double distance(T& a, T& b) {
    double ans=((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
    return ans;
}
bool f(vector<T>&B,vector<T>&R, double d) {
    int m=a+b;
    mt.assign(m,-1);
    adj.assign(m,vector<int>());
    For(i,0,a)
        For(j,0,b) {
            if(distance(B[i],R[j])<d*d)
                adj[i].pb(a+j);
        }
    For(i,0,m) {
        used.assign(m,false);
        try_kuhn(i);
    }
    vector<vector<int>>A(m,vector<int>());
    queue<int>Q;
    vector<bool>state(m,false);
    auto& aa=mt;
    uset<int>st;
    For(u,0,m)
        for(int v:adj[u]) {
            if(mt[v]==u)
                A[v].pb(u);
            else
                A[u].pb(v);
        }
    For(i,0,m)
        st.insert(mt[i]);
    For(i,0,a)
        if(st.find(i)==st.end()) {
            Q.push(i);
            state[i]=true;
        }
    while(!Q.empty()) {
        int u=Q.front();
        Q.pop();
        for(int v:A[u])
            if(!state[v]) {
                state[v]=true;
                Q.push(v);
            }
    }
    int c=0;
    For(i,0,a)
        c+=!state[i];
    For(i,a,m)
        c+=state[i];
    c=m-c;
    return c>=n;
}
void solve() {
    cin >> n >> a >> b;
    vector<T> B(a), R(b);
    For(i, 0, a)
        cin >> B[i];
    For(i,0,b)
        cin>>R[i];
    double l=0,r=1e9;
    while(r-l>1e-8) {
        double m=l+(r-l)/2;
        if(f(B,R,m))
            l=m;
        else
            r=m;
    }
    cout<<setprecision(8)<<fixed;
    cout<<l<<ln;
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
