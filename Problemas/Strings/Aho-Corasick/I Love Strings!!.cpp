//https://vjudge.net/problem/UVA-10679
#include <bits/stdc++.h>
using namespace std;
#define dll double long
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
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<Pair > changes = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
//const int nmax = 2e5 + 1, MOD = 998244353, INF = 1e9;
const int K = 26;
struct Aho{
    static constexpr int nmax = 1e3 + 1;
    ll n=0,m=0;
    ll to[nmax][52],go[nmax][52],mark[nmax],qnt[nmax],p[nmax],pc[nmax],link[nmax],exit[nmax];
    vector<ll>idx[nmax];
    Aho(){
        memset(go,-1,sizeof(go));
        memset(link,-1,sizeof(link));
        memset(exit,-1,sizeof(exit));
    }
    void insert(const string& s){
        ll u=0;
        for(char ch:s){
            ll c=I(ch);
            ll& v=to[u][c];
            if(!v)
                v=++n,p[v]=u,pc[v]=c;
            u=v,++qnt[u];
        }
        ++mark[u],++qnt[0],idx[u].eb(m++);
    }
    int I(char c){//   'a'=0     'A'=26
        return c<'a'?26+c-'A':c-'a';
    }
    vector<Pair>occur(const string& s){
        vector<int>occ(n+1);
        vector<Pair>res;
        ll u=0;
        for(char ch:s){
            u=go_to(u,I(ch));
            for(ll v=u;v!=0;v=get_exit(v))
                ++occ[v];
        }
        For(v,0,n+1)
            for(auto i:idx[v])
                if(occ[v])
                    res.pb({i,occ[v]});
        return res;
    }
    ll get_link(ll u){
        if(link[u]!=-1)return link[u];
        if(u==0||p[u]==0)return link[u]=0;
        return link[u]=go_to(get_link(p[u]),pc[u]);
    }
    ll go_to(ll u, ll c){
        if(go[u][c]!=-1)return go[u][c];
        if(to[u][c])return go[u][c]=to[u][c];
        return go[u][c]=u==0?0:go_to(get_link(u),c);
    }
    ll get_exit(ll u){
        ll v=get_link(u);
        if(exit[u]!=-1)return exit[u];
        return exit[u]=(v==0||mark[v])?v:get_link(v);
    }
    void clear(){
        n = m = 0;
        memset(to, 0, sizeof(to));
        memset(go, -1, sizeof(go));
        memset(mark, 0, sizeof(mark));
        memset(qnt, 0, sizeof(qnt));
        memset(p, 0, sizeof(p));
        memset(pc, 0, sizeof(pc));
        memset(link, -1, sizeof(link));
        memset(exit, -1, sizeof(exit));
        For(i, 0, nmax) idx[i].clear();
    }

};
Aho ac;
void solve(){
    string s;cin>>s;
    int q;cin>>q;
    ac.clear();
    For(i,0,q){
        string t;
        cin>>t;
        ac.insert(t);
    }
    auto occ=ac.occur(s);
    vector<bool>state(q,false);
    ll m=occ.size(),j=0;
    for(auto[a,b]:occ)
        state[a]=true;
    For(i,0,q){  
        cout<<(state[i]?"y":"n")<<ln;
    }
}
signed main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
