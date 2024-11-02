#https://leetcode.com/problems/largest-triangle-area/?envType=problem-list-v2&envId=geometry

#first solution
from itertools import combinations

class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        max_area = 0

        for p1, p2, p3 in combinations(points, 3):
            x1, y1 = p1
            x2, y2 = p2
            x3, y3 = p3

            area = abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))/2.0
            max_area = max(max_area, area)
        
        return max_area


#second solution
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        # max_area = 0

        # for (x1, y1), (x2, y2), (x3, y3) in combinations(points, 3):
        #     area = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2
        #     max_area = max(max_area, area)
        
        # return max_area

        def area(x1, y1, x2, y2, x3, y3):
            return abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2

        # Function to compute the convex hull
        def convex_hull(points):
            points = sorted(points)  # Sort the points lexicographically
            # Build the lower hull
            lower = []
            for p in points:
                while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
                    lower.pop()
                lower.append(p)
            # Build the upper hull
            upper = []
            for p in reversed(points):
                while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
                    upper.pop()
                upper.append(p)
            return lower[:-1] + upper[:-1]  # Remove the last point because it's repeated

        # Cross product to determine the turn direction
        def cross(o, a, b):
            return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

        hull = convex_hull(points)
        max_area = 0
        
        # Iterate through each combination of points in the convex hull
        for i in range(len(hull)):
            for j in range(i + 1, len(hull)):
                for k in range(j + 1, len(hull)):
                    max_area = max(max_area, area(hull[i][0], hull[i][1], 
                                                   hull[j][0], hull[j][1], 
                                                   hull[k][0], hull[k][1]))
        
        return max_area
