//Given an integer 'x', find in the array an integer 'y' which is the less number higher or equal to 'x'
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll* t;
int* t;
int ans=-1;
void buildST(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        buildST(a, v*2, tl, tm);
        buildST(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2],t[v*2+1]);
    }
}
void build(int a[],int n) {
    buildST(a,1,0,n-1);
}
void get_firstST(int v, int l, int r, int x, int j) {
    if(t[v]<x)return;
    if(ans>-1)return;
    if(l==r) {
        if(t[v]>=x)
            ans=l;
        return;
    }
    int m = (l+r)/2;
    get_firstST(v*2,l,m,x,j);
    get_firstST(v*2+1,m+1,r,x,j);
}
void first(int n,int x, int j) {
    return get_firstST(1,0,n-1,x,j);
}
void updateST(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            updateST(v*2, tl,   tm, pos, new_val);
        else
            updateST(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2] , t[v*2+1]);
    }
}
void update(int n, int pos, int x) {
    updateST(1,0,n-1,pos,x);
}
