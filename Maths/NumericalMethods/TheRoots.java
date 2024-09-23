import java.util.*;
import java.io.*;

public class TheRoots {

	public static void main(String[] args) throws Exception {
		Input in = new Input(System.in);
		int caso = 1;
		while (true) {
			int n = in.nextInt();
			if (n == 0)
				break;
			double[] f = new double[n + 1];
			for (int i = f.length - 1; i >= 0; i--)
				f[i] = in.nextDouble();
			double inicial = Math.pow(2, Integer.bitCount(n) / 2);
			double[] ans = new double[n];
			for (int i = 0; i < n; i++) {
				inicial = newton(f, inicial);
				ans[i] = inicial;
				f = div(f, inicial);
			}
			Arrays.sort(ans);
			System.out.print("Equation " + caso + ": ");
			for (int i = 0; i < ans.length; i++) {
				if (i < ans.length - 1)
					System.out.print(String.format("%.4f ", ans[i]));
				else
					System.out.print(String.format("%.4f", ans[i]));
			}
			System.out.println();
			caso++;

		}

	}

	static double[] div(double[] f, double x) {
		double[] ans = new double[f.length - 1];
		for (int i = f.length - 1; i >= 1; i--) {
			ans[i - 1] = f[i];
			f[i - 1] += x * f[i];
		}
		return ans;
	}

	static double eval(double[] f, double x) {
		double ans = 0;
		for (int i = 0; i < f.length; i++)
			ans += f[i] * Math.pow(x, i);
		return ans;
	}

	static double[] f_prima(double[] f, int n) {
		double[] derivada = new double[n - 1];
		derivada[0] = f[1];
		for (int i = 1; i < n - 1; i++)
			derivada[i] = f[i + 1] * (i + 1);
		return derivada;

	}

	static double newton(double[] f, double x) {
		while (Math.abs(eval(f, x)) >= 1e-7)
			x = x - eval(f, x) / eval(f_prima(f, f.length), x);
		return x;
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
