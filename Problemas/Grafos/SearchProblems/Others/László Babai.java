import java.io.*;
import java.util.*;

public class LászlóBabai {

	public static void main(String[] args) {
		Input in = new Input(System.in);
		int t = in.nextInt();
		for (int cases = 0; cases < t; cases++) {
			ArrayList<Integer>[] adj1 = new ArrayList[3];
			for (int i = 0; i < 3; i++)
				adj1[i] = new ArrayList<>();
			int m1 = in.nextInt();
			for (int i = 0; i < m1; i++) {
				int a = in.nextInt() - 1;
				int b = in.nextInt() - 1;
				adj1[a].add(b);
				adj1[b].add(a);
			}
			ArrayList<Integer>[] adj2 = new ArrayList[3];
			for (int i = 0; i < 3; i++)
				adj2[i] = new ArrayList<>();
			int m2 = in.nextInt();
			for (int i = 0; i < m2; i++) {
				int a = in.nextInt() - 1;
				int b = in.nextInt() - 1;
				adj2[a].add(b);
				adj2[b].add(a);
			}
			if (m1 != m2) {
				System.out.println("no");
				continue;
			}
			int[] g1 = new int[3];
			int[] g2 = new int[3];
			for (int i = 0; i < 3; i++)
				g1[i] = adj1[i].size();

			for (int i = 0; i < 3; i++)
				g2[i] = adj2[i].size();

			Arrays.sort(g1);
			Arrays.sort(g2);
			if (Arrays.equals(g1, g2))
				System.out.println("yes");
			else
				System.out.println("no");

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
