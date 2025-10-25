//https://open.kattis.com/problems/cookiecutter

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rfor(i, n, k) for(int i = n; i >= k; i--)
#define all(v) (v).begin(), (v).end()
#define ln "\n"
#define pb push_back

struct Point {
    double x, y;
};
//Shoelace formula
double polygonArea(vector<Point>& vertices) {
    int n = vertices.size();
    if (n < 3)
        return 0.0;

    double area = 0.0;

    for (int i = 0; i < n; i++) {
        Point p1 = vertices[i];
        Point p2 = vertices[(i + 1) % n];
        area += (p1.x * p2.y) - (p2.x * p1.y);
    }

    return abs(area) / 2.0;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> A(n);
    For(i, 0, n)
        cin >> A[i].x >> A[i].y;

    int target;
    cin >> target;
    
    double area = polygonArea(A);
  // area escalada = area original * k^2
    double k = sqrt(target / area); 

    //escalar el poligono
    For(i, 0, n) {
        A[i].x *= k;
        A[i].y *= k;
    }
    double x_min = A[0].x;
    double y_min = A[0].y;
    For(i, 1, n) {
        x_min = min(x_min, A[i].x);
        y_min = min(y_min, A[i].y);
    }

    For(i, 0, n) {
        A[i].x -= x_min;
        A[i].y -= y_min;
    }

    cout << fixed << setprecision(10);
    For(i, 0, n) {
        cout << A[i].x << " " << A[i].y << ln;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
