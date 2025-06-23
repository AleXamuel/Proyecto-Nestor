const int nmax = 1e5 + 5;
ll p[2] = {1200259153, 1202773163}, bs[2][nmax];
int base = 27;
struct shash {
    ll h[2]{0, 0};
    int sz = 0;

    void push_back(int c) {
        h[0] = (h[0] * base + c) % p[0];
        h[1] = (h[1] * base + c) % p[1];
        sz++;
    }

    void push_front(int c) {
        h[0] = (h[0] + c * bs[0][sz]) % p[0];
        h[1] = (h[1] + c * bs[1][sz]) % p[1];
        sz++;
    }

    void pop_front(int c) {
        h[0] = (((h[0] - c * bs[0][sz - 1]) % p[0]) + p[0]) % p[0];
        h[1] = (((h[1] - c * bs[1][sz - 1]) % p[1]) + p[1]) % p[1];
        sz--;
    }

    bool operator ==(const shash &o) const {
        return h[0] == o.h[0] && h[1] == o.h[1];
    }

    void clear() {
        h[0] = 0, h[1] = 0;
        sz = 0;
    }

    Pair get() {
        return {h[0], h[1]};
    }
};
