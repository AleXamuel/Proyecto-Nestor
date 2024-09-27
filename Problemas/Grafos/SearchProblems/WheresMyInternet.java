//https://open.kattis.com/problems/wheresmyinternet
import java.io.*;
import java.util.*;

public class WheresMyInternet {
	static int n;
	static ArrayList<Integer>[] adj;

	public static void main(String[] args) {
		Input in = new Input(System.in);
		PrintWriter out = new PrintWriter(System.out);
		n = in.nextInt();
		int m = in.nextInt();
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			adj[a].add(b);
			adj[b].add(a);
		}
		boolean[] visited = new boolean[n];
		dfs(0, visited);
		boolean cond = true;
		for (int i = 0; i < visited.length; i++)
			if (!visited[i]) {
				out.println(i + 1);
				cond = false;
			}
		if (cond)
			out.println("Connected");
		out.flush();

	}

	static void dfs(int s, boolean[] visited) {
		Stack<Integer> S = new Stack<>();
		S.push(s);
		visited[s] = true;
		while (!S.isEmpty()) {
			int u = S.pop();
			for (int v : adj[u]) {
				if (!visited[v]) {
					visited[v] = true;
					S.push(v);
				}
			}
		}

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

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		public String nextLine() throws Exception {
			return br.readLine();
		}

		public void close() throws IOException {
			br.close();
		}

		public boolean hasNext() {
			try {
				while (st == null || !st.hasMoreTokens())
					st = new StringTokenizer(br.readLine());

			} catch (Exception e) {
				return false;
			}
			return true;
		}

		public boolean ready() throws IOException {
			return br.ready();
		}

	}

}
