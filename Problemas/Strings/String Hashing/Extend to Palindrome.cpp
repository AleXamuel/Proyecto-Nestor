//https://vjudge.net/problem/SPOJ-EPALIN
#include <bits/stdc++.h>
using namespace std;
#define dll double long
#define ll long long
#define Pair pair<int,int>
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(),x.end()
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<Pair > ch = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
ll p[2]={1200259153,1202773163},bs[2][100001];
int base=58;
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
};
void solve() {
    string s;
    while(cin>>s&&s!="--") {
        int mx=0;
        shash a,b;
        int n=s.size();
        Rfor(i,n-1,0) {
            a.pb(s[i]-'A'+1);
            b.pf(s[i]-'A'+1);
            if(a==b)
                mx=i;
        }
        string t=s.substr(0,mx);
        reverse(all(t));
        cout<<s<<t<<ln;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    bs[0][0]=bs[1][0]=1;
    For(i,1,100001)
        bs[0][i]=(bs[0][i-1]*base)%p[0],bs[1][i]=(bs[1][i-1]*base)%p[1];
    while (t--)
        solve();
    return 0;
}

