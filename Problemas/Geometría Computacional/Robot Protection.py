class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __getitem__(self, index):
        return [self.x, self.y][index]

def cross_product(p1, p2, p3):
    x1, y1 = p1
    x2, y2 = p2
    x3, y3 = p3
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)

def convex_hull(points):
    n = len(points)
    if n <= 2:
        return points

    points.sort(key=lambda p: (p.x, p.y))
    lower_hull = []
    upper_hull = []

    for p in points:
        while len(lower_hull) >= 2 and cross_product(lower_hull[-2], lower_hull[-1], p) <= 0:
            lower_hull.pop()
        lower_hull.append(p)

    for p in reversed(points):
        while len(upper_hull) >= 2 and cross_product(upper_hull[-2], upper_hull[-1], p) <= 0:
            upper_hull.pop()
        upper_hull.append(p)

    lower_hull.pop()
    upper_hull.pop()
    return lower_hull + upper_hull

def polygon_area(points):
    area = 0
    for i in range(len(points)):
        j = (i + 1) % len(points)
        area += points[i][0] * points[j][1] - points[j][0] * points[i][1]
    return abs(area) // 2

while True:
    n = int(input())
    if n == 0:
        break
    points = []
    for _ in range(n):
        x, y = map(int, input().split())
        points.append(Point(x, y))
    hull = convex_hull(points)
    area = polygon_area(hull)
    print(float(area))
