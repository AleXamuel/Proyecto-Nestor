import java.io.*;
import java.util.*;

public class GolfBot {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		while (true) {
			int n;
			try {
				n = Integer.parseInt(in.readLine());
			} catch (NumberFormatException e) {
				break;
			}
			int[] arr = new int[n];
			int max = 0;
			for (int i = 0; i < n; i++) {
				int val = Integer.parseInt(in.readLine());
				arr[i] = val;
				max = Math.max(max, val);
			}
			max++;
			ComplexNumber[] poli1 = new ComplexNumber[max];
			Arrays.fill(poli1, new ComplexNumber(0, 0));
			poli1[0] = new ComplexNumber(1, 0);
			for (int i : arr) {
				poli1[i] = new ComplexNumber(1, 0);
			}
			int ans = 0;
			long[] poly3 = polyMult(poli1);
			int m = Integer.parseInt(in.readLine());
			for (int i = 0; i < m; i++) {
				int val = Integer.parseInt(in.readLine());
				if (val < poly3.length && poly3[val] > 0)
					ans++;
			}
			System.out.println(ans);

		}

	}

	static long[] polyMult(ComplexNumber[] a) {
		int m = a.length;
		int sz = m + m - 1;
		int szPrima = nextPowerOf2(sz);
		a = Arrays.copyOf(a, szPrima);
		Arrays.fill(a, m, szPrima, new ComplexNumber(0, 0));
		fft(a, 1);
		for (int i = 0; i < a.length; i++)
			a[i] = a[i].mul(a[i]);
		long[] c = new long[sz];
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

		ComplexNumber div(ComplexNumber b) {
			double denominator = b.real * b.real + b.imag * b.imag;
			return new ComplexNumber((real * b.real + imag * b.imag) / denominator,
					(imag * b.real - real * b.imag) / denominator);
		}

		public String toString() {
			return "(" + real + ", " + imag + "j)";
		}

	}

}
