import java.io.*;
import java.util.*;

public class MaximumSelfMatching {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String s = in.readLine();
		int n = s.length();
		ComplexNumber[] a = new ComplexNumber[n];
		ComplexNumber[] ainv = new ComplexNumber[n];
		ComplexNumber[] b = new ComplexNumber[n];
		ComplexNumber[] binv = new ComplexNumber[n];
		ComplexNumber[] c = new ComplexNumber[n];
		ComplexNumber[] cinv = new ComplexNumber[n];
		Arrays.fill(a, new ComplexNumber(0, 0));
		Arrays.fill(ainv, new ComplexNumber(0, 0));
		Arrays.fill(b, new ComplexNumber(0, 0));
		Arrays.fill(binv, new ComplexNumber(0, 0));
		Arrays.fill(c, new ComplexNumber(0, 0));
		Arrays.fill(cinv, new ComplexNumber(0, 0));
		for (int i = 0; i < n; i++)
			if (s.charAt(i) == 'a') {
				a[i] = new ComplexNumber(1, 0);
				ainv[n - 1 - i] = new ComplexNumber(1, 0);
			} else if (s.charAt(i) == 'b') {
				b[i] = new ComplexNumber(1, 0);
				binv[n - 1 - i] = new ComplexNumber(1, 0);
			} else {
				c[i] = new ComplexNumber(1, 0);
				cinv[n - 1 - i] = new ComplexNumber(1, 0);
			}
		long max = 0;
		long[] aans = polyMult(a, ainv);
		long[] bans = polyMult(b, binv);
		long[] cans = polyMult(c, cinv);
		for (int i = n; i < aans.length; i++) {
			long val = aans[i] + bans[i] + cans[i];
			max = Math.max(max, val);
		}
		StringBuffer out = new StringBuffer();
		for (int i = n; i < aans.length; i++) {
			long val = aans[i] + bans[i] + cans[i];
			if (val == max)
				out.append((i - n + 1) + " ");
		}
		System.out.println(max);
		System.out.println(out);
	}

	static long[] polyMult(ComplexNumber[] a, ComplexNumber[] b) {
		int m = a.length;
		int n = b.length;
		int sz = m + n - 1;
		int szPrima = nextPowerOf2(sz);
		a = Arrays.copyOf(a, szPrima);
		b = Arrays.copyOf(b, szPrima);
		Arrays.fill(a, m, szPrima, new ComplexNumber(0, 0));
		Arrays.fill(b, n, szPrima, new ComplexNumber(0, 0));
		fft(a, 1);
		fft(b, 1);
		for (int i = 0; i < a.length; i++)
			a[i] = a[i].mul(b[i]);
		long[] c = new long[n + m];
		fft(a, -1);
		for (int i = 0; i < c.length; i++)
			c[i] = Math.round(a[i].real);
		return c;

	}

	static int nextPowerOf2(int n) {
		int ans = 1;
		while (ans < n)
			ans *= 2;
		return ans;
	}

	static void fft(ComplexNumber[] seq, int inv) {
		int n = seq.length;
		int shift = 32 - Integer.numberOfTrailingZeros(n);
		for (int i = 1; i < n; i++) {
			int j = Integer.reverse(i << shift);
			if (i < j) {
				ComplexNumber aux = seq[i];
				seq[i] = seq[j];
				seq[j] = aux;
			}
		}
		for (int len = 2; len <= n; len <<= 1) {
			double angle = 2 * Math.PI / len;
			ComplexNumber wn = new ComplexNumber(Math.cos(angle), Math.sin(angle) * inv);
			for (int i = 0; i < n; i += len) {
				ComplexNumber w = new ComplexNumber(1, 0);
				for (int j = 0; j < len / 2; j++) {
					ComplexNumber u = seq[i + j];
					ComplexNumber v = seq[i + j + len / 2].mul(w);
					seq[i + j] = u.add(v);
					seq[i + j + len / 2] = u.sub(v);
					w = w.mul(wn);
				}
			}
		}
		if (inv == -1)
			for (int i = 0; i < seq.length; i++)
				seq[i] = seq[i].mul(new ComplexNumber((double) 1 / n, 0));
	}

	static class ComplexNumber {
		double real;
		double imag;

		ComplexNumber(double r, double i) {
			real = r;
			imag = i;
		}

		ComplexNumber add(ComplexNumber b) {
			return new ComplexNumber(real + b.real, imag + b.imag);
		}

		ComplexNumber sub(ComplexNumber b) {
			return new ComplexNumber(real - b.real, imag - b.imag);
		}

		ComplexNumber mul(ComplexNumber b) {
			return new ComplexNumber(real * b.real - imag * b.imag, real * b.imag + imag * b.real);
		}

		public String toString() {
			return "(" + real + ", " + imag + "j)";
		}

	}

}
