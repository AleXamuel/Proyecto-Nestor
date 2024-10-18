import java.util.*;
import java.io.*;

public class CallingCircles {
	static int n;
	static ArrayList<Integer>[] adj;
	static ArrayList<Integer>[] adjT;
	static Stack<Integer> top_sort;
	static boolean[] state;
	static List<List<Integer>> comps;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		PrintWriter out = new PrintWriter(System.out);
		int caso = 1;
		while (true) {
			st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			if (n == 0 && m == 0)
				break;
			if (caso != 1)
				out.println();
			HashMap<String, Integer> h = new HashMap<>();
			HashMap<Integer, String> inv = new HashMap<>();
			adj = new ArrayList[n];
			adjT = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<>();
				adjT[i] = new ArrayList<>();
			}

			int index = 0;
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(in.readLine());
				String a = st.nextToken();
				String b = st.nextToken();
				if (h.get(b) == null) {
					h.put(b, index);
					inv.put(index, b);
					index++;
				}
				if (h.get(a) == null) {
					h.put(a, index);
					inv.put(index, a);
					index++;
				}
				adj[h.get(a)].add(h.get(b));
				adjT[h.get(b)].add(h.get(a));
			}
			out.println("Calling circles for data set " + caso++ + ":");
			get_scc();
			if (h.isEmpty())
				continue;
			for (List<Integer> comp : comps) {
				index = 0;
				List<String> ans = new ArrayList<>();
				for (int u : comp)
					ans.add(inv.get(u));
				for (String u : ans)
					out.print(u + (index++ < comp.size() - 1 ? ", " : ""));
				out.println();
			}
		}
		out.flush();

	}

	static void get_scc() {
		state = new boolean[n];
		top_sort = new Stack<>();
		for (int i = 0; i < n; i++)
			if (!state[i])
				dfs(i);
		state = new boolean[n];
		comps = new ArrayList<>();
		while (!top_sort.isEmpty()) {
			int u = top_sort.pop();
			if (!state[u]) {
				List<Integer> comp = new ArrayList<>();
				dfs_kos(u, comp);
				comps.add(comp);
			}
		}
	}

	static void dfs(int u) {
		state[u] = true;
		for (int v : adj[u])
			if (!state[v])
				dfs(v);
		top_sort.push(u);
	}

	static void dfs_kos(int u, List<Integer> comp) {
		comp.add(u);
		state[u] = true;
		for (int v : adjT[u])
			if (!state[v])
				dfs_kos(v, comp);
	}

}
