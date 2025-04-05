//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3553
import java.io.*;
import java.util.*;

public class MiceAndMaze {
	static int n;
	static ArrayList<Edge>[] adj;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		PrintWriter out = new PrintWriter(System.out);
		int T = Integer.parseInt(in.readLine());
		for (int cases = 0; cases < T; cases++) {
			in.readLine();
			n = Integer.parseInt(in.readLine());
			int s = Integer.parseInt(in.readLine()) - 1;
			int time = Integer.parseInt(in.readLine());
			int m = Integer.parseInt(in.readLine());
			adj = new ArrayList[n];
			for (int i = 0; i < n; i++)
				adj[i] = new ArrayList<>();
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(in.readLine());
				int a = Integer.parseInt(st.nextToken()) - 1;
				int b = Integer.parseInt(st.nextToken()) - 1;
				int w = Integer.parseInt(st.nextToken());
				adj[b].add(new Edge(a, w));
			}
			int[] d = new int[n];
			Arrays.fill(d, Integer.MAX_VALUE);
			dijkstra(s, d);
			int c = 0;
			for (int i : d)
				if (i <= time)
					c++;
			out.println(c);
			if (cases < T - 1)
				out.println();
		}
		out.flush();

	}

	static void dijkstra(int s, int[] d) {
		boolean[] visited = new boolean[n];
		TreeSet<Edge> Q = new TreeSet<>();
		d[s] = 0;
		Q.add(new Edge(s, d[s]));
		while (!Q.isEmpty()) {
			int u = Q.pollFirst().vertex;
			if (visited[u])
				continue;
			visited[u] = true;
			for (Edge ee : adj[u]) {
				int v = ee.vertex;
				int w = ee.weight;
				if (visited[v])
					continue;
				if (d[u] + w < d[v]) {
					d[v] = d[u] + w;
					Q.add(new Edge(v, d[v]));
				}
			}
		}

	}

	static class Edge implements Comparable<Edge> {
		int vertex;
		int weight;

		Edge(int v, int w) {
			this.vertex = v;
			this.weight = w;
		}

		public int compareTo(Edge o) {
			if (weight < o.weight)
				return -1;
			if (weight > o.weight)
				return 1;
			return vertex - o.vertex;
		}

		public String toString() {
			return "(" + vertex + ", " + weight + ")";
		}

	}

}
