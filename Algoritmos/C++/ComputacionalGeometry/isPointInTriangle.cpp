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
