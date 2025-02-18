//https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/A
//https://codeforces.com/edu/courses
using namespace std;
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <string>
#define ll long long
double nums[100005];
double b[100005];
double pf[100005];
int n,k;
pair<int,int> help(double x) {
    for(int i=0;i<n;i++)
        b[i]=nums[i]-x;
    pf[0]=0;
    for(int i=0;i<n;i++)
        pf[i+1]=pf[i]+b[i];
    map<double,int> st;
    for(int i=k;i<=n;i++) {

        st.insert({pf[i-k],i-k});
        const auto aux=st.begin();
        if(aux->first<=pf[i])
            return make_pair(aux->second+1,i);
    }
    return make_pair(-1,-1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("socdist.in", "r",stdin);
    //freopen("socdist.out", "w", stdout);

    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>nums[i];
    double l=0,r=110;
    pair<int,int> ans={1,n};
    while(r-l>1e-9) {
        double mid=(l+r)/2;
        pair<int,int> p=help(mid);
        if(p.first>-1) {
            ans=p;
            l=mid;
        }
        else
            r=mid;
    }
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}
