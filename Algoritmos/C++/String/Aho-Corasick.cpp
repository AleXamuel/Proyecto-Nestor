struct Aho{
    static constexpr int nmax = 1e3 + 1;
    ll n=0,m=0;
    ll to[nmax][52],go[nmax][52],mark[nmax],qnt[nmax],p[nmax],pc[nmax],link[nmax],exit[nmax];
    vector<ll>idx[nmax];
    //the second size is the alphabeth length in this case is 52
    Aho(){
        memset(go,-1,sizeof(go));
        memset(link,-1,sizeof(link));
        memset(exit,-1,sizeof(exit));
    }
    void insert(const string& s){
        ll u=0;
        for(char ch:s){
            ll c=I(ch);
            ll& v=to[u][c];
            if(!v)
                v=++n,p[v]=u,pc[v]=c;
            u=v,++qnt[u];
        }
        ++mark[u],++qnt[0],idx[u].eb(m++);
    }
    int I(char c){//   'a'=0     'A'=26
        return c<'a'?26+c-'A':c-'a';
    }
    vector<Pair>occur(const string& s){
        vector<int>occ(n+1);
        vector<Pair>res;
        ll u=0;
        for(char ch:s){
            u=go_to(u,I(ch));
            for(ll v=u;v!=0;v=get_exit(v))
                ++occ[v];
        }
        For(v,0,n+1)
            for(auto i:idx[v])
                if(occ[v])
                    res.pb({i,occ[v]});
        return res;
    }
    ll get_link(ll u){
        if(link[u]!=-1)return link[u];
        if(u==0||p[u]==0)return link[u]=0;
        return link[u]=go_to(get_link(p[u]),pc[u]);
    }
    ll go_to(ll u, ll c){
        if(go[u][c]!=-1)return go[u][c];
        if(to[u][c])return go[u][c]=to[u][c];
        return go[u][c]=u==0?0:go_to(get_link(u),c);
    }
    ll get_exit(ll u){
        ll v=get_link(u);
        if(exit[u]!=-1)return exit[u];
        return exit[u]=(v==0||mark[v])?v:get_link(v);
    }
    void clear(){
        n = m = 0;
        memset(to, 0, sizeof(to));
        memset(go, -1, sizeof(go));
        memset(mark, 0, sizeof(mark));
        memset(qnt, 0, sizeof(qnt));
        memset(p, 0, sizeof(p));
        memset(pc, 0, sizeof(pc));
        memset(link, -1, sizeof(link));
        memset(exit, -1, sizeof(exit));
        For(i, 0, nmax) idx[i].clear();
    }

};
struct Aho {
    static constexpr int K = 52;
    int n, rt, chd[nmax][K], fail[nmax], q[nmax], hd, tl, en[nmax];

    int newNode() {
        n++;
        fill_n(chd[n], K, 0);
        fail[n] = 0;
        en[n] = inf;
        return n;
    }

    void init() {
        n = 0;
        rt = newNode();
        fail[rt] = rt;
    }

    int get(char c) {
        return c < 'a' ? c + 26 - 'A' : c - 'a';
    }

    void insert(string &s, int k) {
        int u, i, c;
        int sn = s.size();
        u = rt;
        for (i = 0; i < sn; i++) {
            c = get(s[i]);
            if (!chd[u][c])
                chd[u][c] = newNode();
            u = chd[u][c];
        }
        en[u] = min(en[u], k);
    }

    void build() {
        int c, u, v, w;
        hd = tl = 0;
        for (c = 0; c < K; c++) {
            u = chd[rt][c];
            if (!u)continue;
            fail[u] = rt;
            q[tl++] = u;
        }
        while (hd < tl) {
            u = q[hd++];
            en[u] = min(en[u], en[fail[u]]);
            for (c = 0; c < K; c++) {
                v = chd[u][c];
                if (!v)continue;
                for (w = fail[u]; w != rt && !chd[w][c]; w = fail[w]);
                if (chd[w][c])w = chd[w][c];
                fail[v] = w;
                q[tl++] = v;
            }
        }
    }

    int find(string &s) {
        int len = s.length();
        int u = rt;
        int ans = inf;
        for (int i = 0; i < len; i++) {
            int c = get(s[i]);
            while (u != rt && !chd[u][c])
                u = fail[u];
            if (chd[u][c])
                u = chd[u][c];
            ans = min(ans, en[u]);
        }
        return ans;
    }
};
