//https://open.kattis.com/problems/jabuke
#include <bits/stdc++.h>
using namespace std;
#define ll long long

double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
}

bool isPointInTriangle(pair<double, double> A, pair<double, double> B, pair<double, double> C, pair<double, double> P) {
    double A_area = triangleArea(A.first, A.second, B.first, B.second, C.first, C.second);
    double A_area1 = triangleArea(P.first, P.second, B.first, B.second, C.first, C.second);
    double A_area2 = triangleArea(A.first, A.second, P.first, P.second, C.first, C.second);
    double A_area3 = triangleArea(A.first, A.second, B.first, B.second, P.first, P.second);

    return A_area == (A_area1 + A_area2 + A_area3);
}

void solve() {
    pair<double, double> A, B, C, P;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;

    int n;
    cin >> n;

    int cnt = 0;
    while (n--) {
        cin >> P.first >> P.second;
        if (isPointInTriangle(A, B, C, P))
            cnt++;
    }
    cout << fixed << setprecision(1) << triangleArea(A.first, A.second, B.first, B.second, C.first, C.second) << endl;
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
