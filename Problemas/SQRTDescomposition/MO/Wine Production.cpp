//https://codeforces.com/gym/101879/problem/H
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
#define sz(A) (int)A.size()
#define uset unordered_set
#define umap unordered_map
#define For(i, a, b) for(int i = a; i < b; i++)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (const auto &i : V) cerr << i << " "; cerr << endl;
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
#define VVI vector<vector<ll>>
const int MAX = 3e4+2, MOD = 1e9 + 7, INF = 1e9, base = 27;
struct FenwickTree {
    vector<int> bit;
    int n;
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
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
FenwickTree st(MAX);
int F[MAX],ans=0, n;
vector<int>A;
void remove(int idx) {
    int x=A[idx];
    int cur=F[x];
    st.add(cur,-1);
    st.add(cur-1,1);
    F[x]--;
    int c=st.sum(ans,n+1);
    if (!(c>=ans))
        ans--;
}
void add(int idx) {
    int x=A[idx];
    int cur=F[x];
    st.add(cur,-1);
    st.add(cur+1,1);
    F[x]++;
    int c=st.sum(ans+1,n+1);
    if (c>=ans+1)
        ans++;
}
int get_answer() {
    return ans;
}

int block_size=180;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> MOs(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}
void solve() {
    int q;
    cin>>n>>q;
    st.add(0,n);
    vector<Query>Q(q);
    vector<int>B;
    A.resize(n);
    For(i,0,n)
        cin>>A[i];
    For(i,0,q) {
        int a,b;cin>>a>>b;
        a--,b--;
        Q[i]={a,b,i};
    }
    B=A;
    sort(all(B));
    B.erase(unique(all(B)),B.end());
    For(i,0,n)
        A[i]=lower_bound(all(B),A[i])-B.begin();
    for (int i:MOs(Q))
        cout<<i<<ln;

}
signed main() {
    //freopen("algoritm.in", "r",stdin);
    //freopen("algoritm.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
