// https://www.spoj.com/problems/COUNTISL/en/
import java.io.*;
import java.util.*;

public class HowManyIslands {
	static HashMap<Pair, HashSet<Pair>> adj;

	public static void main(String[] args) {
		Input in = new Input(System.in);
		int t = in.nextInt();
		for (int cases = 0; cases < t; cases++) {
			int n = in.nextInt();
			int m = in.nextInt();
			char[][] matrix = new char[n][m];
			for (int i = 0; i < n; i++)
				matrix[i] = in.next().toCharArray();
			System.out.println(solve(matrix));

		}

	}

	static int solve(char[][] grid) {
		build_Graph(grid);
		int ans = 0;
		HashMap<Pair, Boolean> visited = new HashMap<>();
		for (Pair s : adj.keySet()) {
			if (visited.get(s) == null) {
				ans++;
				bfs(s, visited);
			}
		}
		return ans;
	}

	static void bfs(Pair s, HashMap<Pair, Boolean> visited) {
		Queue<Pair> Q = new LinkedList<>();
		Q.add(s);
		while (!Q.isEmpty()) {
			Pair u = Q.poll();
			for (Pair v : adj.get(u))
				if (visited.get(v) == null) {
					visited.put(v, true);
					Q.add(v);
				}
		}
	}

	static void build_Graph(char[][] grid) {
		int n = grid.length;
		int m = grid[0].length;
		adj = new HashMap<>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '#') {
					Pair p = new Pair(i, j);
					if (j + 1 < m && grid[i][j + 1] == '#')
						addEdge(p, new Pair(i, j + 1));
					if (i + 1 < n && grid[i + 1][j] == '#')
						addEdge(p, new Pair(i + 1, j));
					if (i - 1 > 0 && grid[i - 1][j] == '#')
						addEdge(p, new Pair(i - 1, j));
					if (j - 1 > 0 && grid[i][j - 1] == '#')
						addEdge(p, new Pair(i, j - 1));
					if (i - 1 > 0 && j - 1 > 0 && grid[i - 1][j - 1] == '#')
						addEdge(p, new Pair(i - 1, j - 1));
					if (i - 1 > 0 && j + 1 < m && grid[i - 1][j + 1] == '#')
						addEdge(p, new Pair(i - 1, j + 1));
					if (i + 1 < n && j - 1 > 0 && grid[i + 1][j - 1] == '#')
						addEdge(p, new Pair(i + 1, j - 1));
					if (i + 1 > 0 && j + 1 < m && grid[i + 1][j + 1] == '#')
						addEdge(p, new Pair(i + 1, j + 1));
					if (adj.get(p) == null)
						adj.put(p, new HashSet<>());
				}

			}
		}
	}

	static void addEdge(Pair a, Pair b) {
		if (adj.get(a) == null)
			adj.put(a, new HashSet<>());
		if (adj.get(b) == null)
			adj.put(b, new HashSet<>());
		adj.get(a).add(b);
		adj.get(b).add(a);
	}

	static class Pair {
		int i;
		int j;

		Pair(int i, int j) {
			this.i = i;
			this.j = j;
		}

		public int hashCode() {
			return i + j % 499;
		}

		public boolean equals(Object o) {
			Pair op = (Pair) o;
			return this.i == op.i && this.j == op.j;
		}

		public String toString() {
			return "(" + i + ", " + j + ")";
		}
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
