struct pt {
    ll x, y;


    pt operator-(const pt &o) const {
        return {x - o.x, y - o.y};
    }

    ll operator^(const pt &o) const {
        return x * o.y - y * o.x;
    }
};

ostream &operator<<(ostream &os, const pt &o) {
    return os << "(" << o.x << "," << o.y << ")";
}


ll dist(const pt &a, const pt &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

vector<pt> convex_hull(vector<pt> A) {
    pt p0 = {(ll) 1e9, (ll) 1e9};
    int n = sz(A);
    For(i, 0, n) {
        if (A[i].y < p0.y || (A[i].y == p0.y && A[i].x < p0.x))
            p0 = A[i];
    }

    sort(all(A), [&](const pt &a, const pt &b)-> bool {
        pt u = a - p0;
        pt v = b - p0;
        ll c = u ^ v;
        if (c == 0)
            return dist(a, p0) < dist(b, p0);
        return c > 0;
    });
    int j = -1;
    pt v = A[n - 1] - p0;
    Rfor(i, n-1, 0) {
        pt u = A[i] - p0;
        if ((u ^ v) == 0) {
            j = i;
        } else
            break;
    }
    reverse(A.begin() + j, A.end());
    vector<pt> hull;
    For(i, 0, n) {
        while (sz(hull) >= 2) {
            pt c = A[i];
            pt b = hull.back();
            pt a = hull[sz(hull) - 2];
            pt u = b - a;
            pt v = c - a;
            ll cross = u ^ v;
            if (cross < 0)
                hull.pop_back();
            else
                break;
        }
        hull.push_back(A[i]);
    }
    return hull;
}
