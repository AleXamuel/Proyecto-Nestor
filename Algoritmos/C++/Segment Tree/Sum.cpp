
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll* t;
void buildST(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        buildST(a, v*2, tl, tm);
        buildST(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
void build(int a[],int n) {
    buildST(a,1,0,n-1);
}
ll sumST(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sumST(v*2, tl, tm, l, min(r, tm))
           + sumST(v*2+1, tm+1, tr, max(l, tm+1), r);
}
ll sum(int n, int l, int r) {
    return sumST(1,0,n-1,l,r);
}
void updateST(int v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            updateST(v*2, tl, tm, pos, new_val);
        else
            updateST(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}
void update(int n, int pos, int x) {
    updateST(1,0,n-1,pos,x);
}
