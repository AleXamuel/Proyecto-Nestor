//https://www.spoj.com/problems/THRBL/cstart=10
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int t[50001*4];
void buildST(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        buildST(a, v*2, tl, tm);
        buildST(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2] , t[v*2+1]);
    }
}
void build(int a[],int n) {
    buildST(a,1,0,n-1);
}
int sumST(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(sumST(v*2, tl, tm, l, min(r, tm))
           , sumST(v*2+1, tm+1, tr, max(l, tm+1), r));
}
int sum(int n, int l, int r) {
    return sumST(1,0,n-1,l,r);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int arr[50001];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build(arr,n);
    int c=0;
    while(m--) {
        int l,r;
        cin>>l>>r;
        l--;r--;
        if(arr[l]>=sum(n,l+1,r-1))
            c++;
    }
    cout<<c<<"\n";
    return 0;
}
