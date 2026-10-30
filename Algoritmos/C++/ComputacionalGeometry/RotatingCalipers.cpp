struct pt {
    ll x, y;

    pt operator+(const pt &p) const {
        return {x + p.x, y + p.y};
    }

    pt operator-(const pt &p) const {
        return {x - p.x, y - p.y};
    }

    ll operator^(const pt &o) const {
        return x * o.y - y * o.x;
    }
};

int sign(ll x) {
    if (x < 0) return -1;
    if (x == 0) return 0;
    return 1;
}

vector<Pair > all_anti_podal(int n, vector<pt> &p) {
    vector<Pair > result;
    if (n <= 10) {
        For(i, 0, n)
            For(j, i+1, n)
                result.emplace_back(i, j);
        return result;
    }
    auto nx = [&](int i) {
        return (i + 1) % n;
    };
    auto pv = [&](int i) {
        return (i - 1 + n) % n;
    };
    // parallel edges should't be visited twice
    vector<bool> vis(n, false);
    int p2 = 0; // two "pointers"
    for (int p1 = 0; p1 < n; p1++) {
        // the edge that we are going to consider in this iteration
        // the datatype is Point, but it acts as a vector
        pt base = p[nx(p1)] - p[p1];

        // the last condition makes sure that the cross products don't have the same sign
        while (p2 == p1 || p2 == nx(p1) || sign(base ^ (p[nx(p2)] - p[p2])) ==
               sign(base ^ (p[p2] - p[pv(p2)]))) {
            p2 = nx(p2);
        }

        if (vis[p1])
            continue;
        vis[p1] = true;

        result.emplace_back(p1, p2);
        result.emplace_back(nx(p1), p2);

        // if both edges from p1 and p2 are parallel to each other
        if (sign(base ^ (p[nx(p2)] - p[p2])) == 0) {
            result.emplace_back(p1, nx(p2));
            result.emplace_back(nx(p1), nx(p2));
            vis[p2] = true;
        }
    }

    return result;
}
