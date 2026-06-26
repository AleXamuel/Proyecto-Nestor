//https://codeforces.com/contest/190/problem/C
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l, r)(rng);
#define ll long long
#define ull unsigned ll
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, a, b) for (int i = a; i >= b; i--)
#define all(A) A.begin(), A.end()
#define ln "\n"
#define sz(A) (int) A.size()
#define Pair pair<int,int>
#define mk(a,b) make_pair(a,b)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(V) cerr << #V << " = "; for (const auto &i : V) cerr << i << " "; cerr << endl
#define DBGA(A,l,r) cerr << #A << " = "; For(i,l,r) cerr << A[i] << " "; cerr << endl
#define DBGP(P) cerr<<#P<<" =("<<P.first<<","<<P.second<<")"<<endl
#define DBGM(M) cerr<<#M<<" = "; for(const auto &e:M) cerr<<"("<<e.first<<","<<e.second<<")"<<", ";cerr<<endl
#define RAYA cerr << " ============================ " << endl
#define VVI vector<vector<ll>>

struct Node {
    char val;
    Node *left, *right;

    Node(char v, Node *l, Node *r) {
        this->val = v;
        this->left = l;
        this->right = r;
    }
};

void dfs(Node *root) {
    if (root == nullptr)
        return;
    if (root->val == 'i')
        cout << "int";
    else {
        cout << "pair<";
        dfs(root->left);
        cout << ",";
        dfs(root->right);
        cout << ">";
    }
}


void solve() {
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    vector<string> A;
    A.reserve(n);
    stringstream ss(s);
    string cur;
    while (ss >> cur)
        A.push_back(cur);
    stack<Node *> Q;
    reverse(all(A));
    n = sz(A);
    For(i, 0, n) {
        if (A[i] == "int") {
            Q.emplace(new Node('i', nullptr, nullptr));
        } else {
            if (sz(Q) <= 1) {
                cout << "Error occurred" << ln;
                return;
            }
            Node *l = Q.top();
            Q.pop();
            Node *r = Q.top();
            Q.pop();
            Q.push(new Node('p', l, r));
        }
    }
    if (sz(Q) != 1) {
        cout << "Error occurred" << ln;
    } else {
        dfs(Q.top());
        cout << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("algoritm.in", "r",stdin);
    //freopen("algoritm.out", "w",stdout);
    int T = 1;
    //cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
