import java.util.*;

public class NumberOfIslandsLeetCode {

	public static void main(String[] args) {
		char[][] grid = { { '1', '1', '0', '0', '0' }, { '1', '1', '0', '0', '0' }, { '0', '0', '1', '0', '0' },
				{ '0', '0', '0', '1', '1' } };
		Solution p = new Solution();
		System.out.println(p.numIslands(grid));

	}

	static class Solution {
		HashMap<Pair, HashSet<Pair>> adj;

		public int numIslands(char[][] grid) {
			return solve(grid);
		}

		int solve(char[][] grid) {
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

		void bfs(Pair s, HashMap<Pair, Boolean> visited) {
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

		void build_Graph(char[][] grid) {
			int n = grid.length;
			int m = grid[0].length;
			adj = new HashMap<>();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (grid[i][j] == '1') {
						Pair p = new Pair(i, j);
						if (j + 1 < m && grid[i][j + 1] == '1')
							addEdge(p, new Pair(i, j + 1));
						if (i + 1 < n && grid[i + 1][j] == '1')
							addEdge(p, new Pair(i + 1, j));
						if (i - 1 > 0 && grid[i - 1][j] == '1')
							addEdge(p, new Pair(i - 1, j));
						if (j - 1 > 0 && grid[i][j - 1] == '1')
							addEdge(p, new Pair(i, j - 1));
						if (adj.get(p) == null)
							adj.put(p, new HashSet<>());
					}

				}
			}
		}

		void addEdge(Pair a, Pair b) {
			if (adj.get(a) == null)
				adj.put(a, new HashSet<>());
			if (adj.get(b) == null)
				adj.put(b, new HashSet<>());
			adj.get(a).add(b);
			adj.get(b).add(a);
		}

		class Pair {
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

	}

}
