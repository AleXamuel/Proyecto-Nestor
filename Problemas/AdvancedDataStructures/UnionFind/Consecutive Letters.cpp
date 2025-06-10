//https://www.spoj.com/problems/CONSEC/  Also can be solved greedy
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
const int MOD = 998244353;
const ll inf = -4e18;
//solution
vector<int> pi, Size;

int Find(int u) {
    if (pi[u] == u)return u;
    return pi[u] = Find(pi[u]);
}

void Union(int u, int v) {
    int x = Find(u);
    int y = Find(v);
    if (x == y)
        return;
    if (Size[x] < Size[y]) {
        pi[x] = y;
        Size[y] += Size[x];
    } else {
        pi[y] = x;
        Size[x] += Size[y];
    }
}
void solve() {
    string s;cin>>s;
    int n=s.size();
    pi.resize(n);
    Size.resize(n);
    For(i, 0, n) {
        pi[i] = i;
        Size[i] = 1;
    }
    stack<Pair>query;
    stack<int>ans;
    stack<char>let;
    int q;cin>>q;
    For(i,0,q) {
        int k,idx;cin>>k>>idx;
        query.push({k,idx});
        if(k==2) {
            let.push(s[idx]);
            s[idx]='#';
        }
    }
    For(i,1,n)
        if(s[i]!='#'&&s[i]==s[i-1])
            Union(i,i-1);
    while(!query.empty()) {
        auto [k,j]=query.top();
        query.pop();
        if(k&1)
            ans.push(Size[Find(j)]);
        else {
            s[j]=let.top();
            let.pop();
            if(j-1>=0&&s[j]==s[j-1])
                Union(j,j-1);
            if(j+1<n&&s[j]==s[j+1])
                Union(j,j+1);
        }
    }
    while(!ans.empty()) {
        cout<<ans.top()<<ln;
        ans.pop();
    }




}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ti = 1;
    cin>>ti;
    int vv=1;
    while (ti--) {
        cout<<"Case "<<vv++<<":"<<ln;
        solve();
    }
    return 0;
}
