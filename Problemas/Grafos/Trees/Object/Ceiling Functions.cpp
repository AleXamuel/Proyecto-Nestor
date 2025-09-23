#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define dll long double
#define ll long long
#define ull unsigned long long
#define Pair pair<int,int>
#define eb emplace_back
#define pb push_back
#define pf push_fron        t
#define all(x) x.begin(),x.end()
#define ln "\n"
#define uset unordered_set
#define umap unordered_map
#define For(i, a, b) for(int i = a; i < b; i++)
#define Rfor(i, a, b) for(int i = a; i >= b; i--)
vector<pair<int, int> > moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int nmax = 2e5 + 5, MOD = 1e9 + 7, inf = 1e9;

struct tree {
    struct node {
        int v;
        node *l, *r;

        node(int x) {
            v = x;
            l = nullptr;
            r = nullptr;
        }
    };

    node *root;

    tree(int r) {
        root = new node(r);
    };

    void add(int v) {
        add_f(root, v);
    }

    void add_f(node *n, int x) {
        if (x < n->v) {
            if (n->l) {
                add_f(n->l, x);
                return;
            }
            n->l = new node(x);
            return;
        }
        if (n->r) {
            add_f(n->r, x);
            return;
        }
        n->r = new node(x);
    }

    bool operator ==(const tree &o) const {
        return equals(root, o.root);
    }

    bool equals(node *a, node *b) const {
        if (a == nullptr)
            return b == nullptr;
        if (b == nullptr)
            return false;
        return equals(a->l, b->l) && equals(a->r, b->r);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<tree> A, B;
    For(i, 0, n) {
        int r;
        cin >> r;
        A.pb(r);
        For(j, 1, m) {
            int x;
            cin >> x;
            A.back().add(x);
        }
    }
    For(i, 0, A.size()) {
        if (find(all(B), A[i]) == B.end())
            B.pb(A[i]);
    }
    cout << B.size() << ln;
}

signed main() {
    //freopen("balls.in", "r",stdin);
    //freopen("balls.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
