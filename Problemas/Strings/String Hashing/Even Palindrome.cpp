//https://vjudge.net/problem/SPOJ-PALDR
#include <bits/stdc++.h>
using namespace std;
#define dll double long
#define ll long long
#define Pair pair<int,int>
#define eb emplace_back
//#define pb push_back
#define all(x) x.begin(),x.end()
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<Pair > ch = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
ll p[2]={1200259153,1202773163},bs[2][1000009];
int base=127;
struct shash {
    ll h[2]{0,0};
    int sz=0;
    void pb(int c) {
        h[0]=(h[0]*base+c)%p[0];
        h[1]=(h[1]*base+c)%p[1];
        sz++;
    }
    void pf(int c) {
        h[0]=(h[0]+c*bs[0][sz])%p[0];
        h[1]=(h[1]+c*bs[1][sz])%p[1];
        sz++;
    }
    bool operator ==(const shash& o)const {
        return h[0]==o.h[0]&&h[1]==o.h[1];
    }
    void clear() {
        h[0]=0,h[1]=0;
        sz=0;
    }
};
void solve() {
    string s;
    getline(cin,s);
    s.erase(remove(all(s),'\r'),s.end());
    shash a,b;
    int n=s.size();
    For(i,0,n) {
        a.pb(s[i]-126);
        b.pf(s[i]-126);
        if(a==b&&a.sz%2==0)
            a.clear(),b.clear();
    }
    cout<<(a==b&&a.sz%2==0?"YES":"NO")<<ln;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    bs[0][0]=bs[1][0]=1;
    For(i,1,1000009)
        bs[0][i]=(bs[0][i-1]*base)%p[0],bs[1][i]=(bs[1][i-1]*base)%p[1];
    cin>>t;
    string ignore;
    getline(cin,ignore);
    while (t--)
        solve();
    return 0;
}

