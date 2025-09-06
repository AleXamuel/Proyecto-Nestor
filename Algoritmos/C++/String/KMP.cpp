int ans[10001];
vector<int> kmp(const string& S) {
    int n=S.size();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int g = p[i - 1];
        while (g && S[i] != S[g]) 
            g = p[g - 1];
        p[i] = g + (S[i] == S[g]);
    }
    return p;
}
struct Automaton : vector<vector<int>> {
    Automaton(const string &S):vector(26,vector<int>(sz(S)+1)) {
        auto pi = kmp(S);
        auto &aut = *this; aut[S[0]-'A'][0] = 1;
        for (char c = 0; c < 26; c++)
            for (int i = 1; i <= sz(S); i++)
                aut[c][i] = S[i]-'A' == c ? i+1 : aut[c][pi[i - 1]];
    }
    int nex(char c, int pi) { return (*this)[c-'A'][pi]; }
};
//return the frequence of every prefix
vector<int> ans(n + 1);
for (int i = 0; i < n; i++)
    ans[pi[i]]++;
for (int i = n-1; i > 0; i--)
    ans[pi[i-1]] += ans[i];
for (int i = 0; i <= n; i++)
    ans[i]++;
