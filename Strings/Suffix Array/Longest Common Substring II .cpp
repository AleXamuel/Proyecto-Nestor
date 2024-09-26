#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define pb push_back
using namespace std;
const int N=2000010;
int sz;
int* t;
int* tt;
void buildST(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        buildST(a, v*2, tl, tm);
        buildST(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2] ,t[v*2+1]);
    }
}
void build(int a[], int n) {
    buildST(a,1,0,n-1);
}
int sumQ(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 2140000000;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(sumQ(v*2, tl, tm, l, min(r, tm))
           , sumQ(v*2+1, tm+1, tr, max(l, tm+1), r));
}
int sum(int n,int l, int r) {
    return sumQ(1,0,n-1,l,r);
}
void updateQ(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v]= new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            updateQ(v*2, tl, tm, pos, new_val);
        else
            updateQ(v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2] , t[v*2+1]);
    }
}
void update(int n, int pos, int x) {
    updateQ(1,0,n-1,pos,x);
}


//segundo segment

void buildST2(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        tt[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        buildST2(a, v*2, tl, tm);
        buildST2(a, v*2+1, tm+1, tr);
        tt[v] = min(tt[v*2] ,tt[v*2+1]);
    }
}
void build2(int a[], int n) {
    buildST2(a,1,0,n-1);
}
int sumQ2(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 2140000000;
    if (l == tl && r == tr) {
        return tt[v];
    }
    int tm = (tl + tr) / 2;
    return min(sumQ2(v*2, tl, tm, l, min(r, tm))
           , sumQ2(v*2+1, tm+1, tr, max(l, tm+1), r));
}
int sum2(int n,int l, int r) {
    return sumQ2(1,0,n-1,l,r);
}
void updateQ2(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tt[v]= new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            updateQ2(v*2, tl, tm, pos, new_val);
        else
            updateQ2(v*2+1, tm+1, tr, pos, new_val);
        tt[v] = min(tt[v*2] , tt[v*2+1]);
    }
}
void update2(int n, int pos, int x) {
    updateQ2(1,0,n-1,pos,x);
}
struct SA {
#define REP(i,n) for(int i=0;i<int(n);i++)
#define REP1(i,a,b) for(int i=a;i<=int(b);i++)
    bool _t[N*2];
    int _s[N*2], _sa[N*2], _c[N*2], x[N], _p[N], _q[N*2], r[N], hei[N];
    int operator [] (int i) {return _sa[i];}
    void build(int* s, int n, int m) {
        memcpy(_s, s, sizeof(int) * n);
        sais(_s,_sa,_p,_q,_t,_c,n,m);
        mkhei(n);
    }
    void mkhei(int n) {
        REP(i,n) r[_sa[i]]=i;
        hei[0]=0;
        REP(i,n) if(r[i]) {
            int ans = i>0 ? max(hei[r[i-1]]-1,0):0;
            while (_s[i+ans]==_s[_sa[r[i]-1]+ans])ans++;
            hei[r[i]]=ans;
        }
    }
    void sais(int *s, int *sa, int *p, int *q, bool *t, int *c, int n, int z) {
        bool uniq = t[n-1] = true, neq;
        int nn = 0, nmxz = -1, *nsa = sa + n, *ns = s + n, lst = -1;
#define MS0(x,n) memset((x),0,n*sizeof(*(x)))
#define MAGIC(XD) MS0(sa, n); \
        memcpy(x,c,sizeof(int) * z); \
        XD; \
        memcpy(x+1,c,sizeof(int) * (z-1));\
        REP(i,n) if(sa[i] && !t[sa[i]-1]) sa[x[s[sa[i]-1]]++] =sa[i]-1;\
        memcpy(x,c,sizeof(int) * z); \
        for(int i =n-1; i>=0;i--)if(sa[i] && t[sa[i]-1]) sa[--x[s[sa[i]-1]]]=sa[i]-1;
        MS0(c,z);
        REP(i,n) uniq&= ++c[s[i]]<2;
        REP(i,z-1) c[i+1] +=c[i];
        if(uniq) {REP(i,n) sa[--c[s[i]]]=i;return;}
        for (int i =n-2;i>=0;i--) t[i]=s[i]==s[i+1] ? t[i+1] : s[i]<s[i+1];
        MAGIC(REP1(i,1,n-1) if(t[i] && !t[i-1]) sa[--x[s[i]]]=p[q[i]=nn++]=i);
        REP(i,n) if (sa[i] && t[sa[i]] && !t[sa[i]-1]) {
            neq=lst<0||memcmp(s+sa[i],s+lst,(p[q[sa[i]]+1]-sa[i])*sizeof(int));
            ns[q[lst=sa[i]]]=nmxz+=neq;
        }
        sais(ns, nsa, p+nn, q+n,t+n, c+z, nn, nmxz +1);
        MAGIC(for (int i = nn-1; i>=0;i--) sa[--x[s[p[nsa[i]]]]]=p[nsa[i]]);
    }
}sa;
int lcp[N], p[N];

void suffix_array(int* ip, int len) {
    ip[len++] = 0;
    sa.build(ip, len, 128);
    for (int i = 0; i < len; i++) {
        lcp[i] = sa.hei[i + 1];
        p[i] = sa._sa[i + 1];
    }
}

int arr[N];


int getI(int j, int* nums)  {

    int l = 0;
    int r = sz - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (j < nums[mid]) {
            if (j > nums[mid - 1])
                return mid - 1;
            r = mid - 1;
        } else {
            if (j < nums[mid + 1])
                return mid;
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string r;
    vector<string> cad(0);
    while (true) {
        getline(cin,r);
        if(r.empty())
            break;
        cad.pb(r);
    }
    int n=cad.size();
    int* nums=new int[n+1];
    int* index=new int[n];
    fill_n(index,n,-1);
    string s;
    cout<<endl;
    for(int i =0;i<cad.size();i++) {
        s+=cad[i]+static_cast<char>('A' + i);
        nums[i+1]=s.length();
    }
    sz=cad.size()+1;
    nums[0]=0;
    for(int i =0;i<s.size();i++) arr[i]=s[i];
    suffix_array(arr,s.size());
    int* a1=new int[s.size()];
    for(int i =0;i<s.size();i++)
        a1[i]=lcp[i];
    t=new int[s.size()*4];
    tt=new int[cad.size()*4];
    build(a1,s.size());
    build2(index,cad.size());
    int ans=0;
    for (int i = n;i<s.size();i++) {
        update2(n,getI(p[i],nums),i);
        int mn=sum2(n,0,n-1);
        if(mn!=-1) {
            ans=max(ans,sum(s.size(),mn+1,i));
        }
    }
    cout<<"\n"<<ans;
    delete[] nums;
    delete[] index;
    delete[] t;
    return 0;
}
