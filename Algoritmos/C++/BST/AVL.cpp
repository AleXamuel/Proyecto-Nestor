struct AVL {
    struct Node {
        int key, height, sz;
        Node *left, *right;

        Node(int k): key(k), height(1), sz(1), left(nullptr), right(nullptr) {
        }
    };

    Node *root = nullptr;

    int h(Node *n) { return n ? n->height : 0; }
    int s(Node *n) { return n ? n->sz : 0; }
    int bal(Node *n) { return n ? h(n->left) - h(n->right) : 0; }

    void upd(Node *n) {
        if (!n) return;
        n->height = 1 + max(h(n->left), h(n->right));
        n->sz = 1 + s(n->left) + s(n->right);
    }

    Node *rotRight(Node *y) {
        Node *x = y->left;
        Node *t2 = x->right;
        x->right = y;
        y->left = t2;
        upd(y);
        upd(x);
        return x;
    }

    Node *rotLeft(Node *x) {
        Node *y = x->right;
        Node *t2 = y->left;
        y->left = x;
        x->right = t2;
        upd(x);
        upd(y);
        return y;
    }

    Node *insert(Node *n, int key) {
        if (!n) return new Node(key);
        if (key < n->key) n->left = insert(n->left, key);
        else if (key > n->key) n->right = insert(n->right, key);
        else return n;
        upd(n);
        int b = bal(n);
        if (b > 1 && key < n->left->key) return rotRight(n);
        if (b < -1 && key > n->right->key) return rotLeft(n);
        if (b > 1 && key > n->left->key) {
            n->left = rotLeft(n->left);
            return rotRight(n);
        }
        if (b < -1 && key < n->right->key) {
            n->right = rotRight(n->right);
            return rotLeft(n);
        }
        return n;
    }

    Node *minNode(Node *n) {
        while (n && n->left) n = n->left;
        return n;
    }

    Node *erase(Node *n, int key) {
        if (!n) return n;
        if (key < n->key) n->left = erase(n->left, key);
        else if (key > n->key) n->right = erase(n->right, key);
        else {
            if (!n->left || !n->right) {
                Node *tmp = n->left ? n->left : n->right;
                if (!tmp) {
                    delete n;
                    return nullptr;
                } else {
                    *n = *tmp;
                    delete tmp;
                }
            } else {
                Node *tmp = minNode(n->right);
                n->key = tmp->key;
                n->right = erase(n->right, tmp->key);
            }
        }
        upd(n);
        int b = bal(n);
        if (b > 1 && bal(n->left) >= 0) return rotRight(n);
        if (b > 1 && bal(n->left) < 0) {
            n->left = rotLeft(n->left);
            return rotRight(n);
        }
        if (b < -1 && bal(n->right) <= 0) return rotLeft(n);
        if (b < -1 && bal(n->right) > 0) {
            n->right = rotRight(n->right);
            return rotLeft(n);
        }
        return n;
    }

    int find(Node *n, int idx) {
        if (!n->left && !n->right)
            return n->key;
        if (!n->left)
            return idx == 0 ? n->key : find(n->right, idx - 1);
        if (!n->right)
            return idx == n->left->sz ? n->key : find(n->left, idx);
        if (idx == n->left->sz)
            return n->key;
        if (n->left->sz >= idx)
            return find(n->left, idx);
        return find(n->right, idx - n->left->sz - 1);
    }

    void inorder(Node *n) {
        if (!n) return;
        inorder(n->left);
        cout << n->key << "(sz=" << n->sz << ") ";
        inorder(n->right);
    }

    void insert(int key) { root = insert(root, key); }
    void erase(int key) { root = erase(root, key); }
    int find(int idx) { return find(root, idx); }

    void print() {
        inorder(root);
        cout << endl;
    }

    int size() { return s(root); }
};
