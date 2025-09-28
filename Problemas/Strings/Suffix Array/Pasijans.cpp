//https://open.kattis.com/problems/pasijans
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
#define Vi vector<int>
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
#define RAYA cerr<<"=================================="<<endl
vector<pair<int, int> > moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int MAX = 2e5 + 5, MOD = 1e9 + 7, inf = 1e6+5;
vector<int> sort_cyclic_shifts(vector<int> const &s) {
    int n = s.size();
    const int alphabet = 1e6+10;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i - 1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(vector<int> s) {
    s.pb(0);
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}
vector<int>B,roots,idx;
struct T {
    int val,i;
    bool operator < (const T& o) const {
        if(o.val!=val)return val<o.val;
        return idx[i]<idx[o.i];
    }
};
void solve() {
    int n;cin>>n;
    vector<vector<int>>A(n,vector<int>());
    set<int>st;
    map<int,int>mp,mp2;
    For(i,0,n) {
        int m;cin>>m;
        A[i].resize(m);
        For(j,0,m) {
            cin>>A[i][j];
            st.insert(A[i][j]);
        }
    }
    int c=1;
    for(const int i:st) {
        mp[i]=c;
        mp2[c]=i;
        c++;
    }

    For(i,0,n) {
        roots.pb(B.size());
        For(j,0,A[i].size()) {
            B.pb(mp[A[i][j]]);
        }
        B.pb(inf);
    }
    auto p=suffix_array_construction(B);
    idx.resize(B.size());
    For(i,0,B.size()) {
        idx[p[i]]=i;
    }
    set<T>Q;
    For(i,0,roots.size())
        Q.insert({B[roots[i]],roots[i]});
    vector<int>ans;
    while(!Q.empty()) {
        auto [val,u]=*Q.begin();
        Q.erase(Q.begin());
        if(val==inf)continue;
        ans.pb(mp2[val]);
        Q.insert({B[u+1],u+1});
    }
    for(int i:ans)
        cout<<i<<" ";

}
signed main() {
    //freopen("balls.in", "r",stdin);
    //freopen("balls.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
