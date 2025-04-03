//https://cses.fi/problemset/task/1683/
import java.util.*;
import java.io.*;

public class Main {

	static int n;
	static ArrayList<Integer>[] adj;
	static ArrayList<Integer>[] adjT;
	static Stack<Integer> topsort;
	static int nscc;
	static int[] scc;
	static boolean[] visited;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		PrintWriter out = new PrintWriter(System.out);
		st = new StringTokenizer(in.readLine());
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		adj = new ArrayList[n];
		adjT = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>();
			adjT[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			adj[a].add(b);
			adjT[b].add(a);
		}
		kosaraju();
		out.println(nscc - 1);
		for (int u : scc)
			out.print(u + " ");
		out.close();

	}

	static void kosaraju() {
		visited = new boolean[n];
		topsort = new Stack<>();
		for (int i = 0; i < n; i++)
			if (!visited[i])
				dfs(i);
		nscc = 1;
		scc = new int[n];
		while (!topsort.isEmpty()) {
			int u = topsort.pop();
			if (scc[u] == 0)
				dfsK(u, nscc++);
		}
	}

	static void dfsK(int u, int N) {
		scc[u] = N;
		for (int v : adjT[u])
			if (scc[v] == 0)
				dfsK(v, N);
	}

	static void dfs(int u) {
		visited[u] = true;
		for (int v : adj[u])
			if (!visited[v])
				dfs(v);
		topsort.push(u);
	}

}
