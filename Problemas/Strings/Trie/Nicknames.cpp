//https://open.kattis.com/problems/nicknames
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define ones(x) __builtin_popcount(x)
#define VI vector<int>
#define VVI vector<VI>
#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)v.size()
#define DBGV(A) for(const auto&i:A)cerr<<i<<" ";cerr<<endl;
#define ln "\n"
#define RAYA cerr<<"-------------------------------------"<<endl

struct Node {
    int next[26];
    int cnt;

    Node() {
        memset(next, -1, sizeof(next));
        cnt = 0;
    }
};

vector<Node> trie(1);

void insertWord(const string &s) {
    int node = 0;

    for (char c: s) {
        int x = c - 'a';

        if (trie[node].next[x] == -1) {
            trie[node].next[x] = trie.size();
            trie.emplace_back();
        }
        node = trie[node].next[x];
        trie[node].cnt++;
    }
}

int query(const string &s) {
    int node = 0;

    for (char c: s) {
        int x = c - 'a';

        if (trie[node].next[x] == -1)
            return 0;

        node = trie[node].next[x];
    }
    return trie[node].cnt;
}

void solve() {
    int a, b;
    cin >> a;
    while (a--) {
        string s;
        cin >> s;
        insertWord(s);
    }
    cin >> b;
    while (b--) {
        string s;
        cin >> s;
        cout << query(s) << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

    return 0;
}
