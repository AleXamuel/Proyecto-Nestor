//https://codeforces.com/problemset/problem/126/B
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
const int MAX = 3e5+5, MOD1 = 1e9+7,MOD2=1e9+9, inf = 1e6 + 5;
vector<int> kmp(const string& S) {
    int n=S.size();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int g = p[i - 1];
        while (g && S[i] != S[g])
            g = p[g - 1];
        p[i] = g + (S[i] == S[g]);
    }
    return p;
}
int n;
string s;
void f(vector<int>&p,int v,set<int>&st) {
    if(v==0) {
        cout<<"Just a legend"<<ln;
        return;
    }
    if(st.lower_bound(v)!=st.end()) {
        cout<<s.substr(0,v)<<ln;
        return;
    }
    f(p,p[v-1],st);
}
void solve() {
    cin>>s;
    n=s.size();
    auto p=kmp(s);
    if(p.back()==0) {
        cout<<"Just a legend"<<ln;
        return;
    }
    set<int>st;
    For(i,0,n-1)
        st.insert(p[i]);

    f(p,p.back(),st);
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
