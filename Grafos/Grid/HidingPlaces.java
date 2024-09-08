import java.io.*;
import java.util.*;

public class HidingPlaces {
	public static void main(String[] args) throws IOException {
		Input in = new Input(System.in);
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		int t = in.nextInt();
		HashMap<Character, Integer> cols = new HashMap<>();
		char[] inv = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
		cols.put('a', 0);
		cols.put('b', 1);
		cols.put('c', 2);
		cols.put('d', 3);
		cols.put('e', 4);
		cols.put('f', 5);
		cols.put('g', 6);
		cols.put('h', 7);
		while (t-- > 0) {
			String a = in.next();
			char[] s = a.toCharArray();
			int i = 7 - (s[1] - '0' - 1);
			int j = cols.get(s[0]);
			int[][] matrix = bfs(i, j);
			int max = -1;
			for (int[] x : matrix)
				for (int y : x)
					max = Math.max(max, y);
			out.write(max + " ");
			for (int x = 0; x < 8; x++)
				for (int y = 0; y < 8; y++)
					if (matrix[x][y] == max)
						out.write(inv[y] + "" + (8 - x) + " ");
			out.write("\n");
		}
		out.flush();

	}

	static int[][] bfs(int sr, int sc) {
		Queue<int[]> Q = new LinkedList<>();
		int[][] d = new int[8][8];
		boolean[][] visited = new boolean[8][8];
		Q.add(new int[] { sr, sc });
		d[sr][sc] = 0;
		visited[sr][sc] = true;
		while (!Q.isEmpty()) {
			int[] e = Q.poll();
			int r = e[0];
			int c = e[1];
			if (r - 2 >= 0 && c - 1 >= 0 && !visited[r - 2][c - 1]) {
				visited[r - 2][c - 1] = true;
				d[r - 2][c - 1] = d[r][c] + 1;
				Q.add(new int[] { r - 2, c - 1 });
			}
			if (r + 2 < 8 && c - 1 >= 0 && !visited[r + 2][c - 1]) {
				visited[r + 2][c - 1] = true;
				d[r + 2][c - 1] = d[r][c] + 1;
				Q.add(new int[] { r + 2, c - 1 });
			}
			if (r - 2 >= 0 && c + 1 < 8 && !visited[r - 2][c + 1]) {
				visited[r - 2][c + 1] = true;
				d[r - 2][c + 1] = d[r][c] + 1;
				Q.add(new int[] { r - 2, c + 1 });
			}
			if (r + 2 < 8 && c + 1 < 8 && !visited[r + 2][c + 1]) {
				visited[r + 2][c + 1] = true;
				d[r + 2][c + 1] = d[r][c] + 1;
				Q.add(new int[] { r + 2, c + 1 });
			}
			if (r + 1 < 8 && c - 2 >= 0 && !visited[r + 1][c - 2]) {
				visited[r + 1][c - 2] = true;
				d[r + 1][c - 2] = d[r][c] + 1;
				Q.add(new int[] { r + 1, c - 2 });
			}
			if (r + 1 < 8 && c + 2 < 8 && !visited[r + 1][c + 2]) {
				visited[r + 1][c + 2] = true;
				d[r + 1][c + 2] = d[r][c] + 1;
				Q.add(new int[] { r + 1, c + 2 });
			}
			if (r - 1 >= 0 && c - 2 >= 0 && !visited[r - 1][c - 2]) {
				visited[r - 1][c - 2] = true;
				d[r - 1][c - 2] = d[r][c] + 1;
				Q.add(new int[] { r - 1, c - 2 });
			}
			if (r - 1 >= 0 && c + 2 < 8 && !visited[r - 1][c + 2]) {
				visited[r - 1][c + 2] = true;
				d[r - 1][c + 2] = d[r][c] + 1;
				Q.add(new int[] { r - 1, c + 2 });
			}
		}
		return d;
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
