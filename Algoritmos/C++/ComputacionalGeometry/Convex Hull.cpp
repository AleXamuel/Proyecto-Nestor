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
