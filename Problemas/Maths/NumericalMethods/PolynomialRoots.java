//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=871
import java.util.*;
import java.io.*;

public class PolynomialRoots {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int k = Integer.parseInt(in.readLine());
		for (int i = 0; i < k; i++) {
			int n = Integer.parseInt(in.readLine());
			double[] f = new double[n + 1];
			st = new StringTokenizer(in.readLine());
			for (int j = f.length - 1; j >= 0; j--)
				f[j] = Double.parseDouble(st.nextToken());
			double[] conocidas = new double[n - 2];
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < conocidas.length; j++)
				conocidas[j] = Double.parseDouble(st.nextToken());
			for (double d : conocidas)
				f = div(f, d);
			double[] ans = bashkara(f);
			for (double d : ans)
				System.out.println(String.format("%.1f", d));
		}

	}

	static double[] bashkara(double[] f) {
		double a = f[2];
		double b = f[1];
		double c = f[0];
		double x1 = (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a);
		double x2 = (-b - Math.sqrt(b * b - 4 * a * c)) / (2 * a);
		return new double[] { x1, x2 };

	}

	static double[] div(double[] f, double x) {
		double[] ans = new double[f.length - 1];
		for (int i = f.length - 1; i >= 1; i--) {
			ans[i - 1] = f[i];
			f[i - 1] += x * f[i];
		}
		return ans;
	}

}
