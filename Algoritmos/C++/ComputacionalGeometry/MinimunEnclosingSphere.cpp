struct pt {
    double x, y, z;
};

struct Sphere {
    pt c;
    double r;
};

double dist(const pt &a, const pt &b) {
    return sqrt(pow(a.x - b.x, 2)
                + pow(a.y - b.y, 2)
                + pow(a.z - b.z, 2));
}

bool isInside(const Sphere &s, const pt &p) {
    return dist(s.c, p) <= s.r + 1e-10;
}

Sphere sphereFrom(const pt &a, const pt &b) {
    pt c = {
        (a.x + b.x) / 2.0,
        (a.y + b.y) / 2.0,
        (a.z + b.z) / 2.0
    };
    return {c, dist(a, b) / 2.0};
}


Sphere sphereFrom(const pt &a, const pt &b, const pt &c) {
    double bx = b.x - a.x, by = b.y - a.y, bz = b.z - a.z;
    double cx = c.x - a.x, cy = c.y - a.y, cz = c.z - a.z;

    double B = bx * bx + by * by + bz * bz;
    double C = cx * cx + cy * cy + cz * cz;


    double nx = by * cz - bz * cy;
    double ny = bz * cx - bx * cz;
    double nz = bx * cy - by * cx;
    double n2 = nx * nx + ny * ny + nz * nz;


    double ox = (B * (cy * nz - cz * ny) + C * (bz * ny - by * nz)) / (2.0 * n2);
    double oy = (B * (cz * nx - cx * nz) + C * (bx * nz - bz * nx)) / (2.0 * n2);
    double oz = (B * (cx * ny - cy * nx) + C * (by * nx - bx * ny)) / (2.0 * n2);

    pt center = {a.x + ox, a.y + oy, a.z + oz};
    return {center, dist(center, a)};
}

Sphere sphereFrom(const pt &a, const pt &b,
                  const pt &c, const pt &d) {
    double bx = b.x - a.x, by = b.y - a.y, bz = b.z - a.z;
    double cx = c.x - a.x, cy = c.y - a.y, cz = c.z - a.z;
    double dx = d.x - a.x, dy = d.y - a.y, dz = d.z - a.z;

    double B = bx * bx + by * by + bz * bz;
    double C = cx * cx + cy * cy + cz * cz;
    double D = dx * dx + dy * dy + dz * dz;

    double det = bx * (cy * dz - cz * dy)
                 - by * (cx * dz - cz * dx)
                 + bz * (cx * dy - cy * dx);

    if (fabs(det) < 1e-10)
        return sphereFrom(a, b, c);

    double ox = ( B * (cy * dz - cz * dy) - C * (by * dz - bz * dy) + D * (by * cz - bz * cy)) / (2.0 * det);
    double oy = (-B * (cx * dz - cz * dx) + C * (bx * dz - bz * dx) - D * (bx * cz - bz * cx)) / (2.0 * det);
    double oz = ( B * (cx * dy - cy * dx) - C * (bx * dy - by * dx) + D * (bx * cy - by * cx)) / (2.0 * det);

    pt center = {a.x + ox, a.y + oy, a.z + oz};
    return {center, dist(center, a)};
}

bool isValidSphere(const Sphere &s, const vector<pt> &p) {
    for (const pt &i: p)
        if (!isInside(s, i))
            return false;
    return true;
}

Sphere minSphereTrivial(vector<pt> &p) {
    assert(p.size() <= 4);
    if (p.empty()) return {{0, 0, 0}, 0};
    if (p.size() == 1) return {p[0], 0};
    if (p.size() == 2) return sphereFrom(p[0], p[1]);

    for (int i = 0; i < sz(p); i++)
        for (int j = i + 1; j < sz(p); j++) {
            Sphere s = sphereFrom(p[i], p[j]);
            if (isValidSphere(s, p)) return s;
        }

    if (p.size() == 3) return sphereFrom(p[0], p[1], p[2]);


    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            for (int k = j + 1; k < 4; k++) {
                Sphere s = sphereFrom(p[i], p[j], p[k]);
                if (isValidSphere(s, p)) return s;
            }

    return sphereFrom(p[0], p[1], p[2], p[3]);
}

Sphere welzlHelper(vector<pt> &p, vector<pt> r, int n) {
    if (n == 0 || sz(r) == 4)
        return minSphereTrivial(r);

    int idx = rand(0, n-1)
    pt pnt = p[idx];
    swap(p[idx], p[n - 1]);

    Sphere d = welzlHelper(p, r, n - 1);
    if (isInside(d, pnt))
        return d;

    r.push_back(pnt);
    return welzlHelper(p, r, n - 1);
}

Sphere welzl(const vector<pt> &p) {
    vector<pt> pCopy = p;
    shuffle(all(pCopy), mt19937{random_device{}()});
    return welzlHelper(pCopy, {}, sz(p));
}
