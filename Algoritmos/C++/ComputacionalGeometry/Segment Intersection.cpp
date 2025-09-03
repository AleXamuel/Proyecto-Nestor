struct Point {
    long long x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};
struct segment {
    Point a,b;
};
int ori(Point a, Point b, Point c) {
    long long val = (b.y - a.y) * (c.x - b.x) -
                    (b.x - a.x) * (c.y - b.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool inSeg(Point p, Point q, Point r) {
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

bool inttersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = ori(p1, q1, p2);
    int o2 = ori(p1, q1, q2);
    int o3 = ori(p2, q2, p1);
    int o4 = ori(p2, q2, q1);
    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && inSeg(p1, p2, q1)) return true;
    if (o2 == 0 && inSeg(p1, q2, q1)) return true;
    if (o3 == 0 && inSeg(p2, p1, q2)) return true;
    if (o4 == 0 && inSeg(p2, q1, q2)) return true;
    return false;
}
//if they touch, they touch in the extreme points?
bool bound(Point p1, Point q1, Point p2, Point q2) {
    if (!intersect(p1, q1, p2, q2)) return false;
    if (inSeg(p2, p1, q2) || inSeg(p2, q1, q2))
        return true;
    if (inSeg(p1, p2, q1) || inSeg(p1, q2, q1))
        return true;

    return false;
}
