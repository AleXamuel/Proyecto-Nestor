//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=870
import java.util.*;
import java.io.*;

public class NumberMaze {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer st;
		int T = Integer.parseInt(in.readLine());
		for (int i = 0; i < T; i++) {
			int n = Integer.parseInt(in.readLine());
			int m = Integer.parseInt(in.readLine());
			int[][] grid = new int[n][m];
			for (int j = 0; j < n; j++) {
				st = new StringTokenizer(in.readLine());
				for (int k = 0; k < m; k++)
					grid[j][k] = Integer.parseInt(st.nextToken());
			}
			out.println(dijkstra(grid, n, m));
		}
		out.flush();

	}

	static int dijkstra(int[][] M, int n, int m) {
		int[][] d = new int[n][m];
		for (int[] i : d)
			Arrays.fill(i, Integer.MAX_VALUE);
		boolean[][] visited = new boolean[n][m];
		d[0][0] = M[0][0];
		TreeSet<Edge> Q = new TreeSet<>();
		Q.add(new Edge(new int[] { 0, 0 }, M[0][0]));
		while (!Q.isEmpty()) {
			Edge e = Q.pollFirst();
			int x = e.vertex[0];
			int y = e.vertex[1];
			if (visited[x][y])
				continue;
			visited[x][y] = true;
			if (x - 1 >= 0 && !visited[x - 1][y] && d[x][y] + M[x - 1][y] < d[x - 1][y]) {
				d[x - 1][y] = d[x][y] + M[x - 1][y];
				Q.add(new Edge(new int[] { x - 1, y }, d[x - 1][y]));
			}
			if (x + 1 < n && !visited[x + 1][y] && d[x][y] + M[x + 1][y] < d[x + 1][y]) {
				d[x + 1][y] = d[x][y] + M[x + 1][y];
				Q.add(new Edge(new int[] { x + 1, y }, d[x + 1][y]));
			}
			if (y - 1 >= 0 && !visited[x][y - 1] && d[x][y] + M[x][y - 1] < d[x][y - 1]) {
				d[x][y - 1] = d[x][y] + M[x][y - 1];
				Q.add(new Edge(new int[] { x, y - 1 }, d[x][y - 1]));
			}
			if (y + 1 < m && !visited[x][y + 1] && d[x][y] + M[x][y + 1] < d[x][y + 1]) {
				d[x][y + 1] = d[x][y] + M[x][y + 1];
				Q.add(new Edge(new int[] { x, y + 1 }, d[x][y + 1]));
			}
		}
		return d[n - 1][m - 1];

	}

	static class Edge implements Comparable<Edge> {
		int[] vertex;
		int weight;

		Edge(int[] v, int w) {
			this.vertex = v;
			this.weight = w;
		}

		public int compareTo(Edge o) {
			if (weight < o.weight)
				return -1;
			if (weight > o.weight)
				return 1;
			if (vertex[0] == o.vertex[0])
				return vertex[1] - o.vertex[1];
			return vertex[0] - o.vertex[0];
		}
	}

}
