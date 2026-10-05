//https://open.kattis.com/problems/fallingleaves
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(v) (int)v.size()
#define VI vector<int>
#define VVI vector<VI>
#define For(i, a, b) for(int  i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define all(v) (v).begin(), (v).end()
#define DBGV(A) for(const auto&i:A)cerr<<i<<" ";cerr<<endl;
#define ln "\n"

struct Node {
    char val;
    Node *left;
    Node *right;

    Node(char x): val(x), left(nullptr), right(nullptr) {
    }
};

Node* insert(Node* root, char x) {
    if (!root) return new Node(x);
    if (x < root->val)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

void preorder(Node* root, string &ans) {
    if (!root) return;
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void solve() {
    string s;
    while (cin >> s) {
        if (s == "$")
            break;
        vector<string> lines;
        while (s != "*" && s != "$") {
            lines.push_back(s);
            cin >> s;
        }

        Node* root = nullptr;
        reverse(all(lines));
        for (const string &line : lines) {
            for (char c : line) {
                root = insert(root, c);
            }
        }

        string ans = "";
        preorder(root, ans);
        cout << ans << "\n";

        deleteTree(root);
        s.clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
