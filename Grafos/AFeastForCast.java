import java.io.*;
import java.util.*;

public class PrimsAlgo {
	static BufferedReader in;
	static int leche;

	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(in.readLine());
		for (int i = 0; i < t; i++) {
			int[][][] graph = load_graph();
			int[][] adj = graph[0];
			int[][] w = graph[1];
			int n = adj.length;
			int[] parent = new int[n];
			int[] dist = new int[n];
			Minimum_Spanning_Tree.prim_mst(adj, w, dist, parent);
			int cost = 0;
			for (int j : dist)
				cost += j + 1;
			if (leche - cost >= 0)
				System.out.println("yes");
			else
				System.out.println("no");

		}

	}

	static int[][][] load_graph() throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		leche = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		int m = n * (n - 1) / 2;
		ArrayList<Integer>[] adj = new ArrayList[n];
		ArrayList<Integer>[] w = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<Integer>();
			w[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			adj[a].add(b);
			adj[b].add(a);
			w[a].add(c);
			w[b].add(c);
		}
		int[][] adj_ = new int[n][];
		int[][] w_ = new int[n][];
		for (int i = 0; i < n; i++) {
			adj_[i] = adj[i].stream().mapToInt(x -> x).toArray();
			w_[i] = w[i].stream().mapToInt(x -> x).toArray();
		}
		return new int[][][] { adj_, w_ };
	}

	private class Minimum_Spanning_Tree {
/**
 * @author edwin_andres
 *
 */
		static void prim_mst(int[][] adj, int[][] w, int[] dist, int[] parent) {
			Arrays.fill(dist, Integer.MAX_VALUE);
			boolean[] visited = new boolean[adj.length];
			PriorityQueue<VertexCost> Q = new PriorityQueue<VertexCost>();
			dist[0] = 0;
			Q.add(new VertexCost(0, 0));
			while (!Q.isEmpty()) {
				VertexCost vc = Q.poll();
				int u = vc.v;
				if (visited[u])
					continue;
				visited[u] = true;
				for (int i = 0; i < adj[u].length; i++) {
					int v = adj[u][i];
					if (!visited[v] && dist[v] > w[u][i]) {
						dist[v] = w[u][i];
						parent[v] = u;
						Q.add(new VertexCost(v, dist[v]));
					}
				}
			}
		}

		private static class VertexCost implements Comparable<VertexCost> {
			int v;
			double cost;

			VertexCost(int v, double cost) {
				this.v = v;
				this.cost = cost;
			}

			public int compareTo(VertexCost o) {
				if (this.cost < o.cost)
					return -1;
				return 1;
			}
		}
	}
}
