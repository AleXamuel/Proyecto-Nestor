//https://atcoder.jp/contests/dp/tasks/dp_g?lang=en
import java.io.*;
import java.util.*;

public class LongestPathInDAG {
	static ArrayList<Integer>[] adj;
	static int n;
	static int[] in_deg;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<>();
		in_deg = new int[n];
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			adj[a].add(b);
			in_deg[b]++;
		}
		System.out.println(kahn());

	}

	static int kahn() {
		Queue<Integer> Q = new LinkedList<>();
		for (int i = 0; i < n; i++)
			if (in_deg[i] == 0)
				Q.add(i);
		int res = -1;
		while (!Q.isEmpty()) {
			int level = Q.size();
			for (int i = 0; i < level; i++) {
				int u = Q.poll();
				for (int v : adj[u]) {
					in_deg[v]--;
					if (in_deg[v] == 0)
						Q.add(v);
				}
			}
			res++;
		}
		return res;
	}

}
