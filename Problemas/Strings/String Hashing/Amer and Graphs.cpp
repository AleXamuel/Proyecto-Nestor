//https://codeforces.com/gym/101808/problem/B
#include <bits/stdc++.h>
using namespace std;
#define dll double long
#define ll long long
#define Pair pair<int,int>
#define eb emplace_back
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<Pair > ch = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int nmax = 4002;
ll p[2] = {1200259153, 1202773163}, bs[2][nmax];
int base = 4091;
struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2*31;
    }
};
void solve() {
    int n;cin>>n;
    unordered_map<Pair,int,PairHash>mp;
    vector<int> a(n);
    For(i,0,n) {
        int u,v;cin>>u>>v;
        if(u>v)
            swap(u,v);
        if(mp.find({u,v})==mp.end())
            mp[{u,v}]=mp.size()+1;
        a[i]=mp[{u,v}];
    }
    ll ans=0;
    For(sz,1,n) {
        ll sh0=0,sh1=0;
        unordered_map<Pair,int,PairHash>act;
        For(i,0,sz) {
            sh0+=bs[0][a[i]];sh0%=p[0];
            sh1+=bs[1][a[i]];sh1%=p[1];
        }
        act[{sh0,sh1}]++;
        For(i,sz,n) {
            sh0+=bs[0][a[i]];sh0%=p[0];
            sh1+=bs[1][a[i]];sh1%=p[1];
            sh0-=bs[0][a[i-sz]];sh0+=p[0];sh0%=p[0];
            sh1-=bs[1][a[i-sz]];sh1+=p[1];sh1%=p[1];
            act[{sh0,sh1}]++;
        }
        for(auto&[p,c]:act)
            ans+=(c*(c-1))>>1;
    }
    cout<<ans<<ln;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin>>t;
    bs[0][0] = bs[1][0] = 1;
    For(i, 1, nmax)
        bs[0][i] = (bs[0][i - 1] * base) % p[0], bs[1][i] = (bs[1][i - 1] * base) % p[1];
    while (t--) {
        solve();
    }
    return 0;
}
