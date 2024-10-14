import java.util.*;

public class Main {
	static ArrayList<Integer>[] adj;
	static int[] in_deg;
	static int n;

	@SuppressWarnings("unchecked")
	static int[] findOrder(int V, int[][] E) {
		n = V;
		adj = new ArrayList[n];
		in_deg = new int[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<>();
		for (int i = 0; i < E.length; i++) {
			int a = E[i][1];
			int b = E[i][0];
			adj[a].add(b);
			in_deg[b]++;
		}
		return kahn();
	}

	static int[] kahn() {
		Queue<Integer> Q = new LinkedList<>();
		for (int u = 0; u < n; u++)
			if (in_deg[u] == 0)
				Q.add(u);
		int index = 0;
		int[] toposort = new int[n];
		while (!Q.isEmpty()) {
			int u = Q.poll();
			toposort[index++] = u;
			for (int v : adj[u]) {
				in_deg[v]--;
				if (in_deg[v] == 0)
					Q.add(v);
			}
		}
		if (index != n)
			return new int[] {};
		return toposort;
	}
}
