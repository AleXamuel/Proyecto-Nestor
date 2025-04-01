struct Point{
    long long x, y;
    long long operator^(const Point &o) const { return x * o.y - y * o.x; }
};
istream &operator>>(istream &is, Point &p){
    return is >> p.x >> p.y;
}
long long area(vector<Point> &A, int n){
    long long ans = 0;
    fori(i, 0, n - 1) {
        Point p1 = A[i];
        Point p2 = A[i + 1];
        long long cross = (p1 ^ p2);
        ans += cross;
    }
    return abs(ans + (A[n - 1] ^ A[0]));
}
