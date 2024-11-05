public class FloydWarshall {
		static int n;
		static int[][] adj;

		static void initializeGraph() {
			adj = new int[n][n];
			for (int[] i : adj)
				Arrays.fill(i, Integer.MAX_VALUE);
		}

		static void addEdge(int source, int destination, int cost) {
			adj[source][destination] = cost;
		}

		static void floydWarshall() {
			for (int k = 0; k < n; k++)
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						if (adj[i][k] < Integer.MAX_VALUE && adj[k][j] < Integer.MAX_VALUE)
							adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);

		}
	}
