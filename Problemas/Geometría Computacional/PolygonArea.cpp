//https://cses.fi/problemset/task/2191
using namespace std;
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <numeric>
#define PI acos(-1)
#define toRadians(angle) PI *angle / 180
#define toDegree(angle) (180 * angle) / PI
#define fori(i, k, n) for (int i = k; i < (n); i++)
#define MAXN 200000
#define ln "\n"

struct point
{
    long long x, y;
    point() {}
    point(long long x, long long y) : x(x), y(y) {}
};

long long area(const vector<point> &p, int n)
{
    long long area = 0;
    for (long long i = 0; i < n; i++)
        area += (p[i].x * p[(i + 1) % n].y - p[(i + 1) % n].x * p[i].y);
    return abs(area);
}

void solve()
{
    int n;
    cin >> n;
    vector<point> p(n);
    fori(i, 0, n)
            cin >>
        p[i].x >> p[i].y;
    cout << area(p, n) << ln;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
