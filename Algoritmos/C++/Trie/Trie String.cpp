const int K = 26;

struct node {
    int next[K];
    bool output;

    node() {
        fill(begin(next), end(next), -1);
        output = false;
    }
};


struct Trie {
    vector<node> t;

    Trie() {
        t.assign(1, node());
    }

    void insert(const string &word) {
        int v = 0;
        for (const auto &c: word) {
            int pos = c - 'a';
            if (t[v].next[pos] == -1) {
                t[v].next[pos] = sz(t);
                t.push_back(node());
            }
            v = t[v].next[pos];
        }
        t[v].output = true;
    }

    bool search(const string &word) {
        int v = 0;
        for (const auto &c: word) {
            int pos = c - 'a';
            if (t[v].next[pos] == -1)
                return false;
            v = t[v].next[pos];
        }
        return t[v].output;
    }

    bool startsWith(const string &prefix) {
        int v = 0;
        for (const auto &c: prefix) {
            int pos = c - 'a';
            if (t[v].next[pos] == -1)
                return false;
            v = t[v].next[pos];
        }
        return true;
    }

};
