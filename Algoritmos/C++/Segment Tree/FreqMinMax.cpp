//Compute the Maximum or Minimum of a given segment of an Array and the number of times it appears on that segment.

using namespace std;
#include <bits/stdc++.h>
#define MAXN 100000

int n;
pair<long long, int> t[4 * MAXN];

pair<long long, int> combine(pair<long long, int> a, pair<long long, int> b)
{
    if (a.first < b.first)
        return a;
    if (b.first < a.first)
        return b;
    return {a.first, a.second + b.second};
}

void build(long long a[], int v = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
        t[v] = {a[tl], 1};
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

pair<long long, int> query(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return {INT_MAX, 0};
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        t[v] = {new_val, 1};
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

long long A[MAXN];
