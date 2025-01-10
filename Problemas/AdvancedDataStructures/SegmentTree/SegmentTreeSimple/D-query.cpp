//https://www.spoj.com/problems/DQUERY/
using namespace std;
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <utility>
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define MAXN 300001

int n, t[4 * MAXN];
void build(int a[], int v = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
        t[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        t[v] = new_val;
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}


int A[MAXN];
int last[1000005];
void solve()
{
    cin >> n;
    vector<int> arr(n);
    fori(i, 0, n)
            cin >>arr[i];
    fill(A, A + n, 1);
    fill(last, last + 1000005, -1);
    build(A);
    int q;
    cin >> q;
    vector<pair<pair<int, int>, int>> queries(q);
    fori(i, 0, q)
    {
        cin >> queries[i].first.second >> queries[i].first.first;
        queries[i].second = i;
    }
    vector<int> ans(q);
    sort(queries.begin(), queries.end());
    int c = 0;
    fori(i, 0, n)
    {
        int val = arr[i];
        if (last[val] == -1)
            last[val] = i;
        else
        {
            update(1, 0, n - 1, last[val], 0);
            last[val] = i;
        }
        while (queries[c].first.first == i + 1)
        {
            ans[queries[c].second] = query(1, 0, n - 1, queries[c].first.second - 1, i);
            c++;
        }
    }
    for (const auto &i : ans)
        cout << i << ln;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
