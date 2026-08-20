struct node {
    int val;
    node *left, *right;

    node() : val(0), left(nullptr), right(nullptr) {
    }

    node(int x) : val(x), left(nullptr), right(nullptr) {
    }

    node(int x, node *left, node *right) : val(x), left(left), right(right) {
    }
};

struct Tree {
    node *root;
    int sz;

    Tree() : root(nullptr) {
        sz = 0;
    }

    int size() const {
        return sz;
    }

    bool contains(int x) const {
        return contains(x, root);
    }

    static bool contains(int x, const node *subroot) {
        if (subroot == nullptr)
            return false;
        if (subroot->val == x)
            return true;
        if (x < subroot->val)
            return contains(x, subroot->left);
        return contains(x, subroot->right);
    }

    void insert(int x) {
        if (contains(x, root))
            return;
        sz++;
        root = add(x, root);
    }

    static node *add(int x, node *subroot) {
        if (subroot == nullptr)
            return new node(x);
        if (x < subroot->val)
            subroot->left = add(x, subroot->left);
        else
            subroot->right = add(x, subroot->right);
        return subroot;
    }


    int max() const {
        return max(root)->val;
    }

    static node *max(node *subroot) {
        assert(subroot!=nullptr);
        if (subroot->right == nullptr)
            return subroot;
        return max(subroot->right);
    }

    void remove(int x) {
        if (contains(x, root)) {
            root = remove(x, root);
            sz--;
        }
    }

    node *remove(int x, node *subroot) {
        assert(subroot!=nullptr);
        if (subroot->val == x) {
            if (subroot->left == nullptr && subroot->right == nullptr) {
                delete subroot;
                return nullptr;
            }
            if (subroot->left != nullptr && subroot->right == nullptr) {
                node *aux = subroot->left;
                delete subroot;
                return aux;
            }
            if (subroot->left == nullptr && subroot->right != nullptr) {
                node *aux = subroot->right;
                delete subroot;
                return aux;
            }
            node *pred = max(subroot->left);
            assert(pred!=nullptr);
            subroot->val = pred->val;
            subroot->left = remove(pred->val, subroot->left);
            return subroot;
        }
        if (x < subroot->val)
            subroot->left = remove(x, subroot->left);
        else
            subroot->right = remove(x, subroot->right);
        return subroot;
    }

    void clear() {
        clear(root);
        sz = 0;
        root = nullptr;
    }

    static void clear(const node *subroot) {
        if (subroot == nullptr)
            return;
        clear(subroot->left);
        clear(subroot->right);
        delete subroot;
    }


    void dfs() const {
        dfs(root);
        cout << ln;
    }

    static void dfs(const node *subroot) {
        if (subroot == nullptr)
            return;
        dfs(subroot->left);
        cout << subroot->val << " ";
        dfs(subroot->right);
    }
};
