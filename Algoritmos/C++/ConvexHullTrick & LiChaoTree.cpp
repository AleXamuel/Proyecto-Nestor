//Template de vectores y puntos
struct pt {
    ll x, y;


    pt operator-(const pt &o) const {
        return {x - o.x, y - o.y};
    }

    ll operator*(const pt &o) const {
        return x * o.x + y * o.y;
    }

    ll operator^(const pt &o) const {
        return x * o.y - y * o.x;
    }
};

//LiChaoTree, se usa para insertar funciones lineales de la forma mx+b en log(n)
//Permite consultar el valor minimo de todas las funciones para un x especifico en log(n)
//Se pueden insertar funciones lineales en cualquier orden y hacer consultas en cualquier orden
//Para usar el LiChaoTree se le pasa el arreglo sobre el cual voy a construir el SegmentTree y hacer las queries
struct LiChaoTree {
    vector<pt> t;
    vector<ll> A;
    int MAX;

    LiChaoTree(const vector<ll> &arr) {
        A = arr;
        MAX = sz(arr);
        t.assign(4 * MAX, {0,LLONG_MAX});
    }

    ll f(pt a, ll x) {
        return a * pt{x, 1};
    }

    void add_line(pt nw, int v, int l, int r) {
        int m = (l + r) / 2;
        bool lef = f(nw, A[l]) < f(t[v], A[l]);
        bool mid = f(nw, A[m]) < f(t[v], A[m]);
        if (mid) {
            swap(t[v], nw);
        }
        if (r - l == 1) {
            return;
        }
        if (lef != mid) {
            add_line(nw, 2 * v, l, m);
        } else {
            add_line(nw, 2 * v + 1, m, r);
        }
    }

    void add(pt cur) {
        add_line(cur, 1, 0, MAX);
    }

    ll get(ll x, int v, int l, int r) {
        int m = (l + r) / 2;
        if (r - l == 1)
            return f(t[v], x);
        if (x < A[m])
            return min(f(t[v], x), get(x, 2 * v, l, m));
        return min(f(t[v], x), get(x, 2 * v + 1, m, r));
    }

    ll get(ll x) {
        return get(x, 1, 0, MAX);
    }
};


//ConvexHull Trick, permite insertar funciones lineales mx+b en O(1) amortizado
//Las inserciones requieren que las rectas se inserten en orden creciente por la pendiente, es decir, m1<=m2<=m3<=...<=mn
//Permite consultar el menor valor de todas las funciones lineales para un x especifico en log(n)
//Las consultas pueden ser en cualquier orden
struct ConvexHullTrick {
    vector<pt> hull, vecs;

    static pt rot90(pt p) {
        return pt(-p.y, p.x);
    }

    void add(ll k, ll b) {
        pt nw = {k, b};
        while (!vecs.empty() && (vecs.back() * (nw - hull.back())) < 0) {
            hull.pop_back();
            vecs.pop_back();
        }
        if (!hull.empty()) {
            vecs.push_back(rot90(nw - hull.back()));
        }
        hull.push_back(nw);
    }

    ll get(ll x) {
        pt query = {x, 1};
        auto it = lower_bound(vecs.begin(), vecs.end(), query, [&](pt a, pt b) {
            return (a ^ b) > 0;
        });
        return query * hull[it - vecs.begin()];
    }
};
