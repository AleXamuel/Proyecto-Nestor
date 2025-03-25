struct trieNode {
    ll value;
    trieNode *arr[2];
};

trieNode *newNode() {
    trieNode *temp = new trieNode;
    temp->value = 0;
    temp->arr[0] = NULL;
    temp->arr[1] = NULL;
    return temp;
}

void insert(trieNode *root, ll pre_xor, ll max_bits) {
    trieNode *temp = root;

    bool val;
    for (ll i = max_bits; i >= 0; i--) {
        val = pre_xor & (1 << i);

        if (temp->arr[val] == NULL) temp->arr[val] = newNode();
        temp = temp->arr[val];
    }
    temp->value = pre_xor;
}

ll query(trieNode *root, ll pre_xor, ll max_bits) {
    trieNode *temp = root;
    bool val;
    for (ll i = max_bits; i >= 0; i--) {
        val = pre_xor & (1 << i);

        if (temp->arr[!val] != NULL) temp = temp->arr[!val];
        else if (temp->arr[val] != NULL) temp = temp->arr[val];
    }
    return pre_xor ^ (temp->value);
}

ll maxSubarrayXOR(vector<ll> &arr, ll n = -1, ll max_val = LONG_MIN) {
    if (n == -1) n = arr.size();
    if (max_val == LONG_MIN) max_val = *max_element(arr.begin(), arr.end());
    ll max_bits = 9;

    trieNode *root = newNode();
    insert(root, 0, max_bits);
    ll res = 0, pre_xor = 0;

    for (ll i = 0; i <n; i++) {
        pre_xor = pre_xor ^arr[i];
        insert(root, pre_xor, max_bits);
        res = max(res, query(root, pre_xor, max_bits));
    }
    return res;
}
