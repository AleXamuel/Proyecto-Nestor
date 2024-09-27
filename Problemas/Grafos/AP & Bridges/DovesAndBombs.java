//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1706
import java.io.*;
import java.util.*;

public class DovesAndBombs {
	static int n;
	static ArrayList<Integer>[] adj;
	static int[] d, low;
	static int time;
	static int[] ap;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer st;
		while (true) {
			st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			if (n == 0 && m == 0)
				break;
			adj = new ArrayList[n];
			for (int i = 0; i < n; i++)
				adj[i] = new ArrayList<>();
			while (true) {
				st = new StringTokenizer(in.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				if (a == -1 && b == -1)
					break;
				adj[a].add(b);
				adj[b].add(a);
			}
			TreeSet<Output> ans = new TreeSet<>();
			d = new int[n];
			low = new int[n];
			time = 1;
			ap = new int[n];
			Arrays.fill(d, -1);
			for (int i = 0; i < n; i++)
				if (d[i] == -1)
					dfs(i, -1);
			for (int i = 0; i < n; i++)
				ans.add(new Output(i, ap[i] + 1));
			for (int i = 0; i < m; i++)
				out.println(ans.pollFirst());
			out.println("");
		}
		out.flush();
	}

	static void dfs(int u, int par) {
		d[u] = time++;
		low[u] = d[u];
		int children = 0;
		for (int v : adj[u])
			if (v == par)
				continue;
			else if (d[v] > 0)
				low[u] = Math.min(low[u], d[v]);
			else {
				children++;
				dfs(v, u);
				low[u] = Math.min(low[u], low[v]);
				if (par != -1 && low[v] >= d[u])
					ap[u]++;
			}
		if (par == -1 && children > 1)
			ap[u]++;
	}

	static class Output implements Comparable<Output> {
		int vertex;
		int paloma;

		Output(int v, int p) {
			this.vertex = v;
			this.paloma = p;
		}

		public int compareTo(Output o) {
			if (paloma < o.paloma)
				return 1;
			if (paloma > o.paloma)
				return -1;
			return Integer.compare(vertex, o.vertex);
		}

		public String toString() {
			return vertex + " " + paloma;
		}

	}
}
