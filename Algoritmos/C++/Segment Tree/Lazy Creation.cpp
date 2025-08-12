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
