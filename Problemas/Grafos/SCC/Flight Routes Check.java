//https://cses.fi/problemset/task/1682/
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
		if (nscc > 1) {
			System.out.println("NO");
			int u = 0;
			for (int i = 1; i < n; i++)
				if (scc[i] != scc[u]) {
					System.out.println(scc[u] < scc[i] ? (++i) + " " + (++u) : (++u) + " " + (++i));
					break;
				}
		} else
			System.out.println("YES");

	}

	static void kosaraju() {
		visited = new boolean[n];
		topsort = new Stack<>();
		for (int i = 0; i < n; i++)
			if (!visited[i])
				dfs(i);
		nscc = 0;
		scc = new int[n];
		visited = new boolean[n];
		while (!topsort.isEmpty()) {
			int u = topsort.pop();
			if (!visited[u])
				dfsK(u, nscc++);
		}
	}

	static void dfsK(int u, int N) {
		scc[u] = N;
		visited[u] = true;
		for (int v : adjT[u])
			if (!visited[v])
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
