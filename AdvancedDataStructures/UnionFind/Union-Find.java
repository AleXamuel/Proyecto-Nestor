import java.io.*;
import java.util.*;

public class Union_FindKattis {

	public static void main(String[] args) {
		Input in = new Input(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		int q = in.nextInt();
		UnionFind uf = new UnionFind(n);
		for (int i = 0; i < q; i++) {
			String op = in.next();
			if (op.equals("=")) {
				int a = in.nextInt();
				int b = in.nextInt();
				uf.unionSet(a, b);
			} else {
				int a = in.nextInt();
				int b = in.nextInt();
				out.println(uf.isSameSet(a, b) ? "yes" : "no");
			}

		}
		out.flush();
	}

	static class UnionFind {
		int[] parents;
		int[] treeSizes;

		UnionFind(int size) {
			parents = new int[size];
			treeSizes = new int[size];
			for (int i = 0; i < size; i++) {
				parents[i] = i;
				treeSizes[i] = 1;
			}
		}

		void unionSet(int i, int j) {
			int rootI = find(i);
			int rootJ = find(j);
			if (rootI == rootJ)
				return;
			if (treeSizes[rootI] < treeSizes[rootJ])
				subdue(rootI, rootJ);
			else
				subdue(rootJ, rootI);
		}

		boolean isSameSet(int i, int j) {
			return find(i) == find(j);
		}

		int find(int i) {
			int root = i;
			while (root != parents[root])
				root = parents[root];
			return root;
		}

		private void subdue(int slave, int master) {
			parents[slave] = master;
			treeSizes[master] += treeSizes[slave];
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
