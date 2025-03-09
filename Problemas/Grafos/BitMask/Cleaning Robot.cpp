//https://vjudge.net/problem/SPOJ-CLEANRBT
using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define Pair pair<int,int>
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define ln "\n"
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
const ll inf = 1e18;
const ll mod = 998244353;
const int N = 100001;
struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2*31;
    }
};
int r, c;
vector<string> grid;
vector<vector<int> > cambio = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
vector<vector<vector<int>>> d;
unordered_map<Pair,int,PairHash> mp;
struct Node {
    int x,y,msk;
};
void bfs(Pair s) {
    d[s.first][s.second][0]=0;
    queue<Node> q;
    q.push({s.first,s.second,0});
    while(!q.empty()) {
        auto u=q.front();
        q.pop();
        int i=u.x,j=u.y,msk=u.msk;
        for(auto ch:cambio) {
            int x=i+ch[0],y=j+ch[1];
            int newMask=msk;
            if(x<0||x>=r||y<0||y>=c||grid[x][y]=='x')
                continue;
            if(mp.count({x,y}))
                newMask|=1<<mp[{x,y}];
            if(d[i][j][msk]+1<d[x][y][newMask]) {
                d[x][y][newMask]=d[i][j][msk]+1;
                q.push({x,y,newMask});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("socdist.in", "r",stdin);
    //freopen("socdist.out", "w", stdout)
    while (true) {
        cin >> c >> r;
        if (r == 0 && c == 0)break;
        grid.resize(r);
        mp.clear();
        Pair s;
        int k = 0;
        For(i, 0, r) {
            cin >> grid[i];
            For(j,0,c) {
                if (grid[i][j] == 'o')
                    s = {i, j};
                else if (grid[i][j] == '*')
                    mp[{i,j}]=k++;
            }
        }
        d.assign(r, vector<vector<int>>(c,vector<int>(1<<k,1e9)));
        bfs(s);
        int ans=1e9;
        For(i, 0, r) {
            For(j, 0, c) {
                if(grid[i][j]=='*')
                    ans=min(ans, d[i][j][(1<<k)-1]);
            }
        }
        cout<<(ans==1e9?-1:ans)<<ln;
    }

    return 0;
}
