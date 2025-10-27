//https://www.spoj.com/problems/FREQ2
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
#define Vi vector<ll>
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
#define RAYA cerr<<"=================================="<<endl
//vector<pair<int, int> > D = {{0, 0}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1}};
//vector<pair<int, int> > K = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; //R D U I
const int MAX = 1e5 + 2, MOD1 = 1200259153, MOD2 = 1202773163, INF = 2e9, base = 29;
int A[MAX],B[MAX],VEC[MAX],ans;
void remove(int idx){
    int x=VEC[idx];
    int& f=A[x];
    B[f]--;
    if(ans==f&&B[f]==0)
        ans--;
    f--;
    B[f]++;
}
void add(int idx){
    int x=VEC[idx];
    int& f=A[x];
    if(B[f]>0)
        B[f]--;
    f++;
    ans=max(ans,f);
    B[f]++;
}
int get_answer(){
    return ans;
}

const int block_size=320;

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
    ans=0;
    int cur_l = 0;
    int cur_r = -1;
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
    int n,q;cin>>n>>q;
    For(i,0,n)
        cin>>VEC[i];
    vector<Query>Q(q);
    For(i,0,q) {
        int l,r;cin>>l>>r;
        Q[i]={l,r,i};
    }
    for(int i:MOs(Q))
        cout<<i<<ln;

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
