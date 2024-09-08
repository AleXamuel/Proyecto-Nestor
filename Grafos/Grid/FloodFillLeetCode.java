import java.util.*;

public class FloodFillLeetCode {

	static int[][] bfs(int[][] grid, int sr, int sc, int color) {
		if (grid[sr][sc] == color)
			return grid;
		Queue<int[]> Q = new LinkedList<>();
		int n = grid.length;
		int m = grid[0].length;
		int pixel = grid[sr][sc];
		boolean[][] visited = new boolean[n][m];
		grid[sr][sc] = color;
		visited[sr][sc] = true;
		Q.add(new int[] { sr, sc });
		while (!Q.isEmpty()) {
			int[] cell = Q.poll();
			int r = cell[0];
			int c = cell[1];
			if (r - 1 >= 0 && !visited[r - 1][c] && grid[r - 1][c] == pixel) {
				visited[r - 1][c] = true;
				grid[r - 1][c] = color;
				Q.add(new int[] { r - 1, c });
			}
			if (r + 1 < n && !visited[r + 1][c] && grid[r + 1][c] == pixel) {
				visited[r + 1][c] = true;
				grid[r + 1][c] = color;
				Q.add(new int[] { r + 1, c });
			}
			if (c - 1 >= 0 && !visited[r][c - 1] && grid[r][c - 1] == pixel) {
				visited[r][c - 1] = true;
				grid[r][c - 1] = color;
				Q.add(new int[] { r, c - 1 });
			}
			if (c + 1 < m && !visited[r][c + 1] && grid[r][c + 1] == pixel) {
				visited[r][c + 1] = true;
				grid[r][c + 1] = color;
				Q.add(new int[] { r, c + 1 });
			}
		}
		return grid;

	}

}
