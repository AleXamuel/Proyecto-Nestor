#https://leetcode.com/problems/surface-area-of-3d-shapes/?envType=problem-list-v2&envId=geometry&difficulty=EASY
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        res = 0

        for r in range(n):
            for c in range(m):
                if grid[r][c] != 0:
                    #formula:
                    # A = 2*(bl + lh + hb)
                    res += 2*(grid[r][c] + grid[r][c] + 1)
                # Arriba
                if r > 0:
                    res -= min(grid[r][c], grid[r - 1][c])
                # Abajo
                if r < n - 1:
                    res -= min(grid[r][c], grid[r + 1][c])
                # Izquierda
                if c > 0:
                    res -= min(grid[r][c], grid[r][c - 1])
                # Derecha
                if c < m - 1:
                    res -= min(grid[r][c], grid[r][c + 1])
        return res
