import java.io.*;
import java.util.*;

public class WeakVertices {

	public static void main(String[] args) {
		Input in = new Input(System.in);
		while (true) {
			int n = in.nextInt();
			if (n == -1)
				break;
			long[][] adm = new long[n][n];
			for (int i = 0; i < adm.length; i++)
				for (int j = 0; j < adm.length; j++)
					adm[i][j] = in.nextLong();
			long[][] ans = matrixPower(adm, 3);
			for (int i = 0; i < ans.length; i++)
				for (int j = 0; j < ans.length; j++)
					if (i == j && ans[i][j] == 0)
						System.out.print(i + " ");
			System.out.println(" ");

		}

	}

//Author: William Fiset
	static long[][] matrixPower(long[][] matrix, long p) {
		if (p < 0)
			return null;
		final int N = matrix.length;
		long[][] newMatrix = null;
		if (p == 0) {
			newMatrix = new long[N][N];
			for (int i = 0; i < N; i++)
				newMatrix[i][i] = 1L;
		} else {

			long[][] P = matrixDeepCopy(matrix);

			while (p > 0) {

				if ((p & 1L) == 1L) {
					if (newMatrix == null)
						newMatrix = matrixDeepCopy(P);
					else
						newMatrix = squareMatrixMult(newMatrix, P);
				}
				P = squareMatrixMult(P, P);
				p >>= 1L;
			}
		}

		return newMatrix;
	}

	static long[][] squareMatrixMult(long[][] m1, long[][] m2) {
		final int N = m1.length;
		long[][] newMatrix = new long[N][N];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					newMatrix[i][j] = newMatrix[i][j] + m1[i][k] * m2[k][j];

		return newMatrix;
	}

	static long[][] matrixDeepCopy(long[][] M) {
		final int N = M.length;
		long[][] newMatrix = new long[N][N];
		for (int i = 0; i < N; i++)
			newMatrix[i] = M[i].clone();
		return newMatrix;
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
