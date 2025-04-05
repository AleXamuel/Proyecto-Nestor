#https://leetcode.com/problems/minimum-time-visiting-all-points/?envType=problem-list-v2&envId=geometry&difficulty=EASY
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        total = 0
        n = len(points)
        for i in range(1, n):
            x1, y1 = points[i - 1]
            x2, y2 = points[i]         

            dx = abs(x2 - x1)
            dy = abs(y2 - y1)

            if dx == dy:
                total += dx
            else:
                total += max(dx, dy)
        return total 
