#https://leetcode.com/problems/projection-area-of-3d-shapes/description/?envType=problem-list-v2&envId=geometry&difficulty=EASY
class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        
        # Area of the xy-projection
        xy_area = sum(1 for i in range(n) for j in range(n) if grid[i][j] > 0)
        
        # Area of the yz-projection
        yz_area = sum(max(row) for row in grid)
        
        # Area of the zx-projection
        zx_area = sum(max(grid[i][j] for i in range(n)) for j in range(n))
        
        total_area = xy_area + yz_area + zx_area
        return total_area
