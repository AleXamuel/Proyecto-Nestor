struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

void insert(Node *&root, int val) {
    if (!root) {
        root = new Node(val);
        return;
    }
    if (val < root->val)
        insert(root->left, val);
    else
        insert(root->right, val);
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
