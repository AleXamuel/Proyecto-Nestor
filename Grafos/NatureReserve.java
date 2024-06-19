import java.io.*;
import java.util.*;

public class NautureDeserve {
	static int n;
	static ArrayList<Edge>[] adj;
	static TreeSet<Edge> Q;
	static long[] d;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int t = Integer.parseInt(in.readLine());
		for (int cases = 0; cases < t; cases++) {
			st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			adj = new ArrayList[n];
			for (int i = 0; i < n; i++)
				adj[i] = new ArrayList<>();
			int m = Integer.parseInt(st.nextToken());
			int l = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			Q = new TreeSet<Edge>();
			d = new long[n];
			Arrays.fill(d, Integer.MAX_VALUE);
			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < s; i++) {
				int v = Integer.parseInt(st.nextToken()) - 1;
				Q.add(new Edge(v, 0));
				d[v] = 0;
			}
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(in.readLine());
				int a = Integer.parseInt(st.nextToken()) - 1;
				int b = Integer.parseInt(st.nextToken()) - 1;
				long w = Long.parseLong(st.nextToken());
				adj[a].add(new Edge(b, w + l));
				adj[b].add(new Edge(a, w + l));
			}
			prim();
			System.out.println(Arrays.stream(d).sum());
			//Also works:
			//System.out.println(Arrays.stream(d).sum() + (n - s) * l);
			//This way we don't need to add l to the weight of each edge but n,s and l must be long.

		}

	}

	static void prim() {
		boolean[] state = new boolean[n];
		while (!Q.isEmpty()) {
			Edge e = Q.pollFirst();
			int u = e.vertex;
			if (!state[u]) {
				state[u] = true;
				for (Edge ee : adj[u]) {
					int v = ee.vertex;
					long w = ee.weight;
					if (!state[v] && w < d[v]) {
						d[v] = w;
						Q.add(new Edge(v, d[v]));
					}
				}

			}

		}
	}

	static class Edge implements Comparable<Edge> {
		int vertex;
		long weight;

		Edge(int v, long w) {
			this.vertex = v;
			this.weight = w;
		}

		public int compareTo(Edge o) {
			if (weight < o.weight)
				return -1;
			if (weight > o.weight)
				return 1;
			if (vertex < o.vertex)
				return -1;
			if (vertex > o.vertex)
				return 1;
			return 0;
		}
	}

}
