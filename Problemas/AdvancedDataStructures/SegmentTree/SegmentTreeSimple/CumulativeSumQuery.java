//https://www.spoj.com/problems/CSUMQ/
import java.util.*;
import java.io.*;

public class CumulativeSumQuery {

	public static void main(String[] args) {
		Input in = new Input(System.in);
		int n = in.nextInt();
		long[] arr = new long[n];
		for (int i = 0; i < n; i++)
			arr[i] = in.nextLong();
		SegmentTree st = new SegmentTree(arr);
		int q = in.nextInt();
		for (int i = 0; i < q; i++) {
			int l = in.nextInt();
			int r = in.nextInt();
		System.out.println(st.getValor(l, r+1));
		}

	}

	static class SegmentTree {
		private long[] valores;
		private int izq[], der[], cotas[][], c;
		private int[] cuentas;
		private int N;
		private long[] valoresIniciales;

		public SegmentTree(long[] valoresIniciales) {
			this.valoresIniciales = valoresIniciales;
			N = valoresIniciales.length;
			int n = N * 2;
			valores = new long[n];
			c = 0;
			cotas = new int[n][2];
			izq = new int[n];
			der = new int[n];
			cuentas = new int[N + 1];
			initTree(0, N);
		}

		private int initTree(int desde, int hasta) {
			int C = c++;
			cotas[C][0] = desde;
			cotas[C][1] = hasta;
			if (hasta - desde > 1) {
				int p = (hasta + desde) / 2;
				izq[C] = initTree(desde, p);
				der[C] = initTree(p, hasta);
				valores[C] = valores[izq[C]] + valores[der[C]];
			} else
				valores[C] = valoresIniciales[desde];
			return C;
		}

		// Acepta 0 indexado y funciona como un array
		public void setValor(int index, long val) {
			int C = 0, i = 0;
			cuentas[C++] = i;
			for (; cotas[i][1] - cotas[i][0] > 1;)
				if (cotas[izq[i]][0] <= index && cotas[izq[i]][1] > index)
					cuentas[C++] = (i = izq[i]);
				else
					cuentas[C++] = (i = der[i]);
			valores[i] = val;
			for (C = C - 2; C >= 0; C--) {
				i = cuentas[C];
				long l = valores[izq[i]], r = valores[der[i]];
				valores[i] = l + r;
			}
		}

		// [desde,hasta)
		// Si desde==hasta se yuquea
		public long getValor(int desde, int hasta) {
			return getValor(0, desde, hasta);
		}

		private long getValor(int i, int desde, int hasta) {
			if (cotas[i][0] == desde && cotas[i][1] == hasta)
				return valores[i];
			if (desde >= cotas[izq[i]][0] && hasta <= cotas[izq[i]][1])
				return getValor(izq[i], desde, hasta);
			if (desde >= cotas[der[i]][0] && hasta <= cotas[der[i]][1])
				return getValor(der[i], desde, hasta);
			return getValor(izq[i], desde, cotas[izq[i]][1]) + getValor(der[i], cotas[der[i]][0], hasta);
		}

		public String toString() {
			String res = "";
			for (int i = 0; i < cotas.length; i++)
				res += Arrays.toString(cotas[i]) + ":" + valores[i] + " ,  ";
			return res;
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
