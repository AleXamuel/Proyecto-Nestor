//https://vjudge.net/problem/HackerRank-floyd-city-of-blinding-lights
import java.io.*;
import java.util.*;

public class FloydCityOfBlindingLights {

	public static void main(String[] args) {
		Input in = new Input(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		double[][] adj = new double[n][n];
		for (int i = 0; i < m; i++) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			double w = in.nextDouble();
			adj[a][b] = w;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (adj[i][j] == 0)
					adj[i][j] = Double.MAX_VALUE;
		double[][] ans = floydWarshall(adj);
		int q = in.nextInt();
		for (int i = 0; i < q; i++) {
			int a = in.nextInt() - 1;
			int b = in.nextInt() - 1;
			double res = ans[a][b];
			if (a == b)
				System.out.println(0);
			else if (res == Double.MAX_VALUE)
				System.out.println(-1);
			else
				System.out.println((int) res);
			
		}

	}

	static double[][] floydWarshall(double[][] mAdy) {
		int N;
		double[][] res = new double[N = mAdy.length][N];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				res[i][j] = mAdy[i][j];
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					if (res[i][k] < Double.MAX_VALUE && res[k][j] < Double.MAX_VALUE)
						res[i][j] = Math.min(res[i][j], res[i][k] + res[k][j]);
		return res;
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
