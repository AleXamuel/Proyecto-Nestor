//https://vjudge.net/problem/SPOJ-ADFRUITS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Pair pair<int,int>
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define ln "\n"
#define mk(x,y) make_pair(x,y)
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
const ll inf = 1e18;
const int MOD = 998244353;
string LCS(string s1, string s2) {
    int m = s1.length();
    int k = s2.length();
    vector<vector<int>> dp(m+1,vector<int>(k+1,0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            if (s1[i-1]==s2[j-1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int index = dp[m][k];
    string lcs(index,'#');
    int i = m, j = k;
    while (i > 0 && j > 0) {
        if (s1[i-1]==s2[j-1])  {
            lcs[--index] = s1[i-1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return lcs;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    while (cin>>s>>t) {
        string u=LCS(s,t);
        int i=0,j=0;
        For(k,0,u.length()) {
            while (s[i]!=u[k])
                cout<<s[i++];
            while (t[j]!=u[k])
                cout<<t[j++];
            cout<<u[k];
            i++;
            j++;
        }
        For(l,i,s.length())
            cout<<s[l];
        For(l,j,t.length())
            cout<<t[l];
        cout<<ln;
    }
    return 0;
}

//freopen("socdist.in", "r",stdin);
//freopen("socdist.out", "w", stdout)
