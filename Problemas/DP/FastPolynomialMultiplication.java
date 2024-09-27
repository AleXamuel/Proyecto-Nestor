//Multiply two polynomials in time O(nlogn) using Fast Fourier TransForm
import java.util.*;
import java.io.*;

public class FFT {

	static int grado;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(in.readLine());
		StringTokenizer st;
		for (int cases = 0; cases < t; cases++) {
			int n1 = Integer.parseInt(in.readLine()) + 1;
			ComplexNumber[] p1 = new ComplexNumber[n1];
			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < n1; i++)
				p1[i] = new ComplexNumber(Double.parseDouble(st.nextToken()), 0);
			int n2 = Integer.parseInt(in.readLine()) + 1;
			ComplexNumber[] p2 = new ComplexNumber[n2];
			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < n2; i++)
				p2[i] = new ComplexNumber(Double.parseDouble(st.nextToken()), 0);
			long[] p3 = polyMult(p1, p2);
			System.out.println(grado - 1);
			p3 = Arrays.copyOfRange(p3, 0, grado);
			System.out.println(String.join(" ", Arrays.stream(p3).mapToObj(x -> String.valueOf(x)).toList()));

		}
	}

	static long[] polyMult(ComplexNumber[] a, ComplexNumber[] b) {
		int m = a.length;
		int n = b.length;
		int sz = m + n - 1;
		grado = sz;
		int szPrima = nextPowerOf2(sz);
		a = Arrays.copyOf(a, szPrima);
		b = Arrays.copyOf(b, szPrima);
		for (int i = m; i < szPrima; i++)
			a[i] = new ComplexNumber(0, 0);
		for (int i = n; i < szPrima; i++)
			b[i] = new ComplexNumber(0, 0);
		ComplexNumber[] fft1 = fft(a, false);
		ComplexNumber[] fft2 = fft(b, false);
		ComplexNumber[] fft3 = new ComplexNumber[szPrima];
		for (int i = 0; i < fft3.length; i++)
			fft3[i] = fft1[i].mul(fft2[i]);
		long[] c = new long[szPrima];
		ComplexNumber[] inv_fft3 = fft(fft3, true);
		for (int i = 0; i < c.length; i++)
			c[i] = Math.round(inv_fft3[i].real);
		return c;

	}

	static int nextPowerOf2(int n) {
		int nextPow2 = 1;
		while (nextPow2 < n)
			nextPow2 <<= 1;
		return nextPow2;
	}

	static ComplexNumber[] fft(ComplexNumber[] seq, boolean inverse) {
		if (seq.length == 1)
			return seq;
		int n = seq.length;
		ComplexNumber[] seq_even = new ComplexNumber[n / 2];
		ComplexNumber[] seq_odd = new ComplexNumber[n / 2];
		for (int i = 0; i < n / 2; i++) {
			seq_even[i] = seq[i * 2];
			seq_odd[i] = seq[i * 2 + 1];
		}
		ComplexNumber[] s1 = fft(seq_even, inverse);
		ComplexNumber[] s2 = fft(seq_odd, inverse);
		ComplexNumber[] fft_ans = new ComplexNumber[n];
		ComplexNumber w = new ComplexNumber(1, 0);
		ComplexNumber wn = null;
		if (inverse)
			wn = new ComplexNumber(Math.cos(2 * Math.PI / n), -Math.sin(2 * Math.PI / n));
		else
			wn = new ComplexNumber(Math.cos(2 * Math.PI / n), Math.sin(2 * Math.PI / n));
		for (int k = 0; k < n / 2; k++) {
			fft_ans[k] = s1[k].add(w.mul(s2[k]));
			fft_ans[k + n / 2] = s1[k].sub(w.mul(s2[k]));
			w = w.mul(wn);
		}
		if (inverse)
			for (int i = 0; i < fft_ans.length; i++)
				fft_ans[i] = fft_ans[i].mul(new ComplexNumber(0.5, 0));
		return fft_ans;

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
