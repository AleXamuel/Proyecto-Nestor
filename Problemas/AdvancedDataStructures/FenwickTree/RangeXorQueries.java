import java.util.*;
import java.io.*;

public class RangeXorQueries {

	public static void main(String[] args) throws Exception {
		Input in = new Input(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		int q = in.nextInt();
		FenwickTree ft = new FenwickTree(n);
		for (int i = 0; i < n; i++)
			ft.update(i, in.nextLong());
		for (int i = 0; i < q; i++)
			out.println(ft.query(in.nextInt() - 1, in.nextInt() - 1));
		out.flush();
		in.close();
	}

	static class FenwickTree {
		long[] t;
		int n;
		int passive = 0;

		FenwickTree(int n) {
			this.n = n;
			t = new long[n];
		}

		void set(int i, int v) {
			long old = query(i, i);
			revUpdate(i, old);
			update(i, v);
		}

		void update(int i, long v) {
			while (i < n) {
				t[i] = op(t[i], v);
				i = goUp(i);
			}
		}

		void revUpdate(int i, long v) {
			while (i < n) {
				t[i] = rev(t[i], v);
				i = goUp(i);
			}
		}

		long query(int l, int r) {
			return rev(query(r), query(l - 1));
		}

		long rev(long a, long b) {
			return a ^ b;
		}

		long query(int r) {
			long res = passive;
			while (r >= 0) {
				res = op(res, t[r]);
				r = goDown(r);
			}
			return res;
		}

		long op(long a, long b) {
			return a ^ b;
		}

		int goUp(int x) {
			return x | (x + 1);
		}

		int goDown(int x) {
			return (x & (x + 1)) - 1;
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
