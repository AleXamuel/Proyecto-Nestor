//https://codeforces.com/gym/105505/problem/J
#include <bits/stdc++.h>
#include <iomanip>
#define pi 3.141592653589793238462643383279502884197
using namespace std;
const int nmax=3*1e5+5;
pair<int,int> nums[nmax];
double d(int t, int x) {
    return (double)x/tan(t*pi/180);
}
double h(int t, double x) {
    return (double)x*tan(t*pi/180);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(10);
    int t,n;
    cin>>t>>n;
    for(int i =0;i<n;i++) {
        int x,h;
        cin>>x>>h;
        nums[i]={x,h};
    }

    sort(nums,nums+n);
    long double ans=0;
    double res=0;
    for(int i =0;i<n;i++) {
        double x=nums[i].first+d(t,nums[i].second);
        res=x;
        pair <int,int> p={nums[i].first,nums[i].second};
        while(true) {
            if(i+1==n||x<=nums[i+1].first) {
                ans+=res-p.first;
                break;
            }
            if(h(t,x-nums[i+1].first)<=nums[i+1].second) {
                ans+=nums[i+1].first-nums[i].first;
                break;
            }
            res-=nums[i+1].first-nums[i].first;
            ans+=nums[i+1].first-nums[i].first;
            i++;

        }
    }
    cout<<ans<<"\n";
    return 0;
}
