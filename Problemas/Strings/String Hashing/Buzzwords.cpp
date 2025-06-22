//https://vjudge.net/problem/UVA-11855
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
ll p[2] = {1200259153, 1202773163}, bs[2][1009];
int base = 27;

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
        return {h[0],h[1]};
    }
};

struct PairHash {
    template<typename T1, typename T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2 * 31;
    }
};
string replace(string &s, char a) {
    string ans;
    For(i,0,s.size())
        if(a!=s[i])
            ans.pb(s[i]);
    return ans;
}
void solve() {
    string s;
    while(getline(cin,s)&&!s.empty()) {
        s=replace(s,' ');
        int n=s.size();
        For(sz,1,n) {
            shash sh;
            unordered_map<Pair,int,PairHash>mp;
            For(i,0,sz)
                sh.pb(s[i]-'A'+1);
            mp[sh.get()]++;
            For(i,sz,n) {
                sh.pb(s[i]-'A'+1);
                sh.pop_front(s[i-sz]-'A'+1);
                mp[sh.get()]++;
            }
            int mx=1;
            for(auto[h,c]:mp)
                mx=max(mx,c);
            if(mx>1)
                cout<<mx<<ln;
            else
                break;
        }
        cout<<ln;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    bs[0][0] = bs[1][0] = 1;
    For(i, 1, 1009)
        bs[0][i] = (bs[0][i - 1] * base) % p[0], bs[1][i] = (bs[1][i - 1] * base) % p[1];
    while (t--) {
        solve();
    }
    return 0;
}
