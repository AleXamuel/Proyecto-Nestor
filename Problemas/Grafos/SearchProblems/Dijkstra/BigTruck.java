//https://open.kattis.com/problems/bigtruck
import java.util.*;
import java.io.*;

public class BigTruck {
	static int n;
	static ArrayList<Edge>[] adj;
	static int[] items;

	public static void main(String[] args) {
		Input in = new Input(System.in);
		n = in.nextInt();
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<>();
		items = new int[n];
		for (int i = 0; i < n; i++)
			items[i] = in.nextInt();
		int m = in.nextInt();
		for (int i = 0; i < m; i++) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			int w = in.nextInt();
			adj[a].add(new Edge(b, w));
			adj[b].add(new Edge(a, w));
		}
		int[][] ans = dijkstra();
		if (ans[0][n - 1] == Integer.MAX_VALUE || ans[1][n - 1] == Integer.MIN_VALUE)
			System.out.println("impossible");
		else
			System.out.println(ans[0][n - 1] + " " + ans[1][n - 1]);

	}

	static int[][] dijkstra() {
		TreeSet<Edge> Q = new TreeSet<>();
		int[] d = new int[n];
		Arrays.fill(d, Integer.MAX_VALUE);
		boolean[] visited = new boolean[n];
		int[] item_d = new int[n];
		Arrays.fill(item_d, Integer.MIN_VALUE);
		Q.add(new Edge(0, 0));
		d[0] = 0;
		item_d[0] = items[0];
		while (!Q.isEmpty()) {
			Edge e = Q.pollFirst();
			int u = e.vertex;
			if (!visited[u]) {
				visited[u] = true;
				for (Edge ee : adj[u]) {
					int v = ee.vertex;
					int w = ee.weight;
					if (!visited[v])
						if (d[u] + w == d[v])
							item_d[v] = Math.max(item_d[u] + items[v], item_d[v]);
						else if (d[u] + w < d[v]) {
							d[v] = d[u] + w;
							item_d[v] = item_d[u] + items[v];
							Q.add(new Edge(v, d[v]));
						}
				}
			}

		}
		return new int[][] { d, item_d };

	}

	static class Edge implements Comparable<Edge> {
		int vertex;
		int weight;

		Edge(int v, int w) {
			this.vertex = v;
			this.weight = w;
		}

		public int compareTo(Edge e) {
			if (weight < e.weight)
				return -1;
			if (weight > e.weight)
				return 1;
			return Integer.compare(vertex, e.vertex);
		}

		public String toString() {
			return "(" + vertex + ", " + weight + ")";
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
