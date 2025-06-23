//https://codeforces.com/contest/1200/problem/E
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
const int nmax = 1e6 + 5;
ll p[2] = {1200259153, 1202773163}, bs[2][nmax];
int base = 80;
struct shash {
    ll h[2]{0, 0};
    int sz = 0;

    void push_back(int c) {
        h[0] = (h[0] * base + c) % p[0];
        h[1] = (h[1] * base + c) % p[1];
        sz++;
    }

    void push_front(int c) {
        h[0] = (h[0] + c * bs[0][sz]) % p[0];
        h[1] = (h[1] + c * bs[1][sz]) % p[1];
        sz++;
    }

    void pop_front(int c) {
        h[0] = (((h[0] - c * bs[0][sz - 1]) % p[0]) + p[0]) % p[0];
        h[1] = (((h[1] - c * bs[1][sz - 1]) % p[1]) + p[1]) % p[1];
        sz--;
    }

    bool operator ==(const shash &o) const {
        return h[0] == o.h[0] && h[1] == o.h[1];
    }

    void clear() {
        h[0] = 0, h[1] = 0;
        sz = 0;
    }

    Pair get() {
        return {h[0], h[1]};
    }
};
int calc(string& s,string& t) {
    shash a,b;
    int n=s.size(),m=t.size();
    int mx=0;
    For(i,0,min(n,m)) {
        a.pf(s[n-1-i]);
        b.pb(t[i]);
        if(a==b)
            mx=i+1;
    }
    return mx;
}
void solve() {
    int n;cin>>n;
    vector<string>a(n);
    string word;word.reserve(1e6+2);
    For(i,0,n)
        cin>>a[i];
    word+=a[0];
    For(i,1,n) {
        int c=calc(word,a[i]);
        if(c>=a[i].size())continue;
        word+=a[i].substr(0+c,a[i].size()-c);
    }
    cout<<word<<ln;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    bs[0][0] = bs[1][0] = 1;
    For(i, 1, nmax)
        bs[0][i] = (bs[0][i - 1] * base) % p[0], bs[1][i] = (bs[1][i - 1] * base) % p[1];
    while (t--) {
        solve();
    }
    return 0;
}
