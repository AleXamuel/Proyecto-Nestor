import java.util.*;
import java.io.*;

public class LongestPathInATree {
	static int n;
	static ArrayList<Integer>[] adj;
	static boolean[] visitado;
	static int max_prof, max_ver;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(in.readLine());
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<>();
		for (int i = 0; i < n - 1; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			a--;
			b--;
			adj[a].add(b);
			adj[b].add(a);
		}
		System.out.println(solve());

	}

	static int solve() {
		visitado = new boolean[n];
		max_prof = 0;
		max_ver = 0;
		dfs(0, 0);
		max_prof = 0;
		Arrays.fill(visitado, false);
		dfs(max_ver, 0);
		return max_prof;
	}

	static void dfs(int v, int dist) {
		visitado[v] = true;
		if (dist > max_prof) {
			max_prof = dist;
			max_ver = v;
		}
		for (int u : adj[v])
			if (!visitado[u])
				dfs(u, dist + 1);

	}

}
