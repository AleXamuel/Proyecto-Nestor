//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=73&page=show_problem&problem=1197

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct pt {
    double x, y;
    bool operator == (pt const& t) const {
        return x == t.x && y == t.y;
    }
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    a = st;
}

class PolygonIntersection {
private:
    // Producto punto de dos vectores
    static double dotProduct(const pt& a, const pt& b) {
        return a.x * b.x + a.y * b.y;
    }
    
    // Obtener el vector normal de un lado
    static pt getNormal(const pt& edge) {
        return pt{-edge.y, edge.x};
    }
    
    // Proyectar un polígono sobre un eje
    static void projectPolygon(const std::vector<pt>& vertices, const pt& axis, double& min, double& max) {
        min = dotProduct(vertices[0], axis);
        max = min;
        
        for (size_t i = 1; i < vertices.size(); i++) {
            double projection = dotProduct(vertices[i], axis);
            if (projection < min) min = projection;
            if (projection > max) max = projection;
        }
    }

public:
    static bool doPolygonsIntersect(const std::vector<pt>& poly1, const std::vector<pt>& poly2) {
        // Verificar ejes de poly1
        for (size_t i = 0; i < poly1.size(); i++) {
            size_t next = (i + 1) % poly1.size();
            pt edge = {
                poly1[next].x - poly1[i].x,
                poly1[next].y - poly1[i].y
            };
            pt normal = getNormal(edge);
            
            // Normalizar el eje
            double length = sqrt(normal.x * normal.x + normal.y * normal.y);
            normal.x /= length;
            normal.y /= length;
            
            // Proyectar ambos polígonos sobre el eje
            double min1, max1, min2, max2;
            projectPolygon(poly1, normal, min1, max1);
            projectPolygon(poly2, normal, min2, max2);
            
            // Si hay un hueco entre las proyecciones, no hay intersección
            if (max1 < min2 || max2 < min1) {
                return false;
            }
        }
        
        // Verificar ejes de poly2
        for (size_t i = 0; i < poly2.size(); i++) {
            size_t next = (i + 1) % poly2.size();
            pt edge = {
                poly2[next].x - poly2[i].x,
                poly2[next].y - poly2[i].y
            };
            pt normal = getNormal(edge);
            
            double length = sqrt(normal.x * normal.x + normal.y * normal.y);
            normal.x /= length;
            normal.y /= length;
            
            double min1, max1, min2, max2;
            projectPolygon(poly1, normal, min1, max1);
            projectPolygon(poly2, normal, min2, max2);
            
            if (max1 < min2 || max2 < min1) {
                return false;
            }
        }
        
        return true; // No se encontró eje separador
    }
};


int main() {
    while (true) {
        int M, C;
        cin >> M >> C;
        if (M == 0 && C == 0) break;

        vector<pt> pointsMaj(M), pointsClev(C);
        for (int i = 0; i < M; i++) {
            cin >> pointsMaj[i].x >> pointsMaj[i].y;
        }
        for (int i = 0; i < C; i++) {
            cin >> pointsClev[i].x >> pointsClev[i].y;
        }

        convex_hull(pointsMaj);
        convex_hull(pointsClev);

        cout << (PolygonIntersection::doPolygonsIntersect(pointsMaj, pointsClev) ? "No" : "Yes") << endl;
        
    }
    return 0;
}
