//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=73&page=show_problem&problem=1197
#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    
    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y};
    }
};

int orientation(const Point& a, const Point& b, const Point& c) {
    double cross = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
    return (cross < 0) ? -1 : (cross > 0) ? 1 : 0;
}


vector<Point> convexHull(vector<Point> points, bool includeCollinear = false) {
    if (points.size() <= 1) return points;
    
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    
    vector<Point> hull;
    for (int phase = 0; phase < 2; ++phase) {
        auto start = hull.size();
        for (const auto& p : points) {
            while (hull.size() >= start + 2) {
                auto a = hull[hull.size()-2];
                auto b = hull.back();
                int o = orientation(a, b, p);
                if (o < 0 || (!includeCollinear && o == 0)) break;
                hull.pop_back();
            }
            hull.push_back(p);
        }
        hull.pop_back();
        reverse(points.begin(), points.end());
    }
    
    if (hull.size() == 2 && hull[0] == hull[1]) hull.pop_back();
    return hull;
}

class PolygonIntersectionChecker {
public:
    static bool check(const vector<Point>& poly1, const vector<Point>& poly2) {
        return checkSeparatingAxis(poly1, poly2) && checkSeparatingAxis(poly2, poly1);
    }

private:
    static bool checkSeparatingAxis(const vector<Point>& poly1, const vector<Point>& poly2) {
        for (size_t i = 0; i < poly1.size(); ++i) {
            Point edge = poly1[(i+1)%poly1.size()] - poly1[i];
            Point normal = {-edge.y, edge.x};
            
            // Normalizar el vector normal
            double len = sqrt(normal.x*normal.x + normal.y*normal.y);
            normal.x /= len;
            normal.y /= len;
            
            auto [min1, max1] = projectPolygon(poly1, normal);
            auto [min2, max2] = projectPolygon(poly2, normal);
            
            if (max1 < min2 || max2 < min1) return false;
        }
        return true;
    }
    
    static pair<double, double> projectPolygon(const vector<Point>& poly, const Point& axis) {
        double min_proj = axis.x*poly[0].x + axis.y*poly[0].y;
        double max_proj = min_proj;
        
        for (const auto& p : poly) {
            double proj = axis.x*p.x + axis.y*p.y;
            min_proj = min(min_proj, proj);
            max_proj = max(max_proj, proj);
        }
        return {min_proj, max_proj};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (true) {
        int M, C;
        cin >> M >> C;
        if (M == 0 && C == 0) break;

        vector<Point> pointsM(M), pointsC(C);
        for (auto& p : pointsM) cin >> p.x >> p.y;
        for (auto& p : pointsC) cin >> p.x >> p.y;
        
        auto hullM = convexHull(pointsM);
        auto hullC = convexHull(pointsC);
        
        cout << (PolygonIntersectionChecker::check(hullM, hullC) ? "No" : "Yes") << endl;
    }
    
    return 0;
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
    static double dotProduct(const pt& a, const pt& b) {
        return a.x * b.x + a.y * b.y;
    }
    
    static pt getNormal(const pt& edge) {
        return pt{-edge.y, edge.x};
    }
    
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
        for (size_t i = 0; i < poly1.size(); i++) {
            size_t next = (i + 1) % poly1.size();
            pt edge = {
                poly1[next].x - poly1[i].x,
                poly1[next].y - poly1[i].y
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
        
        return true; 
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
