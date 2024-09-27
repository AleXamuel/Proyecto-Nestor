//LeetCode994
import java.util.*;

public class RottingOranges {

	static int orangesRotting(int[][] grid) {
		int n = grid.length;
		int m = grid[0].length;
		boolean[][] visited = new boolean[n][m];
		int[][] d = new int[n][m];
		Queue<int[]> Q = new LinkedList<>();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (grid[i][j] == 2) {
					Q.add(new int[] { i, j });
					d[i][j] = 0;
					visited[i][j] = true;
				}
		while (!Q.isEmpty()) {
			int[] e = Q.poll();
			int r = e[0];
			int c = e[1];
			if (r - 1 >= 0 && !visited[r - 1][c] && grid[r - 1][c] == 1) {
				visited[r - 1][c] = true;
				d[r - 1][c] = d[r][c] + 1;
				Q.add(new int[] { r - 1, c });
			}
			if (r + 1 < n && !visited[r + 1][c] && grid[r + 1][c] == 1) {
				visited[r + 1][c] = true;
				d[r + 1][c] = d[r][c] + 1;
				Q.add(new int[] { r + 1, c });
			}
			if (c - 1 >= 0 && !visited[r][c - 1] && grid[r][c - 1] == 1) {
				visited[r][c - 1] = true;
				d[r][c - 1] = d[r][c] + 1;
				Q.add(new int[] { r, c - 1 });
			}

			if (c + 1 < m && !visited[r][c + 1] && grid[r][c + 1] == 1) {
				visited[r][c + 1] = true;
				d[r][c + 1] = d[r][c] + 1;
				Q.add(new int[] { r, c + 1 });
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!visited[i][j] && grid[i][j] == 1)
					return -1;
		int ans = 0;
		for (int[] i : d)
			for (int j : i)
				ans = Math.max(ans, j);
		return ans;

	}

}
