//https://codeforces.com/contest/2155/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, n, k) for (int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define INF(t) numeric_limits<t>::max()
#define ln "\n"
#define sz(v) (int)((v).size())
#define Pair pair<ll,ll>
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ============================ " << endl


ostream &operator<<(ostream &os,Pair A) {
    os << "(" << A.first << "," << A.second << ")";
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> A) {
    if (A.empty()) {
        os << "[]";
        return os;
    }
    os << "[";
    For(i, 0, sz(A)-1)
        os << A[i] << ", ";
    os << A.back() << "]";
    return os;
}

int mod(int a, int b) {
    if (b < 0)
        b *= -1;
    return (a % b + b) % b;
}

const int MAX = 1e5;
int n;
int A[MAX];

int f(const vector<char> &cur) {
    vector<int> pref(n);
    pref[0] = 0;
    For(i, 1, n) {
        if (cur[i - 1] == 'L')
            pref[i] = pref[i - 1] + 1;
        else
            pref[i] = pref[i - 1];
    }
    vector<int> suf(n);
    suf[n - 1] = 0;
    Rfor(i, n-2, 0) {
        if (cur[i + 1] == 'R')
            suf[i] = suf[i + 1] + 1;
        else
            suf[i] = suf[i + 1];
    }
    For(i, 0, n)
        if (pref[i] + suf[i] + 1 != A[i])
            return 0;

    return 1;
}


void solve() {
    cin >> n;
    For(i, 0, n)
        cin >> A[i];
    if (n == 1) {
        cout << (A[0] == 1 ? 2 : 0) << ln;
        return;
    }
    if (A[0] - A[1] == 0) {
        vector<char> B(n);
        vector<char> C(n);
        B[0] = 'L';
        B[1] = 'R';

        C[0] = 'R';
        C[1] = 'L';
        For(i, 1, n-1) {
            int val = A[i] - A[i + 1];
            if (val == 0) {
                if (B[i] == 'L')
                    B[i + 1] = 'R';
                else
                    B[i + 1] = 'L';
                if (C[i] == 'L')
                    C[i + 1] = 'R';
                else
                    C[i + 1] = 'L';
            } else if (val == 1) {
                B[i + 1] = 'R';
                C[i + 1] = 'R';
            } else if (val == -1) {
                B[i + 1] = 'L';
                C[i + 1] = 'L';
            } else {
                cout << 0 << ln;
                return;
            }
        }
        int ans = f(B) + f(C);
        if (B == C)
            ans--;
        cout << ans << ln;
    } else {
        vector<char> ans(n);
        int dif = A[0] - A[1];
        if (dif == 1) {
            ans[0] = 'R';
            ans[1] = 'R';
        } else if (dif == -1) {
            ans[0] = 'L';
            ans[1] = 'L';
        } else {
            cout << 0 << ln;
            return;
        }
        For(i, 1, n-1) {
            int val = A[i] - A[i + 1];
            if (val == 0) {
                if (ans[i] == 'L')
                    ans[i + 1] = 'R';
                else
                    ans[i + 1] = 'L';
            } else if (val == 1)
                ans[i + 1] = 'R';
            else if (val == -1)
                ans[i + 1] = 'L';
            else {
                cout << 0 << ln;
                return;
            }
        }
        cout << f(ans) << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
