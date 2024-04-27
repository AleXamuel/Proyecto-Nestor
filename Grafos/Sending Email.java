import java.io.*;
import java.util.*;

public class SendingEmail {
	static int n;
	static ArrayList<Edge>[] adj;
	static final int INF = 10000000;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(in.readLine());
		for (int i = 0; i < test; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			int t = Integer.parseInt(st.nextToken());
			adj = new ArrayList[n];
			for (int j = 0; j < n; j++)
				adj[j] = new ArrayList<>();
			for (int j = 0; j < m; j++) {
				st = new StringTokenizer(in.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int w = Integer.parseInt(st.nextToken());
				adj[a].add(new Edge(b, w));
				adj[b].add(new Edge(a, w));
			}
			int ans = dijkstra(s, t);
			if (ans != INF)
				System.out.println("Case #" + (i + 1) + ": " + ans);
			else
				System.out.println("Case #" + (i + 1) + ": " + "unreachable");

		}
	}

	static int dijkstra(int s, int t) {
		int[] d = new int[n], pi = new int[n];
		boolean[] state = new boolean[n];
		Arrays.fill(d, INF);
		d[s] = 0;
		TreeSet<Edge> Q = new TreeSet<Edge>();
		Q.add(new Edge(s, d[s]));
		while (!Q.isEmpty()) {
			Edge e = Q.pollFirst();
			int u = e.v;
			if (!state[u]) {
				for (Edge ee : adj[u]) {
					int v = ee.v;
					int w = ee.w;
					if (!state[v])
						if (d[u] + w < d[v]) {
							d[v] = d[u] + w;
							pi[v] = u;
							Q.add(new Edge(v, d[v]));
						}
				}
				state[u] = true;
			}
		}
		return d[t];
	}

	private static class Edge implements Comparable<Edge> {
		int v;
		int w;

		public Edge(int v, int w) {
			this.v = v;
			this.w = w;
		}

		public boolean equals(Object o) {
			if (o instanceof Edge)
				return (v == ((Edge) o).v && w == ((Edge) o).w);
			return false;
		}

		public int compareTo(Edge o) {
			if (w < o.w)
				return -1;
			if (w > o.w)
				return 1;
			if (v < o.v)
				return -1;
			if (v > o.v)
				return 1;
			return 0;
		}
	}

}
