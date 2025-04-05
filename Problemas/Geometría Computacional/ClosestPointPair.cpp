//https://www.spoj.com/problems/CLOPPAIR/en/
using namespace std;
#include <bits/stdc++.h>

#define all(A) A.begin(),A.end()
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define ll long long
#define ull unsigned long long


struct pt {
    ll x, y, id;
};

struct cmp_x {
    bool operator()(const pt &a, const pt &b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y {
    bool operator()(const pt &a, const pt &b) const {
        return a.y < b.y;
    }
};

istream &operator>>(istream &is, pt &p) {
    return is >> p.x >> p.y;
}


ostream &operator<<(ostream &os, const pt &p) {
    return os << "(" << p.x << "," << p.y << ")";
}

int n;
vector<pt> t;

vector<pt> a;

double mindist;
pair<ll, ll> best_pair;

void upd_ans(const pt &a, const pt &b) {
    double dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    if (dist < mindist) {
        mindist = dist;
        best_pair = {a.id, b.id};
    }
}


void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                upd_ans(a[i], a[j]);
            }
        }
        sort(a.begin() + l, a.begin() + r, cmp_y());
        return;
    }

    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec(l, m);
    rec(m, r);

    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmp_y());
    copy(t.begin(), t.begin() + r - l, a.begin() + l);
    int tsz = 0;
    for (int i = l; i < r; ++i) {
        if (abs(a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
    }
}

void solve() {
    cin >> n;
    a.assign(n, {});
    fori(i, 0, n) {
        cin >> a[i];
        a[i].id = i;
    }
    t.resize(n);
    sort(a.begin(), a.end(), cmp_x());
    mindist = 1E20;
    rec(0, n);
    ll x1 = best_pair.first;
    ll x2 = best_pair.second;
    if (x1 < x2)
        cout << x1 << " " << x2 << " " << fixed << setprecision(6) << mindist << ln;
    else
        cout << x2 << " " << x1 << " " << fixed << setprecision(6) << mindist << ln;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
