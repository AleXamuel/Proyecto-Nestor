// https://vjudge.net/problem/UVA-11396
import java.io.*;
import java.util.*;

public class ClawDecomposition {
	static int n;
	static ArrayList<Integer>[] adj;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		while (true) {
			n = Integer.parseInt(in.readLine());
			if (n == 0)
				break;
			adj = new ArrayList[n];
			for (int i = 0; i < n; i++)
				adj[i] = new ArrayList<>();
			while (true) {
				StringTokenizer st = new StringTokenizer(in.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				if (a == 0 && b == 0)
					break;
				a--;
				b--;
				adj[a].add(b);
				adj[b].add(a);
			}
			System.out.println(bfs() ? "YES" : "NO");

		}

	}

	static boolean bfs() {
		int[] pi = new int[n];
		Boolean[] color = new Boolean[n];
		boolean[] visited = new boolean[n];
		Arrays.fill(color, null);
		Arrays.fill(pi, -1);
		color[0] = true;
		Queue<Integer> Q = new LinkedList<>();
		Q.add(0);
		while (!Q.isEmpty()) {
			int u = Q.poll();
			if (!visited[u]) {
				visited[u] = true;
				for (int v : adj[u]) {
					if (!visited[v]) {
						if (color[v] == null)
							color[v] = !color[u];
						if (color[v] == color[u])
							return false;
						pi[v] = u;
						Q.add(v);
					}
				}
			}
		}
		return true;

	}

}
