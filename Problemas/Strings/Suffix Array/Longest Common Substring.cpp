//https://vjudge.net/problem/SPOJ-LCS
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
int nums[3];
const int N=500010;
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


int getI(int j) {
    return j < nums[1] ? 0 : 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    nums[1] = s.length() + 1;
    s += "$" + t  +"%"  ;
    for (int i =0;i<s.length();i++) arr[i]=s[i];
    nums[2] = s.length();
    suffix_array(arr,s.size());
    int maxLCP = 0;
    for (int i = 2; i<s.size() ; i++) {
        if (getI(p[i]) != getI(p[i - 1]) && lcp[i] > maxLCP)
            maxLCP = lcp[i];
    }
    cout << maxLCP << endl;
    return 0;
}
