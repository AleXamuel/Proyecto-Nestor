struct node {
    int val, height;
    node *left, *right;

    node() : val(0), height(0), left(nullptr), right(nullptr) {
    }

    node(const int x) : val(x), height(0), left(nullptr), right(nullptr) {
    }

    node(const int x, node *left, node *right) : val(x), height(0), left(left), right(right) {
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

    node *add(int x, node *subroot) {
        if (subroot == nullptr)
            return new node(x);
        if (x < subroot->val)
            subroot->left = add(x, subroot->left);
        else
            subroot->right = add(x, subroot->right);
        updHeight(subroot);
        int bal = balance(subroot);
        if (abs(bal) > 1) {
            if (bal > 1) {
                if (balance(subroot->left) < 1)
                    subroot->left = rotateLeft(subroot->left);
                subroot = rotateRight(subroot);
            } else {
                if (balance(subroot->right) > 0)
                    subroot->right = rotateRight(subroot->right);
                subroot = rotateLeft(subroot);
            }
        }
        return subroot;
    }

    static node *rotateLeft(node *subroot) {
        node *aux = subroot->right;
        subroot->right = aux->left;
        aux->left = subroot;
        updHeight(subroot);
        updHeight(aux);
        return aux;
    }

    static node *rotateRight(node *subroot) {
        node *aux = subroot->left;
        subroot->left = aux->right;
        aux->right = subroot;
        updHeight(subroot);
        updHeight(aux);
        return aux;
    }

    static int balance(const node *subroot) {
        if (subroot == nullptr)
            return 0;
        return getHeight(subroot->left) - getHeight(subroot->right);
    }

    static int getHeight(const node *subroot) {
        return subroot == nullptr ? -1 : subroot->height;
    }

    static void updHeight(node *subroot) {
        subroot->height = max(getHeight(subroot->left), getHeight(subroot->right)) + 1;
    }


    int end() const {
        return end(root)->val;
    }

    static node *end(node *subroot) {
        assert(subroot!=nullptr);
        if (subroot->right == nullptr)
            return subroot;
        return end(subroot->right);
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
            node *pred = end(subroot->left);
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
