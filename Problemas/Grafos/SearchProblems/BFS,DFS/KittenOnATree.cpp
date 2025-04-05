//https://open.kattis.com/problems/kitten
using namespace std;
#include <bits/stdc++.h>

#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"

vector<string> split(string s, char regex) {
    int n = s.size();
    vector<string> ans;
    string t;
    for (int i = 0; i < n; i++) {
        if (s[i] == regex) {
            ans.push_back(t);
            t.clear();
            continue;
        }
        t += s[i];
    }
    ans.push_back(t);
    return ans;
}

unordered_map<int, vector<int> > adj;
unordered_map<int, int> pi;

void dfs(int u) {
    for (const auto &v: adj[u]) {
        pi[v] = u;
        dfs(v);
    }
}


void solve() {
    int K, R;
    cin >> K;
    bool cond = true;
    cin.ignore();
    while (true) {
        string s;
        getline(cin, s);
        vector<string> nums = split(s, ' ');
        int b = stoi(nums[0]);
        if (cond) {
            R = b;
            cond = false;
        }
        if (b == -1)
            break;
        const int n = nums.size();
        fori(i, 1, n) {
            int a = stoi(nums[i]);
            adj[a].push_back(b);
        }
    }
    pi[K] = -1;
    dfs(K);
    vector<int> ans;
    while (R != K) {
        ans.push_back(R);
        R = pi[R];
    }
    ans.push_back(K);
    reverse(ans.begin(), ans.end());
    for (const auto &i: ans)
        cout << i << " ";
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    solve();
    return 0;
}
