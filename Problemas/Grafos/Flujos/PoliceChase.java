//https://cses.fi/problemset/task/1695
import java.io.*;
import java.util.*;

public class PoliceChase {
	static int n;
	static ArrayList<Integer>[] adj;
	static int INF = Integer.MAX_VALUE;
	static int[][] capacity;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		PrintWriter out = new PrintWriter(System.out);
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<>();
		capacity = new int[n][n];
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			adj[a].add(b);
			adj[b].add(a);
			capacity[a][b] = capacity[b][a] = 1;
		}
		out.println(maxflow(0, n - 1));
		boolean[] visited = dfs(0);
		for (int u = 0; u < n; u++)
			for (int v : adj[u])
				if (visited[u] && !visited[v])
					out.println((u + 1) + " " + (v + 1));
		out.flush();
	}

	static boolean[] dfs(int s) {
		boolean[] visited = new boolean[n];
		Stack<Integer> Q = new Stack<>();
		visited[s] = true;
		Q.push(s);
		while (!Q.isEmpty()) {
			int u = Q.pop();
			for (int v = 0; v < n; v++)
				if (capacity[u][v] > 0 && !visited[v]) {
					visited[v] = true;
					Q.push(v);
				}
		}
		return visited;
	}

	static int maxflow(int s, int t) {
		int[] pi = new int[n];
		int maxflow = 0;
		while (bfs(s, t, pi)) {
			int flow = INF;
			for (int u = t; u != s; u = pi[u]) {
				int p = pi[u];
				flow = Math.min(flow, capacity[p][u]);
			}
			for (int u = t; u != s; u = pi[u]) {
				int p = pi[u];
				capacity[p][u] -= flow;
				capacity[u][p] += flow;
			}
			maxflow += flow;
		}
		return maxflow;
	}

	static boolean bfs(int s, int t, int[] pi) {
		boolean[] visited = new boolean[n];
		Queue<Integer> Q = new LinkedList<>();
		Q.add(s);
		pi[s] = -1;
		visited[s] = true;
		while (!Q.isEmpty()) {
			int u = Q.poll();
			for (int v : adj[u])
				if (!visited[v] && capacity[u][v] > 0) {
					pi[v] = u;
					visited[v] = true;
					if (v == t)
						return true;
					Q.add(v);
				}
		}
		return false;
	}
	/*
	 * A minimum cut can be found after performing a maximum flow computation using
	 * the Ford-Fulkerson method. One possible minimum cut is the following: the set
	 * of all the vertices that can be reached from S in the residual graph (using
	 * edges with positive residual capacity), and the set of all the other
	 * vertices. This partition can be easily found using DFS starting at S .
	 */

}
