/*https://codeforces.com/problemset/problem/1027/D*/

import java.io.*;
import java.util.*;

public class MouseHunt {
	static int n;
	static ArrayList<Integer>[] adj;
	static boolean[] state;
	static Stack<Integer> Toposort;

	public static void MouseHunt(String[] args) throws Exception {
		Input in = new Input(System.in);
		n = in.nextInt();
		int[] costos = new int[n];
		for (int i = 0; i < n; i++)
			costos[i] = in.nextInt();
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<>();
		for (int i = 0; i < n; i++)
			adj[i].add(in.nextInt() - 1);
		System.out.println(solve(costos));
	}

	static int solve(int[] costos) {
		int ans = 0;
		boolean[] visited = new boolean[n];
		for (int i : TopSort()) {
			int min = Integer.MAX_VALUE;
			if (!visited[i]) {
				ArrayList<Integer> cost = bfs(i, visited);
				if (!cost.isEmpty()) {
					for (int j : cost)
						min = Math.min(min, costos[j]);
					ans += min;
				}
			}
		}
		return ans;
	}

	static ArrayList<Integer> bfs(int s, boolean[] visited) {
		ArrayList<Integer> ciclos = new ArrayList<>();
		Queue<Integer> Q = new LinkedList<>();
		Stack<Integer> S = new Stack<>();
		Q.add(s);
		visited[s] = true;
		while (!Q.isEmpty()) {
			int u = Q.poll();
			S.push(u);
			for (int v : adj[u])
				if (!visited[v]) {
					visited[v] = true;
					Q.add(v);
				} else if (S.contains(v)) {
					int t = S.pop();
					ciclos.add(t);
					while (t != v) {
						t = S.pop();
						ciclos.add(t);
					}
				}
		}
		return ciclos;
	}

	static void dfs(int s) {
		state[s] = true;
		for (int v : adj[s])
			if (!state[v])
				dfs(v);
		Toposort.add(s);
	}

	static int[] TopSort() {
		state = new boolean[n];
		Toposort = new Stack<>();
		for (int i = 0; i < n; i++)
			if (!state[i])
				dfs(i);
		int ans[] = new int[n];
		for (int i = 0; i < n; i++)
			ans[i] = Toposort.pop();
		return ans;
	}

	static class Input {
		BufferedReader br;
		StringTokenizer st;

		public Input(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}
		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
	}
}
