#https://leetcode.com/problems/check-if-it-is-a-straight-line/?envType=problem-list-v2&envId=geometry
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        def collinear(p1, p2, p3):
            x1, y1 = p1
            x2, y2 = p2
            x3, y3 = p3

            cross_product = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)
            return cross_product == 0
        res = True
        n = len(coordinates)
        for i in range(n - 2):
            res = res and collinear(coordinates[i], coordinates[i + 1], coordinates[i + 2])
        return res
