//https://cses.fi/problemset/task/1144
#include <bits/stdc++.h>
using namespace std;
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
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<Pair > ch = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const int nmax = 2e5+1, MOD = 1e9 + 7, inf = 1e9;
int cnt=0,root;
struct node {
    int sum,ls,rs;
}t[nmax*30];
void add(int &p,int x, int y, int l=1, int r=inf) {
    if(!p)
        p=++cnt;
    if(l==r) {
        t[p].sum+=y;
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid)
        add(t[p].ls,x,y,l,mid);
    else
        add(t[p].rs,x,y,mid+1,r);
    t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
}
int query(int p, int l, int r, int tl=1, int tr=inf) {
    if (!p) return 0;
    if (l <= tl && tr <= r)
        return t[p].sum;
    int sum = 0;
    int mid = (tl + tr) / 2;
    if (l <= mid)
        sum += query(t[p].ls, l, r, tl, mid);
    if (r > mid)
        sum += query(t[p].rs, l, r, mid+1, tr);
    return sum;
}

void solve() {
    int n,q;cin>>n>>q;
    vector<int>A(n+1);
    For(i,1,n+1) {
        cin>>A[i];
        add(root,A[i],1);
    }
    while(q--) {
        char c;
        int l,r;cin>>c>>l>>r;
        if(c=='!') {
            add(root,A[l],-1);
            add(root,r,1);
            A[l]=r;
        }
        else {
            cout<<query(root,l,r)<<ln;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
