//https://cses.fi/alon/task/1143
using namespace std;
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <numeric>
#define fori(i, k, n) for (int i = k; i < n; i++)
#define ln "\n"
#define MAXN 200001

int n, t[4 * MAXN];
int A[MAXN];

void build(int a[], int v = 1, int tl = 0, int tr = n - 1)
{
    if (tl == tr)
        t[v] = a[tl];
    else
    {
        int tm = (tl + tr) >> 1;
        build(a, v << 1, tl, tm);
        build(a, (v << 1) + 1, tm + 1, tr);
        t[v] = max(t[v << 1], t[(v << 1) + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
        t[v] = new_val;
    else
    {
        int tm = (tl + tr) >> 1;
        if (pos <= tm)
            update(v << 1, tl, tm, pos, new_val);
        else
            update((v << 1) + 1, tm + 1, tr, pos, new_val);
        t[v] = max(t[v << 1], t[(v << 1) + 1]);
    }
}

int dfs(int q, int v, int l, int r)
{
    if (l == r)
    {
        update(1, 0, n - 1, l, t[v] - q);
        return l + 1;
    }
    int left = v << 1;
    int right = (v << 1) + 1;
    int mid = (l + r) >> 1;
    if (t[left] >= q)
        return dfs(q, left, l, mid);
    return dfs(q, right, mid + 1, r);
}

void solve()
{
    int m;
    cin >> n >> m;
    fori(i, 0, n)
            cin >>
        A[i];
    build(A);
    while (m--)
    {
        int val;
        cin >> val;
        if (t[1] < val)
            cout << 0;
        else
            cout << dfs(val, 1, 0, n - 1);
        cout << " ";
    }
    cout << ln;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
