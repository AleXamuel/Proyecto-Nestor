struct Point {
    long long x, y;
    Point() {}
    Point(long long _x, long long _y) : x(_x), y(_y) {}
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    long long cross(const Point& p) const { return x * p.y - y * p.x; }
    long long cross(const Point& a, const Point& b) const { return (a - *this).cross(b - *this); }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};
struct segment {
    Point a,b;
};


int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(long long a, long long b, long long c, long long d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const Point& a, const Point& b, const Point& c, const Point& d) {
    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}
