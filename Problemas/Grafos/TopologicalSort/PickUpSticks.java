import java.io.*;
import java.util.*;

public class PickUpSticks {
	static ArrayList<Integer>[] adj;
	static int n;

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Input in = new Input(System.in);
		n = in.nextInt();
		adj = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<>();
		int m = in.nextInt();
		for (int i = 0; i < m; i++)
			adj[in.nextInt() - 1].add(in.nextInt() - 1);
		if (isDag())
			for (int i : topoSort())
				System.out.println(i+1);
		else
			System.out.println("IMPOSSIBLE");

	}

	static int[] topoSort() {
		int state[] = new int[n];
		List<Integer> r = new ArrayList<Integer>();
		for (int v = 0; v < n; v++)
			if (state[v] == 0 && !dfsTS(v, state, r))
				return null;
		int t = r.size(), a[] = new int[t], i;
		for (i = 0; i < t; i++)
			a[i] = r.get(t - 1 - i);
		return a;

	}

	static boolean isDag() {
		return topoSort() != null;
	}

	static boolean dfsTS(int v, int[] state, List<Integer> r) {
		state[v] = 1;
		for (int w : adj[v])
			if (state[w] == 1 || (state[w] == 0 && !dfsTS(w, state, r)))
				return false;
		state[v] = 2;
		r.add(v);
		return true;

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

		double nextDouble() {
			return Double.parseDouble(next());
		}

		public String nextLine() throws Exception {
			return br.readLine();
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

	}

}
