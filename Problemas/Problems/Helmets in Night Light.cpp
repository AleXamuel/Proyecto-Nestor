//https://codeforces.com/contest/1876/problem/A
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
#define Pair pair<int,int>
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


struct Item {
    int first, second;

    bool operator<(const Item &o) const {
        if (first != o.first)
            return first < o.first;
        return second > o.second;
    }
};

ostream &operator<<(ostream &os, const Item &o) {
    os << "(" << o.first << "," << o.second << ")";
    return os;
}


void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> A(n), B(n);
    for (int &i: A)
        cin >> i;
    for (int &i: B)
        cin >> i;
    multiset<Item> H;
    For(i, 0, n)
        H.insert({B[i], A[i]});

    ll ans = p;
    const Item cur = {p, 1};
    queue<Item> Q;
    Q.push(*H.begin());
    H.erase(H.find(*H.begin()));
    while (!Q.empty()) {
        auto e = Q.front();
        Q.pop();
        if (e.first > p)
            e = cur;
        int val = e.second;
        vector<Item> act;
        for (const auto &i: H) {
            if (val == 0)
                break;
            act.push_back(i);
            ans += e.first;
            val--;
        }
        for (const auto &i: act) {
            H.erase(H.find(i));
            Q.push(i);
        }
    }
    cout << ans << ln;
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
