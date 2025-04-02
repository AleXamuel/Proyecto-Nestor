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

//llamar al metodo: PolygonIntersectionChecker::check(Poly1, Poly2)
