/* https://vjudge.net/problem/UVA-10199 */

import java.util.*;
import java.io.*;

public class TouristGuide {

	static HashMap<String, Integer> vertices;
	static ArrayList<Integer>[] adj;
	static HashSet<Integer> ap;
	static TreeSet<String> ans;
	static int n;
	static int[] d, f, low;
	static int time;
	static boolean[] visitado;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int c = 1;
		while (true) {
			String s = in.readLine();
			if (s.equals("0") || s.isEmpty())
				break;
			try {
				n = Integer.parseInt(s);
			} catch (NumberFormatException e) {
				break;
			}
			adj = new ArrayList[n];
			for (int i = 0; i < n; i++)
				adj[i] = new ArrayList<>();
			vertices = new HashMap<>();
			for (int i = 0; i < n; i++) {
				String city = in.readLine();
				vertices.put(city, i);
			}
			int R = Integer.parseInt(in.readLine());
			for (int i = 0; i < R; i++) {
				String edges = in.readLine();
				StringTokenizer st = new StringTokenizer(edges, " ");
				int a = vertices.get(st.nextToken());
				int b = vertices.get(st.nextToken());
				adj[a].add(b);
				adj[b].add(a);
			}
			if (c != 1)
				System.out.println();
			ans = new TreeSet<>();
			d = new int[n];
			low = new int[n];
			time = 1;
			ap = new HashSet<>();
			visitado = new boolean[n];
			solve(0);
			for (int i = 0; i < visitado.length; i++)
				if (!visitado[i])
					solve(i);
			System.out.print("City map #" + c + ": " + ans.size() + " camera(s) found\n");
			for (String i : ans)
				System.out.print(i + "\n");
			c++;
		}
	}

	static void solve(int u) {
		dfs(u, -1);
		for (Map.Entry<String, Integer> entry : vertices.entrySet()) {
			String key = entry.getKey();
			Integer val = entry.getValue();
			if (ap.contains(val))
				ans.add(key);
		}
	}

	static void dfs(int u, int par) {
		d[u] = time++;
		visitado[u] = true;
		low[u] = d[u];
		int children = 0;
		for (int v : adj[u]) {
			if (v == par)
				continue;
			else if (d[v] > 0)
				low[u] = Math.min(low[u], d[v]);
			else {
				children++;
				dfs(v, u);
				low[u] = Math.min(low[u], low[v]);
				if (par != -1 && low[v] >= d[u])
					ap.add(u);

			}
		}
		if (par == -1 && children > 1)
			ap.add(u);
	}

}
