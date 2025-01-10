struct Point
{
    double x, y;

    Point operator+(const Point &o) const { return {x + o.x, y + o.y}; }
    Point operator-(const Point &o) const { return {x - o.x, y - o.y}; }
    double operator*(const Point &o) const { return x * o.x + y * o.y; }
    double operator^(const Point &o) const { return x * o.y - y * o.x; }
};

Point operator*(double k, const Point &p) { return {k * p.x, k * p.y}; }

istream &operator>>(istream &is, Point &p)
{
    return is >> p.x >> p.y;
}

ostream &operator<<(ostream &os, const Point &p)
{
    return os << "(" << p.x << "," << p.y << ")";
}
