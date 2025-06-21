//https://vjudge.net/problem/SPOJ-ADACLEAN
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
ll p[2] = {1200259153, 1202773163}, bs[2][1000009];
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
};

struct PairHash {
    template<typename T1, typename T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2 * 31;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    shash sh;
    unordered_set<pair<ll,ll>, PairHash> st;
    For(i, 0, k)
        sh.pb(s[i] - 'a' + 1);
    st.insert({sh.h[0], sh.h[1]});
    For(i, k, n) {
        sh.pb(s[i] - 'a' + 1);
        sh.pop_front(s[i - k] - 'a' + 1);
        st.insert({sh.h[0], sh.h[1]});
    }
    cout << st.size() << ln;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    bs[0][0] = bs[1][0] = 1;
    For(i, 1, 1000009)
        bs[0][i] = (bs[0][i - 1] * base) % p[0], bs[1][i] = (bs[1][i - 1] * base) % p[1];
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
