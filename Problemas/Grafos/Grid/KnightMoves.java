//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380
import java.io.*;
import java.util.*;

public class KnighMoves {
	static HashMap<Character, Integer> rows;

	public static void main(String[] args) {
		Input in = new Input(System.in);
		rows = new HashMap<>();
		rows.put('a', 0);
		rows.put('b', 1);
		rows.put('c', 2);
		rows.put('d', 3);
		rows.put('e', 4);
		rows.put('f', 5);
		rows.put('g', 6);
		rows.put('h', 7);
		while (in.hasNext()) {
			String a = in.next();
			String b = in.next();
			char[] s = a.toCharArray();
			char[] t = b.toCharArray();
			int i = rows.get(s[0]);
			int j = s[1] - '0' - 1;
			int k = rows.get(t[0]);
			int l = t[1] - '0' - 1;
			System.out.println("To get from " + a + " to " + b + " takes " + bfs(i, j)[k][l] + " knight moves.");

		}

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
