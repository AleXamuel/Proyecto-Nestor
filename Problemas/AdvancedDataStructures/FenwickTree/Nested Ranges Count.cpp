//https://cses.fi/problemset/task/2169
#include <bits/stdc++.h>
using namespace std;
#define dll long double
#define ll long long
#define ull unsigned long long
#define Pair pair<ll,ll>
#define eb emplace_back
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define ln "\n"
#define uset unordered_set
#define umap unordered_map
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<pair<int, int> > moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int nmax = 4e5+5, mod = 1e9+7, inf = 1e9;
int n;
struct T {
    int l,r,idx;
    bool operator <(const T& o)const {
        if(r!=o.r)return r<o.r;
        return l>o.l;
    }
};
struct FT {
    vector<int> bit;  // binary indexed tree
    int n;

    FT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FT(vector<int> const &a) : FT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
int ans[2][nmax];
void solve() {
    cin >> n;
    vector<T>A(n);
    vector<int>B;
    For(i,0,n) {
        cin>>A[i].l>>A[i].r;
        B.pb(A[i].l);
        B.pb(A[i].r);
        A[i].idx=i;
    }
    sort(all(B));
    int cnt=0;
    map<int,int>mp;
    For(i,0,B.size())
        if(mp.find(B[i])==mp.end())
            mp[B[i]]=cnt++;
    For(i,0,n) {
        A[i].l=mp[A[i].l];
        A[i].r=mp[A[i].r];
    }
    sort(all(A));
    FT t1(cnt),t2(cnt);
    for(auto&[l,r,i]:A) {
        int val=t1.sum(l,r);
        ans[0][i]=val;
        t1.add(l,1);
    }
    vector<vector<int>>fsh(cnt,vector<int>());
    vector<int>str(cnt,0);
    For(i,0,n) {
        fsh[A[i].r].pb(i);
        str[A[i].l]++;
    }
    For(i,0,cnt) {
        t2.add(i,str[i]);
        for(int j:fsh[i]) {
            ans[1][A[j].idx]=t2.sum(A[j].l)-1;
            t2.add(A[j].l,-1);
        }
    }
    For(i,0,n)
        cout<<ans[0][i]<<" ";
    cout<<ln;
    For(i,0,n)
       cout<<ans[1][i]<<" ";


}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
