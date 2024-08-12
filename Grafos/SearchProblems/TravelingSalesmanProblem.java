import java.io.*;
import java.util.*;

public class TSP {

	public static void main(String[] args) {
		Input in = new Input(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		double[][] adm = new double[n][n];
		for (int i = 0; i < adm.length; i++)
			Arrays.fill(adm[i], Double.MAX_VALUE);
		for (int i = 0; i < m; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			double w = in.nextDouble();
			adm[a][b] = w;
		}
		double ans = Double.MAX_VALUE;
		for (int i = 0; i < n; i++)
			ans = Math.min(ans, tsp(adm, i));
		System.out.println(ans == Double.MAX_VALUE ? -1 : (long) ans);

	}

	static double tsp(double[][] mAdy, int v) {
		int n = mAdy.length, t = 1 << n;
		double mem[][] = new double[t][n];
		for (double[] arr : mem)
			Arrays.fill(arr, -1d);
		return tsp(mAdy, n, v, v, 1 << v, mem);
	}

	static double tsp(double[][] mAdy, int n, int v1, int v2, int visitados, double[][] mem) {
		if (mem[visitados][v1] >= 0d)
			return mem[visitados][v1];
		if (visitados == (1 << n) - 1)
			return mem[visitados][v1] = mAdy[v1][v2];
		double min = Double.POSITIVE_INFINITY, d;
		for (int e = visitados, j = 0; j < n; j++, e >>>= 1)
			if ((e & 1) == 0 && (d = mAdy[v1][j]) < min)
				min = Math.min(min, d + tsp(mAdy, n, j, v2, visitados | (1 << j), mem));
		return mem[visitados][v1] = min;
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
