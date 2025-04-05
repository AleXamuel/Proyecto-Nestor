//https://vjudge.net/problem/SPOJ-SHOP
import java.io.*;
import java.util.*;

public class Main {

	static int n;
	static int m;
	static char[][] grid;
	static int[][] d;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		PrintWriter out = new PrintWriter(System.out);
		boolean cond = true;
		while (true) {
			if (cond)
				cond = false;
			else
				in.readLine();
			st = new StringTokenizer(in.readLine());
			m = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			if (n == 0 && m == 0)
				break;
			grid = new char[n][m];
			d = new int[n][m];
			int[] s = new int[2];
			int[] t = new int[2];
			for (int i = 0; i < n; i++) {
				grid[i] = in.readLine().toCharArray();
				for (int j = 0; j < m; j++)
					if (grid[i][j] == 'S') {
						s[0] = i;
						s[1] = j;
					} else if (grid[i][j] == 'D') {
						t[0] = i;
						t[1] = j;
					}
				Arrays.fill(d[i], Integer.MAX_VALUE);
			}
			out.println(dijkstra(s, t));
		}
		out.close();
	}

	static int dijkstra(int[] s, int[] t) {
		TreeSet<int[]> Q = new TreeSet<>((e1, e2) -> {
			for (int k = 0; k < 3; k++) {
				if (e1[k] < e2[k])
					return -1;
				if (e1[k] > e2[k])
					return 1;
			}
			return 0;
		});
		d[s[0]][s[1]] = 0;
		boolean[][] visited = new boolean[n][m];
		Q.add(new int[] { 0, s[0], s[1] });
		while (!Q.isEmpty()) {
			int[] e = Q.pollFirst();
			int x = e[1];
			int y = e[2];
			if (visited[x][y])
				continue;
			visited[x][y] = true;
			if (x - 1 >= 0 && !visited[x - 1][y]) {
				char c = grid[x - 1][y];
				if (Character.isDigit(c)) {
					int val = Integer.parseInt(String.valueOf(c));
					if (d[x][y] + val < d[x - 1][y]) {
						d[x - 1][y] = d[x][y] + val;
						Q.add(new int[] { d[x][y] + val, x - 1, y });
					}
				}
				if (c == 'D' && d[x][y] < d[x - 1][y])
					d[x - 1][y] = d[x][y];
			}
			if (x + 1 < n && !visited[x + 1][y]) {
				char c = grid[x + 1][y];
				if (Character.isDigit(c)) {
					int val = Integer.parseInt(String.valueOf(c));
					if (d[x][y] + val < d[x + 1][y]) {
						d[x + 1][y] = d[x][y] + val;
						Q.add(new int[] { d[x][y] + val, x + 1, y });
					}
				}
				if (c == 'D' && d[x][y] < d[x + 1][y])
					d[x + 1][y] = d[x][y];
			}
			if (y - 1 >= 0 && !visited[x][y - 1]) {
				char c = grid[x][y - 1];
				if (Character.isDigit(c)) {
					int val = Integer.parseInt(String.valueOf(c));
					if (d[x][y] + val < d[x][y - 1]) {
						d[x][y - 1] = d[x][y] + val;
						Q.add(new int[] { d[x][y] + val, x, y - 1 });
					}
				}
				if (c == 'D' && d[x][y] < d[x][y - 1])
					d[x][y - 1] = d[x][y];
			}
			if (y + 1 < m && !visited[x][y + 1]) {
				char c = grid[x][y + 1];
				if (Character.isDigit(c)) {
					int val = Integer.parseInt(String.valueOf(c));
					if (d[x][y] + val < d[x][y + 1]) {
						d[x][y + 1] = d[x][y] + val;
						Q.add(new int[] { d[x][y] + val, x, y + 1 });
					}
				}
				if (c == 'D' && d[x][y] < d[x][y + 1])
					d[x][y + 1] = d[x][y];

			}
		}
		return d[t[0]][t[1]];
	}
}
