//https://codeforces.com/problemset/problem/1486/D
using namespace std;
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <string>
#define ll long long
#define Pair pair<int,int>
int nums[200005];
int b[200005];
int pf[200005];
int n,k;
bool help(int x) {
    for(int i=0;i<n;i++)
        b[i]=nums[i]>=x?1:-1;
    pf[0]=0;
    for(int i=0;i<n;i++)
        pf[i+1]=pf[i]+b[i];
    set<int> st;
    for(int i=k;i<=n;i++) {
        st.insert(pf[i-k]);
        if(*st.begin()<pf[i])
            return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("socdist.in", "r",stdin);
    //freopen("socdist.out", "w", stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>nums[i];
    int l=1,r=n;
    int ans=0;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(help(mid)) {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
