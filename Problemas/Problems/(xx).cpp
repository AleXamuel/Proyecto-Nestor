//https://atcoder.jp/contests/abc454/tasks/abc454_d
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (const auto &i : V) cerr << i << " "; cerr << endl;
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define DBGM(M) cerr<<#M<<" = "; for(const auto &e:M) cerr<<"("<<e.first<<","<<e.second<<")"<<", ";cerr<<endl;
#define RAYA cerr << " ============================ " << endl;


string f(const string &A){
    string Q;
    int n = sz(A);
    For(i,0,n){
        if(A[i]==')'){
            if(sz(Q)>=3){
                int m = sz(Q);
                if(Q[m-1]=='x' && Q[m-2]=='x' && Q[m-3]=='('){
                    char a = Q.back();
                    char b = Q[m-2];
                    Q.pop_back();
                    Q.pop_back();
                    Q.pop_back();
                    Q.push_back(b);
                    Q.push_back(a);
                    continue;
                }
            }
            Q.push_back(A[i]);
        }
        else{
            Q.push_back(A[i]);
        }
    }
    return Q;
}


void solve() {
   string a,b;
   cin>>a>>b;
   a = f(a);
   b = f(b);
   cout<<(a==b?"Yes":"No")<<ln;
   

   
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
