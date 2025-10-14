//https://vjudge.net/problem/UVA-536
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
ostream &operator<<(ostream &os, deque<T> A) {
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


struct Node {
    char val;
    Node *left, *right;

    Node(char v, Node *l, Node *r) {
        val = v;
        left = l;
        right = r;
    }
};


unordered_map<char, int> H;

Node *root;

Node *add(Node *subroot, char val) {
    if (subroot == nullptr)
        return new Node(val, nullptr, nullptr);
    int act = H[subroot->val] - H[val];
    if (act > 0)
        subroot->left = add(subroot->left, val);
    else
        subroot->right = add(subroot->right, val);
    return subroot;
}

void dfs(Node *subroot) {
    if (subroot == nullptr)
        return;
    dfs(subroot->left);
    dfs(subroot->right);
    cout << subroot->val;
}

void solve() {
    string pre, in;
    while (cin >> pre >> in) {
        H.clear();
        root = new Node(pre.front(), nullptr, nullptr);
        int n = sz(in);
        For(i, 0, n)
            H[in[i]] = i;
        For(i, 1, n)
            root = add(root, pre[i]);
        dfs(root);
        cout << ln;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
