import java.util.*;

public class Main {
	static ArrayList<Integer>[] adj;
	static int n;

	// Directed Graph
	static boolean dfs(int u, int[] state) {
		if (state[u] == 1)
			return true;
		if (state[u] == 2)
			return false;
		state[u] = 1;
		boolean ans = false;
		for (int v : adj[u])
			ans = ans || dfs(v, state);
		state[u] = 2;
		return ans;
	}

	// Undirected Graph
	static boolean dfs(int u, int par, boolean[] visited) {
		if (visited[u])
			return true;
		visited[u] = true;
		boolean ans = false;
		for (int v : adj[u])
			if (v != par)
				ans = ans || dfs(v, u, visited);
		return ans;
	}
}
