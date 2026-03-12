//https://vjudge.net/problem/UVA-11237
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
#define DBGA(A) cerr << #A << " = "; for (auto &i : A) cerr << i << " "; cerr << endl;
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl;
#define RAYA cerr << " ============================ " << endl


const int MAX = 1e5;

int A[MAX], pref[MAX];

void solve() {
    int c, n;
    while (cin >> c >> n && c != 0) {
        For(i, 0, n)
            cin >> A[i];
        pref[0] = A[0] % c;
        For(i, 1, n) {
            pref[i] = pref[i - 1] + A[i] % c;
            pref[i] %= c;
        }
        int ans = -1;
        For(i, 0, n)
            if (pref[i] == 0) {
                ans = i + 1;
                break;
            }

        if (ans == -1) {
            map<int, int> H;
            For(i, 0, n) {
                if (H.find(pref[i]) != H.end()) {
                    For(j, H[pref[i]]+2, i+2)
                        cout << j << " ";
                    cout << ln;
                    break;
                }
                H[pref[i]] = i;
            }
        } else {
            For(j, 1, ans+1)
                cout << j << " ";
            cout << ln;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
}
