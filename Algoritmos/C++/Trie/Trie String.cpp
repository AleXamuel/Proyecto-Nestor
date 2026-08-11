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
