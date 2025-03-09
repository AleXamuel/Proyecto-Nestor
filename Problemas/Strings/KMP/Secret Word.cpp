//https://vjudge.net/problem/UVA-12467
using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define Pair pair<int,int>
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define ln "\n"
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
const ll inf = 1e18;
const ll mod = 998244353;
const int N = 100001;
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("socdist.in", "r",stdin);
    //freopen("socdist.out", "w", stdout)
    int ti;cin>>ti;
    while(ti--) {
        string s; cin>>s;
        int n = s.length();
        string t=s;
        reverse(all(t));
        auto table = prefix_function(s+"$"+t);
        int ans=0;
        For(i,n,table.size())
            ans=max(ans, table[i]);
        string solve=s.substr(0,ans);
        reverse(all(solve));
        cout<<solve<<ln;
    }
    return 0;
}


