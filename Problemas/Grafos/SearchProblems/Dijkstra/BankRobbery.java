//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5038
import java.io.*;
import java.util.*;

public class BankRobbery {
	static int n;
	static ArrayList<Edge>[] adj;
	static int[] d;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		PrintWriter out = new PrintWriter(System.out);
		for (int c;;) {
			try {
				st = new StringTokenizer(in.readLine());
				n = Integer.parseInt(st.nextToken());
				int m = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int p = Integer.parseInt(st.nextToken());
				adj = new ArrayList[n];
				d = new int[n];
				for (int i = 0; i < n; i++) {
					adj[i] = new ArrayList<>();
					d[i] = Integer.MAX_VALUE;
				}
				for (int i = 0; i < m; i++) {
					st = new StringTokenizer(in.readLine());
					int u = Integer.parseInt(st.nextToken());
					int v = Integer.parseInt(st.nextToken());
					int w = Integer.parseInt(st.nextToken());
					adj[u].add(new Edge(v, w));
					adj[v].add(new Edge(u, w));
				}
				int[] bancos = new int[b];
				st = new StringTokenizer(in.readLine());
				for (int i = 0; i < b; i++)
					bancos[i] = Integer.parseInt(st.nextToken());
				int masLejano = -1;
				if (p != 0) {
					st = new StringTokenizer(in.readLine());
					TreeSet<Edge> Q = new TreeSet<>();
					for (int i = 0; i < p; i++) {
						int val = Integer.parseInt(st.nextToken());
						d[val] = 0;
						Q.add(new Edge(val, 0));
					}
					dijkstra(Q);
					for (int i : bancos)
						masLejano = Math.max(masLejano, d[i]);
				} else
					masLejano = Integer.MAX_VALUE;
				TreeSet<Integer> ans = new TreeSet<>();
				for (int i : bancos)
					if (d[i] == masLejano)
						ans.add(i);
				out.println(ans.size() + " " + (masLejano == Integer.MAX_VALUE ? "*" : masLejano));
				c = 0;
				for (int i : ans)
					out.print(i + (c++ != ans.size() - 1 ? " " : ""));
				out.println();
			} catch (Exception e) {
				break;
			}
		}
		out.flush();

	}

	static void dijkstra(TreeSet<Edge> Q) {
		boolean[] visited = new boolean[n];
		while (!Q.isEmpty()) {
			Edge e = Q.pollFirst();
			int u = e.vertex;
			if (visited[u])
				continue;
			visited[u] = true;
			for (Edge ee : adj[u]) {
				int v = ee.vertex;
				int w = ee.weight;
				if (!visited[v] && d[u] + w < d[v]) {
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

		public int compareTo(Edge e) {
			if (weight < e.weight)
				return -1;
			if (weight > e.weight)
				return 1;
			return vertex - e.vertex;
		}

	}

}
