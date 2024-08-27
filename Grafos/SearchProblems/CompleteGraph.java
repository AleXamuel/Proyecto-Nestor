import java.io.*;
import java.util.*;

public class CompleteGraph {
	static int n;

	public static void main(String[] args) {
		Input in = new Input(System.in);
		n = in.nextInt();
		int m = in.nextInt();
		int[][] matrix = new int[n][n];
		for (int i = 0; i < m; i++) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			matrix[a][b] = matrix[b][a] = 1;
		}
		System.out.println(solve(matrix) ? "YES" : "NO");

	}

	static boolean solve(int[][] m) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (i == j && m[i][j] != 0)
					return false;
				if (m[i][j] != 1 && i != j)
					return false;
			}
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
