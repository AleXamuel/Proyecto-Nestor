//https://vjudge.net/problem/CSES-1649
#include <iostream>
#include <algorithm>
#include <exception>
using namespace std;
typedef long long ll;
int* t;
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
int main() {
    int n,q;
    cin>>n>>q;
    int* a=new int[n];
    t=new int [4*n];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    build(a,n);
    for (int i = 0; i < q; i++) {
        int type;
        cin>>type;
        if (type == 1) {
            int j,x;
            cin>>j>>x;
            update(n,j-1,x);
        }
        else {
            int l,r;
            cin>>l>>r;
            cout<<sum(n,l-1,r-1)<<endl;
        }
    }
    delete[] a;
    delete[] t;
    return 0;

}
