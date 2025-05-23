//https://codeforces.com/contest/140/problem/C
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define dll double long
#define ll long long
#define Pair pair<ll,int>
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(),x.end()
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<Pair > ch = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int mod = 1000000007;
const int inf = 500;
//solution
bool f(unordered_map<int,int>&mp, int k) {
    int c=0;
    for(auto&[a,b]:mp)
        c+=min(b,k);
    return k*3<=c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    unordered_map<int,int>mp;
    For(i,0,n) {
        int x;cin>>x;
        mp[x]++;
    }
    int l=0,r=n/3,k=0;
    while(l<=r) {
        int mid=(l+r)/2;
        if(f(mp,mid)) {
            l=mid+1;
            k=mid;
        }
        else
            r=mid-1;
    }
    vector<int>a;
    for(auto&[x,b]:mp)
        For(i,0,min(b,k))
            a.pb(x);
    sort(all(a));
    cout<<k<<ln;
    For(i,0,k)
        cout<<a[i+(k<<1)]<<" "<<a[i+k]<<" "<<a[i]<<ln;

    return 0;
}
