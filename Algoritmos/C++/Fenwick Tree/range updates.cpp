struct BIT { // this code is 1-indexed
    vector<int> B1, B2;
    int N;
    BIT(int n) {
        N = n;
        B1.assign(n + 1, 0);
        B2.assign(n + 1, 0);
    }
    void add(vector<int> &b, int idx, int x) {
        while (idx <= N) {
            b[idx] += x;
            idx += idx & -idx;
        }
    }
    void range_add(int l, int r, int x) {
        add(B1, l, x);
        add(B1, r + 1, -x);
        add(B2, l, x * (l - 1));
        add(B2, r + 1, -x * r);
    }
    int sum(vector<int>&b,int idx) {
        int total=0;
        while(idx>0) {
            total+=b[idx];
            idx-=idx&-idx;
        }
        return total;
    }
    int prefix_sum(int idx) {
        return sum(B1,idx)*idx-sum(B2,idx);
    }
    int range_sum(int l, int r) {
        return prefix_sum(r)-prefix_sum(l-1);
    }
};
