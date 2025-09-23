struct STP {
    //segment tree persistent for histograms
    struct node {
        int x,l,r;
        node(int a=0,int b=0, int c=0):x(a),l(b),r(c){}
    };
    vector<node>st;
    vector<int>rt;
    int N,sz;
    STP(int size) {
        N=size,sz=0;
        push();
        rt.push_back(0);
    }
    void push() {
        sz++;
        st.push_back(node(0,0,0));
    }
    void copy(int u,int v) {
        st[v]=st[u];
    }
    void update(int u, int v, int tl, int tr, int x) {
        push();
        copy(u,v);
        st[v].x++;
        if(tl==tr)return;
        int tm=tl+tr>>1;
        if(x<=tm)
            update(st[u].l,st[v].l=sz,tl,tm,x);
        else
            update(st[u].r,st[v].r=sz,tm+1,tr,x);
    }
    int query(int u, int v, int tl, int tr, int l, int r) {
        if(l>tr||r<tl)
            return 0;
        if(l<=tl&&tr<=r)
            return st[v].x-st[u].x;
        int tm=tl+tr>>1;
        return query(st[u].l,st[v].l,tl,tm,l,r)+query(st[u].r,st[v].r,tm+1,tr,l,r);
    }
    int query(int u, int v, int l , int r) {
        return query(rt[u],rt[v],1,N,l,r);
    }
    void add(int x) {
        int lsz=rt.size();
        rt.push_back(sz);
        update(rt[lsz-1],rt[lsz],1,N,x);
    }
 
};
