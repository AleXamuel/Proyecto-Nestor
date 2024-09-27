import java.util.*;
import java.io.*;

public class CoastLength {
	static int[][] grid;
	static int n;
	static int m;

	public static void main(String[] args) {
		Input in = new Input(System.in);
		n = in.nextInt();
		m = in.nextInt();
		grid = new int[n + 2][m + 2];
		for (int i = 1; i <= n; i++) {
			String row = in.next();
			int c = 0;
			for (int j = 1; j <= m; j++) {
				grid[i][j] = row.charAt(c) - '0';
				c++;
			}

		}
		System.out.println(bfs());

	}

	static int bfs() {
		int ans = 0;
		Queue<int[]> Q = new LinkedList<>();
		Q.add(new int[] { 0, 0 });
		grid[0][0] = -1;
		while (!Q.isEmpty()) {
			int[] cell = Q.poll();
			int r = cell[0];
			int c = cell[1];
			if (r - 1 >= 0) {
				if (grid[r - 1][c] == 0) {
					grid[r - 1][c] = -1;
					Q.add(new int[] { r - 1, c });
				} else if (grid[r - 1][c] == 1)
					ans++;
			}
			if (r + 1 <= n + 1) {
				if (grid[r + 1][c] == 0) {
					grid[r + 1][c] = -1;
					Q.add(new int[] { r + 1, c });
				} else if (grid[r + 1][c] == 1)
					ans++;
			}
			if (c - 1 >= 0) {
				if (grid[r][c - 1] == 0) {
					grid[r][c - 1] = -1;
					Q.add(new int[] { r, c - 1 });
				} else if (grid[r][c - 1] == 1)
					ans++;
			}
			if (c + 1 <= m + 1) {
				if (grid[r][c + 1] == 0) {
					grid[r][c + 1] = -1;
					Q.add(new int[] { r, c + 1 });
				} else if (grid[r][c + 1] == 1)
					ans++;
			}
		}
		return ans;
	}

	static class Input {
		BufferedReader br;
		StringTokenizer st;

		public Input(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		public String nextLine() throws Exception {
			return br.readLine();
		}

		public void close() throws IOException {
			br.close();
		}

		public boolean hasNext() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(br.readLine());

			} catch (Exception e) {
				return false;
			}
			return true;
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

	}
}
