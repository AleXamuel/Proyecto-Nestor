//https://open.kattis.com/problems/goatrope
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Función para calcular la distancia de un punto a un segmento de línea
double distance_to_segment(double xp, double yp, double x1, double y1, double x2, double y2) {
    double A = xp - x1;
    double B = yp - y1;
    double C = x2 - x1;
    double D = y2 - y1;

    double dot = A * C + B * D;
    double len_sq = C * C + D * D;
    double param = -1;

    if (len_sq != 0)
        param = dot / len_sq;

    double xx, yy;

    if (param < 0) {
        xx = x1;
        yy = y1;
    } else if (param > 1) {
        xx = x2;
        yy = y2;
    } else {
        xx = x1 + param * C;
        yy = y1 + param * D;
    }

    return distance(xp, yp, xx, yy);
}

void solve() {
    int x0, y0, x1, y1, x2, y2;
    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

    // Asegurarse de que x1 < x2 y y1 < y2
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);

    // Distancia a los lados del rectángulo
    double dist_left = distance_to_segment(x0, y0, x1, y1, x1, y2);   // Lado izquierdo
    double dist_right = distance_to_segment(x0, y0, x2, y1, x2, y2);  // Lado derecho
    double dist_bottom = distance_to_segment(x0, y0, x1, y1, x2, y1); // Lado inferior
    double dist_top = distance_to_segment(x0, y0, x1, y2, x2, y2);    // Lado superior

    // Distancia a las esquinas del rectángulo
    double dist_corner1 = distance(x0, y0, x1, y1); // Esquina inferior izquierda
    double dist_corner2 = distance(x0, y0, x1, y2); // Esquina superior izquierda
    double dist_corner3 = distance(x0, y0, x2, y1); // Esquina inferior derecha
    double dist_corner4 = distance(x0, y0, x2, y2); // Esquina superior derecha

    double min_dist = min({dist_left, dist_right, dist_bottom, dist_top, dist_corner1, dist_corner2, dist_corner3, dist_corner4});
  
    cout << fixed << setprecision(6) << min_dist << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
