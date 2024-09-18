//https://open.kattis.com/problems/illumination
import java.io.*;
import java.util.*;

public class Illumination2SAT {

	public static void main(String[] args) {
		Input in = new Input(System.in);
		int n = in.nextInt();
		int r = in.nextInt();
		int k = in.nextInt();
		Lampara[] lamparas = new Lampara[k];
		TWOSAT solver = new TWOSAT(2 * k);
		for (int i = 0; i < k; i++) {
			int row = in.nextInt();
			int col = in.nextInt();
			lamparas[i] = new Lampara(row - 1, col - 1);
		}

		for (int i = 0; i < k; i++)
			for (int j = i + 1; j < k; j++) {
				if (lamparas[i].fila == lamparas[j].fila
						&& Math.abs(lamparas[i].columna - lamparas[j].columna) <= 2 * r) {
					solver.addEdge(i, j + k);
					solver.addEdge(j, i + k);

				}
				if (lamparas[i].columna == lamparas[j].columna
						&& Math.abs(lamparas[i].fila - lamparas[j].fila) <= 2 * r) {
					solver.addEdge(i + k, j);
					solver.addEdge(j + k, i);
				}

			}
		solver.strongly_cc();
		for (int i = 0; i < k; i++)
			if (solver.scc[i] == solver.scc[i + k]) {
				System.out.println(0);
				return;
			}
		System.out.println(1);
	}

	static class Lampara {
		int fila;
		int columna;

		Lampara(int f, int c) {
			this.fila = f;
			this.columna = c;
		}
	}

	static class TWOSAT {
		int n;
		ArrayList<Integer>[] adj;
		ArrayList<Integer>[] adjT;
		Stack<Integer> top_sort;
		int[] d, scc;
		int time;
		int nscc;

		TWOSAT(int n) {
			this.n = n;
			adj = new ArrayList[n];
			adjT = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<>();
				adjT[i] = new ArrayList<>();
			}
		}

		void addEdge(int a, int b) {
			adj[a].add(b);
			adjT[b].add(a);
		}

		void strongly_cc() {
			d = new int[n];
			top_sort = new Stack<>();
			time = 1;
			for (int i = 0; i < n; i++)
				if (d[i] == 0)
					dfs(i);
			scc = new int[n];
			nscc = 0;
			Arrays.fill(d, 0);
			Arrays.fill(scc, -1);
			while (!top_sort.isEmpty()) {
				int u = top_sort.pop();
				if (d[u] == 0) {
					dfs_kos(u);
					nscc++;
				}
			}
		}

		void dfs(int u) {
			d[u] = time++;
			for (int v : adj[u])
				if (d[v] == 0)
					dfs(v);
			top_sort.push(u);

		}

		void dfs_kos(int u) {
			scc[u] = nscc;
			d[u] = time++;
			for (int v : adjT[u])
				if (d[v] == 0)
					dfs_kos(v);
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

		double nextDouble() {
			return Double.parseDouble(next());
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
