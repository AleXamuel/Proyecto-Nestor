//https://vjudge.net/problem/SPOJ-DIGOKEYS
import java.util.*;
import java.io.*;

public class DIGOKEYS_FindTheTreasure {
	static int n;
	static ArrayList<Integer>[] adj;
	static int[] pi;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(in.readLine());
		for (int cases = 0; cases < t; cases++) {
			n = Integer.parseInt(in.readLine());
			adj = new ArrayList[n];
			for (int i = 0; i < n; i++)
				adj[i] = new ArrayList<>();
			for (int i = 0; i < n - 1; i++) {
				StringTokenizer st = new StringTokenizer(in.readLine());
				st.nextToken();
				while (st.hasMoreTokens()) {
					adj[i].add(Integer.parseInt(st.nextToken()) - 1);
				}
				Collections.sort(adj[i]);
			}
			if (!bfs())
				System.out.println(-1);
			else {
				StringBuffer ans = new StringBuffer();
				int s = n - 1;
				int c = 0;
				while (s != 0) {
					s = pi[s];
					c++;
					ans.insert(0, (s + 1) + " ");
				}
				System.out.println(c);
				System.out.println(ans);
			}
		}

	}

	static boolean bfs() {
		pi = new int[n];
		boolean[] state = new boolean[n];
		Queue<Integer> Q = new LinkedList<>();
		pi[0] = -1;
		state[0] = true;
		Q.add(0);
		while (!Q.isEmpty()) {
			int u = Q.poll();
			if (u == n - 1)
				return true;
			for (int v : adj[u]) {
				if (!state[v]) {
					pi[v] = u;
					state[v] = true;
					Q.add(v);
				}
			}
		}
		return false;
	}
}
