//Given an integer 'x', find in the array an integer 'y' which is the less number higher or equal to 'x'
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
        t[v] = max(t[v*2],t[v*2+1]);
    }
}
void build(int a[],int n) {
    buildST(a,1,0,n-1);
}
int get_firstST(int v, int l, int r, int x) {
    if(x>t[v]) return -1;
    if(l==r && x<=t[v]) return l;
    int mid = (l+r)/2;
    int left=t[2*v];
    if(x<=left) return get_firstST(2*v,l,mid,x);
    return get_firstST(2*v+1,mid+1,r,x);
}
int first(int n,int x) {
    return get_firstST(1,0,n-1,x);
}
void updateST(int v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr) {
        t[v] -= new_val;
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
